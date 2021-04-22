cmake_minimum_required(VERSION 3.5)
set(APPNAME "Chapter_01")

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-instr-generate -fcoverage-mapping") # Code coverage for C
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-instr-generate -fcoverage-mapping") #Code coverage for C++

#set(CMAKE_CXX_CLANG_TIDY clang-tidy-7) #enable clang-tidy


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
target_compile_options(${APPNAME} PRIVATE -Wall -Wcast-align -Wconversion -Wctor-dtor-privacy -Werror -Wextra -Wpedantic -Wshadow -Wsign-conversion)  #Enable warning
target_link_libraries(${APPNAME} ${GTest_LIBRARIES} ${Boost_LIBRARIES})

include_directories(src)


#add_subdirectory(src)
add_subdirectory(test)