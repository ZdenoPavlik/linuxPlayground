# author  Zdenko Pavlik

cmake_minimum_required(VERSION 3.5)
set(APPNAME "Chapter_01_unitTests")
project(${APPNAME})

include_directories(..)
include_directories(../src)
include_directories(test)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

enable_testing()

# GTest
find_package(GTest REQUIRED)
include_directories(${GTest_INCLUDE_DIRS})
link_directories(${GTest_LIBRARY_DIRS})

################################
# Unit Tests
################################
# Add test cpp file
set (SOURCES
    ../src/Library/Book/Book.cpp
    UnitTests/SimpleUnitTest.cpp
    UnitTests/FixturesTest.cpp
    MockingTests/MockedBook.cpp
    MockingTests/MockedBookTest.cpp
    DummyTest.cpp
)

set(HEADERS
    stdafx_test.h
)

add_executable(${APPNAME} ${HEADERS} ${SOURCES})
# Link test executable against gtest & gtest_main
target_link_libraries(${APPNAME} gtest pthread -lgtest -lgmock gtest_main )
add_test( ${APPNAME} runUnitTests )


