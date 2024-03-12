cmake_minimum_required(VERSION 3.5)
project("LinuxPlayground"  LANGUAGES CXX)

#cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ..


#Chapter 00 -> origin
add_subdirectory(chapter_00)

#Chapter 01 -> Gtest and Gmock
add_subdirectory(chapter_01_testing)

#Chapter 02 -> Atomic vs lock_guard
add_subdirectory(chapter_02_thread_synchronization)

#Chapter 03 -> Own implementation of smart template container
add_subdirectory(chapter_03_smart_container)

#Chapter 04 -> CRPT - https://www.fluentcpp.com/2017/05/12/curiously-recurring-template-pattern/
add_subdirectory(chapter_04_reversed_inheritance_CRPT)

#Chapter 05 -> Boost.Asio -> https://www.boost.org/doc/libs/1_65_0/doc/html/boost_asio/examples/cpp11_examples.html
add_subdirectory(chapter_05_boost_asio/example_1)
add_subdirectory(chapter_05_boost_asio/example_2)
add_subdirectory(chapter_05_boost_asio/example_3)

#Chapter 06 -> Dependency injection using template -> https://bajamircea.github.io/coding/cpp/2015/11/01/dependency-injection-templates.html
add_subdirectory(chapter_06_dependency_injection)

#Chapter 07 -> Type traits -> https://www.internalpointers.com/post/quick-primer-type-traits-modern-cpp
add_subdirectory(chapter_07_type_traits)

#Chapter 08 -> Templates and SFINAE
add_subdirectory(chapter_08_templates)

#Chapter 09 -> Concepts
add_subdirectory(chapter_09_concepts)

#Chapter 10 -> Coroutines
add_subdirectory(chapter_10_coroutines)

#Chapter 11 -> String_view
add_subdirectory(chapter_11_string_view)

#Chapter 12 -> Modules
add_subdirectory(chapter_12_modules)

#Chapter 13 -> Decltype, Declval
add_subdirectory(chapter_13_decltype_declval)

#Chapter 14 -> Lambdas
add_subdirectory(chapter_14_lambdas)

#Chapter 15 -> Ranges
add_subdirectory(chapter_15_ranges)

#Chapter 16 -> Asserts, std::variant, std::any, std::function
add_subdirectory(chapter_16_asserts_variants_any_functions)

#Chapter 17 -> chrono
add_subdirectory(chapter_17_chrono)

#Chapter 18 -> filesystem
add_subdirectory(chapter_18_filesystem)

#Chapter 19 -> Move semantic for Mima
add_subdirectory(chapter_19_move_semantic)

#Chapter 20 -> Latex
#add_subdirectory(chapter_20_Latex)

#Chapter 21 -> Bitwise operations
add_subdirectory(chapter_21_bitwise_operations)

#Chapter 22 -> Threads, future and promises
add_subdirectory(chapter_22_threads_future)

#Chapter 23 -> Thread exercises, Udemy course
add_subdirectory(chapter_23_threads_udemy)

#Chapter 24 -> C++ community, std::variant demo
add_subdirectory(chapter_24_variantCppCommunityDemo)

#Chapter 25 -> Thread pool
add_subdirectory(chapter_25_thread_pool)

#Chapter 26 -> Qt core
#add_subdirectory(chapter_26_Qt_core)

#Chapter 27 -> Object tree
add_subdirectory(chapter_27_object_tree)






