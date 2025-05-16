cmake_minimum_required(VERSION 3.25)
project(TextStreams)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

FetchContent_Declare(
   gtest2html
   URL https://github.com/adarmalik/gtest2html/archive/refs/heads/master.zip
)
FetchContent_MakeAvailable(gtest2html)

enable_testing()
file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE TESTS test/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCES} ${TESTS})
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC src)
target_link_libraries(${PROJECT_NAME} PUBLIC gtest gcov)
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
if(CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Og -g3 -fno-inline -fprofile-arcs -ftest-coverage)
    target_link_options(${PROJECT_NAME} PRIVATE -fprofile-arcs)
endif()
