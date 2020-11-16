cmake_minimum_required(VERSION 3.5)
project("LinuxPlayground"  LANGUAGES CXX)

#cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ..


#Chapter 00 -> origin
add_subdirectory(chapter_00)

#Chapter 01 -> Gtest and Gmock
#add_subdirectory(chapter_01)

#Chapter 02 -> Atomic vs lock_guard
add_subdirectory(chapter_02)

#Chapter 03 -> Own implementation of smart template container
add_subdirectory(chapter_03)

#Chapter 04 -> CRPT - https://www.fluentcpp.com/2017/05/12/curiously-recurring-template-pattern/
add_subdirectory(chapter_04)

#Chapter 05 -> Boost.Asio -> https://www.boost.org/doc/libs/1_65_0/doc/html/boost_asio/examples/cpp11_examples.html
add_subdirectory(chapter_05/example_1)
add_subdirectory(chapter_05/example_2)
add_subdirectory(chapter_05/example_3)

#Chapter 06 -> Dependency injection using template -> https://bajamircea.github.io/coding/cpp/2015/11/01/dependency-injection-templates.html
add_subdirectory(chapter_06)

#Chapter 07 -> Type traits -> https://www.internalpointers.com/post/quick-primer-type-traits-modern-cpp
add_subdirectory(chapter_07)

