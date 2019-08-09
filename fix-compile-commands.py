#!/usr/bin/env python3
from os import walk
from os.path import isfile, isdir, abspath, samefile
import pathlib
import json

def get_files_recurse(d):
    # input : directory
    l = [x for x in pathlib.Path(d).glob('**/*.cpp')]
    l.extend([x for x in pathlib.Path(d).glob('**/*.h')])
    return l

def is_present(file_path, cmds, debug):
    for o in cmds:
        if samefile(o["file"], file_path):
            if debug:
                print("Found same file:", o["file"], file_path)
            return True
    return False

def ensure_all_present(files, debug):
    with open("compile_commands.json", 'r') as file:
        cmds = json.load(file)
    not_in_cmds = []
    for f in files:
        file_path = abspath(f)
        if not is_present(file_path, cmds, debug):
            not_in_cmds.append(file_path)
    default = cmds[0]
    for c in not_in_cmds:
        d_copy = dict(default)
        d_copy["file"] = abspath(c)
        cmds.append(d_copy)
    with open("compile_commands.json", 'w') as file:
        json.dump(cmds, file, indent=2)

if __name__ == '__main__':
    import sys
    args = sys.argv[1:]
    debug = False
    if '--debug' in args:
        args.remove('--debug')
        debug = True
    files = []
    for d in args:
        l = get_files_recurse(d)
        files.extend(l if l is not None else [])
        if debug:
            print('For directory:', d, '\n' + str(files))
    ensure_all_present(files, debug) 
