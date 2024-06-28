cmake_minimum_required(VERSION 3.18)
project(TextStreams)

if(POLICY CMP0135)
    cmake_policy(SET CMP0135 NEW)
    set(CMAKE_POLICY_DEFAULT_CMP0135 NEW)
endif()

file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}
    src/main.cpp
    lib/zlib-1.3.1/adler32.c
    lib/zlib-1.3.1/crc32.c
    lib/zlib-1.3.1/zutil.c
    lib/zlib-1.3.1/inftrees.c
    lib/zlib-1.3.1/inffast.c
    lib/zlib-1.3.1/inflate.c)
add_executable(${PROJECT_NAME} ${SOURCES})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
target_include_directories(${PROJECT_NAME} PUBLIC src PUBLIC lib/zlib-1.3.1)
