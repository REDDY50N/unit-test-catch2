#!/bin/bash

set -euo pipefail

help()
{
cat << EOM
Runs unit tests with ctest.
If no arguments are given, it uses the current directory.

Usage:
  ./test [--debug] [--release] [path]

Options:
  -h, --help    Show this help message.
  --debug       Uses the default debug build path: (repo-root)/build-debug
  --release     Uses the default release build path: (repo-root)/build-release
  [path]        Uses a custom path.
EOM
}

readonly repository_root=$(git rev-parse --show-toplevel)
path_to_build_directory=$(pwd)

while [[ $# > 0 ]]; do
    argument="$1"

    case $argument in
        -h | --help)
            help
            exit 0
        ;;

        --debug)
            path_to_build_directory=$repository_root/cmake-build-debug
            shift
        ;;

        --release)
            path_to_build_directory=$repository_root/cmake-build-release
            shift
        ;;

        *)
            path_to_build_directory=$argument
            break
        ;;
    esac
done

rm -rf $path_to_build_directory/test-results || true
mkdir -p $path_to_build_directory/test-results

cd $path_to_build_directory
ctest -V --timeout 10