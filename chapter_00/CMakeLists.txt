cmake_minimum_required(VERSION 3.5)
set(APPNAME "Chapter_00")


set (SOURCES
    src/main.cpp
)

set(HEADERS
)

project(${APPNAME}  LANGUAGES CXX)
add_executable(${APPNAME} ${HEADERS} ${SOURCES} )
target_compile_options(${APPNAME} PRIVATE -Wall -Wcast-align -Wconversion -Wctor-dtor-privacy -Werror -Wextra -Wpedantic -Wshadow -Wsign-conversion)  #Enable warning

install (TARGETS ${APPNAME} RUNTIME DESTINATION bin)
include_directories(src)