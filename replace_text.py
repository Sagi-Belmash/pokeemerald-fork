#!/usr/bin/env python3
"""
replace_printtext_add_false.py

Changes calls like:
  PrintTextOnWindow(text, windowId);
into:
  PrintTextOnWindow(text, windowId, FALSE);

- Handles nested parentheses in argument lists
- Skips string/char literals and // and /* */ comments
- Dry-run by default (prints diffs). Use --apply to actually overwrite files (no backups).
"""

from pathlib import Path
import argparse
import difflib
import re
import sys

TARGET_FNAMES = ["PrintTextOnWindow"]

DEFAULT_EXTS = {".c", ".h", ".cpp", ".cc", ".hpp"}


def find_matching_paren(s, start_idx):
    """ Find the matching closing parenthesis, skipping strings and comments. """
    i = start_idx
    depth = 1
    L = len(s)
    while i < L:
        ch = s[i]
        if ch in ('"', "'"):
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
    idx = 0
    out_parts = []
    last_pos = 0
    replacements = []

    # Build a combined search string for speed
    while True:
        # find the next occurrence of any target function
        next_pos = -1
        next_fn = None
        for fn in TARGET_FNAMES:
            p = text.find(fn + "(", idx)
            if p != -1 and (next_pos == -1 or p < next_pos):
                next_pos = p
                next_fn = fn
        if next_pos == -1:
            break

        pos = next_pos
        fn = next_fn
        start_args = pos + len(fn) + 1
        match_end = find_matching_paren(text, start_args)
        if match_end == -1:
            idx = start_args
            continue

        args = text[start_args:match_end]

        # If it already ends with FALSE, skip
        if re.search(r',\s*FALSE\s*$', args):
            idx = match_end + 1
            continue

        # Otherwise, add , FALSE
        new_args = args.rstrip() + ", FALSE"
        original_call = text[pos:match_end+1]
        new_call = fn + "(" + new_args + ")"

        out_parts.append(text[last_pos:pos])
        out_parts.append(new_call)
        replacements.append((pos, original_call, new_call))

        last_pos = match_end + 1
        idx = last_pos

    if not replacements:
        return text, []

    out_parts.append(text[last_pos:])
    return "".join(out_parts), replacements


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
    sys.exit(main())
