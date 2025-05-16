#!/bin/sh -e

rm -fr build
rm -fr doc
rm -fr report
clear
cmake -DCMAKE_BUILD_TYPE=Debug -S . -B build
cmake --build build
mkdir -p report/coverage
mkdir -p report/unittest
lcov --directory . --zerocounters
build/TextStreams --gtest_output=xml:report/unittest/index.xml
xsltproc $(find -name gtest2html.xslt) report/unittest/index.xml > report/unittest/index.html
(
    cd build;
    gcov --branch-counts --demangled-names $(find CMakeFiles/TextStreams.dir/test/*.o | paste -sd ' ');
    lcov --rc lcov_branch_coverage=1 --capture --directory . --output-file total.info;
    lcov --rc lcov_branch_coverage=1 --remove total.info "/usr/*" "$(realpath $(pwd)/../test)/*" "$(pwd)/_deps/googletest-src/googletest/include/gtest/*" --output-file filtered.info;
    genhtml --branch-coverage --demangle-cpp filtered.info --output-directory ../report/coverage;
)
doxygen doxygen.conf
