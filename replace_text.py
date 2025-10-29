#!/usr/bin/env python3
"""
replace_withrtl_false_to_true.py

Replace calls like:
  AddTextPrinterParameterizedWithRTL(..., FALSE)
  AddTextPrinterParameterized3WithRTL(..., FALSE)
  AddTextPrinterParameterized4WithRTL(..., FALSE)
  AddTextPrinterParameterized5WithRTL(..., FALSE)

with the same calls but ending in TRUE:
  ..., TRUE)

- Handles nested parentheses in argument lists
- Skips string/char literals and // and /* */ comments while scanning for matching ')'
- Dry-run by default (prints diffs). Use --apply to actually overwrite files (no backups).
- Scans .c/.h/.cpp/.cc/.hpp by default; supply --ext to change.
"""

from pathlib import Path
import argparse
import difflib
import re
import sys

TARGET_FNAMES = [
    "AddTextPrinterParameterizedWithRTL",
    "AddTextPrinterParameterized3WithRTL",
    "AddTextPrinterParameterized4WithRTL",
    "AddTextPrinterParameterized5WithRTL",
]

DEFAULT_EXTS = {".c", ".h", ".cpp", ".cc", ".hpp"}

def find_matching_paren(s, start_idx):
    """
    Given s[start_idx-1] == '(' (start_idx is index after '('),
    find index of matching ')' and return it. Skips strings and comments.
    Returns -1 on failure.
    """
    i = start_idx
    depth = 1
    L = len(s)
    while i < L:
        ch = s[i]
        # Skip string/char literal
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
        # Skip line comment
        if s[i:i+2] == "//":
            i += 2
            while i < L and s[i] != "\n":
                i += 1
            continue
        # Skip block comment
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
    """
    Return (new_text, replacements_list). replacements_list contains tuples:
    (fn_name, pos, match_end, original_call, new_call)
    """
    idx = 0
    L = len(text)
    out_parts = []
    last_pos = 0
    replacements = []

    while True:
        # find next occurrence of any target function name
        nearest_pos = -1
        nearest_name = None
        for name in TARGET_FNAMES:
            p = text.find(name + "(", idx)
            if p != -1 and (nearest_pos == -1 or p < nearest_pos):
                nearest_pos = p
                nearest_name = name
        if nearest_pos == -1:
            break

        pos = nearest_pos
        name = nearest_name
        start_args = pos + len(name) + 1  # index after '('

        match_end = find_matching_paren(text, start_args)
        if match_end == -1:
            # unmatched, skip this occurrence
            idx = pos + len(name) + 1
            continue

        args = text[start_args:match_end]  # between '(' and ')'

        # Check if arguments end with ", FALSE" (allow whitespace)
        if re.search(r',\s*FALSE\s*$', args):
            # Build new args replacing the trailing FALSE with TRUE
            new_args = re.sub(r',\s*FALSE\s*$', ', TRUE', args)
            original_call = text[pos:match_end+1]
            new_call = name + "(" + new_args + ")"

            # Append unchanged region and new_call
            out_parts.append(text[last_pos:pos])
            out_parts.append(new_call)
            replacements.append((name, pos, match_end, original_call, new_call))

            last_pos = match_end + 1
            idx = last_pos
        else:
            # no trailing FALSE; skip this occurrence but continue search after it
            idx = match_end + 1

    if not replacements:
        return text, []

    out_parts.append(text[last_pos:])
    new_text = "".join(out_parts)
    return new_text, replacements

def process_file(path: Path, apply: bool):
    text = path.read_text(encoding="utf-8")
    new_text, repls = process_text(text)
    if not repls:
        return False, None
    if apply:
        path.write_text(new_text, encoding="utf-8")
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
    parser = argparse.ArgumentParser()
    parser.add_argument("path", nargs="?", default=".", help="root path to process")
    parser.add_argument("--apply", action="store_true", help="apply changes in-place (no backups)")
    parser.add_argument("--ext", nargs="*", default=list(DEFAULT_EXTS), help="file extensions to process (include the dot)")
    args = parser.parse_args()

    root = Path(args.path).resolve()
    exts = set(e if e.startswith(".") else "." + e for e in args.ext)

    print(f"{'APPLY' if args.apply else 'DRY-RUN'} mode. Scanning {root} for extensions: {sorted(exts)}")
    modified, diffs = walk_and_process(root, exts, args.apply)

    if not modified:
        print("No matches requiring change found.")
        return 0

    print(f"Files changed: {len(modified)}")
    for p in modified:
        print(" -", p)
    print("\nDiffs:")
    for p, diff in diffs.items():
        print(f"\n----- {p} -----")
        for line in diff:
            print(line)
    if not args.apply:
        print("\nDry run complete. Re-run with --apply to actually write changes (no backups).")
    else:
        print("\nApplied changes in-place (no backups).")
    return 0

if __name__ == "__main__":
    import argparse
    sys.exit(main())
