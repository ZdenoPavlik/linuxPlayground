cmake_minimum_required(VERSION 3.5)
set(APPNAME "Chapter_25")
set (CMAKE_CXX_STANDARD 20)

set (SOURCES
    src/main.cpp
)

set(HEADERS
)

project(${APPNAME}  LANGUAGES CXX)
add_executable(${APPNAME} ${HEADERS} ${SOURCES} )
target_compile_options(${APPNAME} PRIVATE -Wall -Wcast-align -Wconversion -Wctor-dtor-privacy -Werror -Wextra -Wpedantic -Wshadow -Wsign-conversion)  #Enable warning

# Threads
find_package(Threads REQUIRED)
target_link_libraries(${APPNAME} Threads::Threads)
include_directories(${Threads_INCLUDE_DIRS})
link_directories(${Threads_LIBRARY_DIRS})

include_directories(src)