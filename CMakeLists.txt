cmake_minimum_required(VERSION 3.5)
project("LinuxPlayground"  LANGUAGES CXX)

#cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ..


#Chapter 00 -> origin
add_subdirectory(chapter_00)

#Chapter 01 -> Gtest and Gmock
add_subdirectory(chapter_01)

#Chapter 02 -> Atomic vs lock_guard
add_subdirectory(chapter_02)

#Chapter 03 -> Own implementation of smart template container
add_subdirectory(chapter_03)