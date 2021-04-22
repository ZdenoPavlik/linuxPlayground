cmake_minimum_required(VERSION 3.5)
set(APPNAME "Chapter_02")

#Smart template container

set (SOURCES
    src/main.cpp
)

set(HEADERS
)

project(${APPNAME}  LANGUAGES CXX)
add_executable(${APPNAME} ${HEADERS} ${SOURCES} )
target_compile_options(${APPNAME} PRIVATE -Wall -Wcast-align -Wconversion -Wctor-dtor-privacy -Werror -Wextra -Wpedantic -Wshadow -Wsign-conversion)  #Enable warning

#install (TARGETS ${APPNAME} RUNTIME DESTINATION bin)
include_directories(src)

# Threads
find_package(Threads REQUIRED)
target_link_libraries(${APPNAME} Threads::Threads)
include_directories(${Threads_INCLUDE_DIRS})
link_directories(${Threads_LIBRARY_DIRS})

# Boost
#SET(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS log REQUIRED)
target_link_libraries(${APPNAME} Boost::log)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})