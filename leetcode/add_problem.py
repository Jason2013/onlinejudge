# coding=utf-8

import os
import sys
import subprocess

def help(ScriptName):
    print("Usage: {SCRIPT_NAME} ProblemNo".format(SCRIPT_NAME=ScriptName))

def ProblemNo(s):
    return "{:04}".format(int(s))

def CopyFileWithReplace(SrcFile, DestFile, items):
    with open(SrcFile) as f:
        src = f.read()

    if items:
        # print(items)
        for (key, val) in items.items():
            src = src.replace("{%s}" % key, val)

    DestDirName = os.path.dirname(DestFile)
    if not os.path.isdir(DestDirName):
        os.makedirs(DestDirName)

    with open(DestFile, "w") as f:
        f.write(src)


def GetSrcFiles():
    SrcFiles = [
        "templates/cpp/CMakeLists.txt",
        "templates/cpp/main.cpp",
        "templates/cpp/build/build.bat",
        "templates/python3/main.py",
    ]

    return SrcFiles


def GetDestFiles(PROBLEM_NO):
    return [f.replace("templates", PROBLEM_NO) for f in GetSrcFiles()]


def CopyCppFiles(items = None):

    PROBLEM_NO = items["PROBLEM_NO"]

    SrcFiles = GetSrcFiles()
    DestFiles = GetDestFiles(PROBLEM_NO)

    for SrcFile, DestFile in zip(SrcFiles, DestFiles):
        CopyFileWithReplace(SrcFile, DestFile, items)


def AddDestFilesToGit(items):

    PROBLEM_NO = items["PROBLEM_NO"]
    DestFiles = GetDestFiles(PROBLEM_NO)

    for f in DestFiles:
        subprocess.call(["git", "add", "-f", f])

    subprocess.call(["git", "commit", "-m", '"Add problem [%s]."' % PROBLEM_NO])

if __name__ == "__main__":
    if len(sys.argv) < 2:
        help(sys.argv[0])
        exit(-1)

    items = {}
    # print(sys.argv[1])
    # print(type(sys.argv[1]))
    items["PROBLEM_NO"] = ProblemNo(sys.argv[1])
    CopyCppFiles(items)
    AddDestFilesToGit(items)
