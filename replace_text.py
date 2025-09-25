#!/usr/bin/env python3
"""
replace_addtext_nobak.py

Replace:
    AddTextPrinterParameterized(...)
with:
    AddTextPrinterParameterizedWithRTL(..., FALSE)

Behavior:
- Handles nested parentheses in argument lists
- Skips string literals and C-style (//, /* */) comments
- By default: dry-run (prints diffs)
- With --apply: modifies files in-place WITHOUT creating backups
- Scans files by extension (default: .c .h .cpp .cc .hpp)
"""

import argparse
import difflib
from pathlib import Path
import sys

TARGET_NAME = "AddTextPrinterParameterized("
NEW_NAME = "AddTextPrinterParameterizedWithRTL("
INSERT_ARG = ", FALSE"

DEFAULT_EXTS = {".c", ".h", ".cpp", ".cc", ".hpp"}

def find_matching_paren(s, start_idx):
    """Find index of matching ')' for '(' at start_idx-1. Skips strings and comments."""
    i = start_idx
    depth = 1
    L = len(s)
    while i < L:
        ch = s[i]
        if ch == '"' or ch == "'":
            quote = ch
            i += 1
            while i < L:
                if s[i] == "\\":
                    i += 2
                elif s[i] == quote:
                    i += 1
                    break
                else:
                    i += 1
            continue
        if s[i:i+2] == "//":
            i += 2
            while i < L and s[i] != "\n":
                i += 1
            continue
        if s[i:i+2] == "/*":
            i += 2
            while i < L and s[i:i+2] != "*/":
                i += 1
            i += 2 if i < L else 0
            continue
        if s[i] == '(':
            depth += 1
        elif s[i] == ')':
            depth -= 1
            if depth == 0:
                return i
        i += 1
    return -1

def process_text(text):
    """Return (new_text, replacements_list). replacements_list is empty if nothing changed."""
    idx = 0
    L = len(text)
    out = []
    last_pos = 0
    replacements = []

    while True:
        pos = text.find(TARGET_NAME, idx)
        if pos == -1:
            break
        # simple word-boundary check: avoid matching identifiers that include this as suffix
        if pos > 0 and (text[pos-1].isalnum() or text[pos-1] == '_'):
            idx = pos + len(TARGET_NAME)
            continue
        start_args = pos + len(TARGET_NAME)
        match_end = find_matching_paren(text, start_args)
        if match_end == -1:
            # unmatched parentheses; skip
            idx = pos + len(TARGET_NAME)
            continue
        args = text[start_args:match_end]
        new_call = NEW_NAME + args + INSERT_ARG + ")"
        out.append(text[last_pos:pos])
        out.append(new_call)
        replacements.append((pos, match_end, new_call))
        last_pos = match_end + 1
        idx = last_pos

    if not replacements:
        return text, []
    out.append(text[last_pos:])
    return "".join(out), replacements

def process_file(path: Path, apply: bool):
    text = path.read_text(encoding="utf-8")
    new_text, replacements = process_text(text)
    if not replacements:
        return False, None
    if apply:
        # overwrite in-place WITHOUT backups
        path.write_text(new_text, encoding="utf-8")
    # produce unified diff for reporting
    orig_lines = text.splitlines(keepends=False)
    new_lines = new_text.splitlines(keepends=False)
    diff = list(difflib.unified_diff(orig_lines, new_lines, fromfile=str(path) + ".orig", tofile=str(path), lineterm=""))
    return True, diff

def walk_and_process(root: Path, exts, apply: bool):
    modified = []
    diffs = {}
    for p in root.rglob("*"):
        if p.is_file() and p.suffix.lower() in exts:
            ok, diff = process_file(p, apply)
            if ok:
                modified.append(p)
                diffs[p] = diff
    return modified, diffs

def main():
    parser = argparse.ArgumentParser(description="Replace AddTextPrinterParameterized(...) -> AddTextPrinterParameterizedWithRTL(..., FALSE) (no backups)")
    parser.add_argument("path", nargs="?", default=".", help="root path to process")
    parser.add_argument("--apply", action="store_true", help="apply changes in-place (no backups). Without this it's a dry-run.")
    parser.add_argument("--ext", nargs="*", default=list(DEFAULT_EXTS), help="file extensions to process (include the dot), e.g. --ext .c .h")
    args = parser.parse_args()

    root = Path(args.path).resolve()
    exts = set(e if e.startswith(".") else "." + e for e in args.ext)

    print(f"{'APPLY' if args.apply else 'DRY-RUN'} mode. Scanning {root} for extensions: {sorted(exts)}")
    modified, diffs = walk_and_process(root, exts, args.apply)

    if not modified:
        print("No occurrences found.")
        return 0

    print(f"Files modified: {len(modified)}")
    for p in modified:
        print(" -", p)
    print("\nDiffs:")
    for p, diff in diffs.items():
        print(f"\n----- {p} -----")
        if diff:
            for line in diff:
                print(line)
        else:
            print("(no textual diff available)")

    if not args.apply:
        print("\nDry run complete. Re-run with --apply to actually overwrite files (no backups will be made).")
    else:
        print("\nApplied changes in-place (no backups created).")

    return 0

if __name__ == "__main__":
    sys.exit(main())
