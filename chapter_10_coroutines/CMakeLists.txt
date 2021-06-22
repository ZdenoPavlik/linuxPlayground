cmake_minimum_required(VERSION 3.5)
set(APPNAME "Chapter_10")
set (CMAKE_CXX_STANDARD 20)
set(CMAKE_C_COMPILER /usr/bin/gcc-11 CACHE PATH "")
set(CMAKE_CXX_COMPILER /usr/bin/g++-11 CACHE PATH "")


set (SOURCES
    src/main.cpp
)

set(HEADERS
)

project(${APPNAME}  LANGUAGES CXX)
add_executable(${APPNAME} ${HEADERS} ${SOURCES} )
target_compile_options(${APPNAME} PRIVATE -fcoroutines -Wall -Wcast-align -Wconversion -Wctor-dtor-privacy -Werror -Wextra -Wpedantic -Wshadow -Wsign-conversion)  #Enable warning

include_directories(src)