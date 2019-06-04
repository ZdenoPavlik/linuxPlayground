# Main cmake configuration and build script for the Intercom subproject
# author  Zdenko Pavlik
#
# Copyright (c) 2017, 2018, GS Elektromedizinische Geraete G. Stemple GmbH.
# All rights reserved.

cmake_minimum_required(VERSION 3.5)
set(APPNAME "Playground")

set (SOURCES
    src/main.cpp
    src/Library/Bookshelf.cpp
    src/Library/BookFactory.cpp
    src/Library/Book/Book.cpp
)

set(HEADERS
    src/Library/Bookshelf.hpp
    src/Library/BookFactory.hpp
    src/Library/Book/BookInterface.hpp
    src/Library/Book/Book.hpp
)

project(${APPNAME}  LANGUAGES CXX)
add_executable(${APPNAME} ${HEADERS} ${SOURCES} )

include_directories(src)

# Threads
find_package(Threads REQUIRED)
include_directories(${Threads_INCLUDE_DIRS})
link_directories(${Threads_LIBRARY_DIRS})

# GTest
find_package(GTest REQUIRED)
include_directories(${GTest_INCLUDE_DIRS})
link_directories(${GTest_LIBRARY_DIRS})

# Boost
find_package(Boost COMPONENTS system python filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

#add_subdirectory(src)
add_subdirectory(test)
