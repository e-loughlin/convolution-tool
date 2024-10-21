# Author: Evan Loughlin
# Date: 2019/10/19
#
# Script for building current directory, and running tests.
# Use option "--notb" or "--notests" to not run tests.

import argparse
import os
from pathlib import Path

import git


def stringToBool(v):
    if isinstance(v, bool):
        return v
    if v.lower() in ("yes", "true", "t", "y", "1"):
        return True
    elif v.lower() in ("no", "false", "f", "n", "0"):
        return False
    else:
        raise argparse.ArgumentTypeError("Boolean value expected.")


argumentParser = argparse.ArgumentParser(description="Build settings.")
argumentParser.add_argument(
    "-notests",
    "--notests",
    "-notb",
    "--notb",
    dest="notests",
    type=stringToBool,
    nargs="?",
    const=True,
    default=False,
    help="Disables building tests.",
)
argumentParser.add_argument(
    "-ca",
    "--cleanall",
    dest="clean_all",
    type=stringToBool,
    nargs="?",
    const=True,
    default=False,
    help="Cleans build directory.",
)


def run_tests():
    # Get same directory as current, but within /build
    cwd = os.getcwd()
    buildCwd = cwd.replace("/src", "/build/release/src")

    # Recursively search for and run test executables
    for filepath in Path(buildCwd).glob("**/*"):
        filename = os.path.basename(filepath)
        if "RunTests_" in filename and "." not in filename:
            os.system(filepath)


def delete_tests():
    # Get same directory as current, but within /build
    cwd = os.getcwd()
    buildCwd = cwd.replace("/src", "/build/release/src")

    # Recursively search for and run test executables
    for filepath in Path(buildCwd).glob("**/*"):
        filename = os.path.basename(filepath)
        if "RunTests_" in filename and "." not in filename:
            os.remove(filepath)


def build_dir_exists():
    return os.path.isdir(get_build_dir())


def make_build_dir():
    os.system("cd {0} && mkdir build && cd {1}".format(get_git_root(), os.getcwd()))


def run_cmake_at_root():
    cwd = os.getcwd()
    os.system("cd {0} && cmake ../ && cd {1}".format(get_build_dir(), cwd))


def run_make_at_root():
    cwd = os.getcwd()
    os.system("cd {0} && make && cd {1}".format(get_build_dir(), cwd))


def clean_rebuild():
    os.system("cd {0} && rm -rf * && cd {1}".format(get_build_dir(), os.getcwd()))
    run_cmake_at_root()
    run_make_at_root()


def get_git_root():
    git_repo = git.Repo(os.getcwd(), search_parent_directories=True)
    git_root = git_repo.git.rev_parse("--show-toplevel")
    return git_root


def get_src_dir():
    return get_git_root() + "/src"


def get_build_dir():
    return get_git_root() + "/build"


def build_from_current_dir():
    # Get same directory as current, but within /build (#TODO: Make this less hacky)
    cwd = os.getcwd()
    os.system("touch ./CMakeLists.txt")
    buildCwd = cwd.replace("/src", "/build/release/src")

    os.system("cd {0} && make -b && cd {1}".format(buildCwd, cwd))


def get_user_permission(warningMessage):
    print("Warning:\n\t{0}\n\nContinue? (y/n)".format(warningMessage))
    return stringToBool(input())


def cwd_in_src():
    return ("build/src" not in os.getcwd()) and ("/src" in os.getcwd())


def main():
    # Parse arguments
    args = argumentParser.parse_args()

    if not cwd_in_src():
        print("Build script can only be run within source directory (source).")
        exit()

    if not (build_dir_exists()):
        get_user_permission("No /build directory detected. Initiate full build?")
        make_build_dir()
        clean_rebuild()
        run_tests()
        exit()

    if args.clean_all:
        if get_user_permission(
            "Clean *entire* /build directory? (This deletes the /build directory)"
        ):
            clean_rebuild()
            run_tests()
        exit()

    # Delete previously built tests
    delete_tests()

    # Build recursively
    build_from_current_dir()

    # Run all tests
    if not args.notests:
        run_tests()


if __name__ == "__main__":
    main()
