cmake_minimum_required(VERSION 3.5)
set(APPNAME "Chapter_03")



set (SOURCES
    src/SmartContainer.hpp
    src/main.cpp
)

set(HEADERS
)

project(${APPNAME}  LANGUAGES CXX)
add_executable(${APPNAME} ${SOURCES} ${HEADERS} )
target_compile_options(${APPNAME} PRIVATE -Wall -Wcast-align -Wconversion -Wctor-dtor-privacy -Wshadow -Wsign-conversion)  #Enable warning

include_directories(src)