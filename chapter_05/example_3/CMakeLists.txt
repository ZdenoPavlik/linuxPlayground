cmake_minimum_required(VERSION 3.5)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

#client
set(APPNAME_client "Chapter_05_e3_client")


set (SOURCES
    main.cpp
)

set(HEADERS
)

project(${APPNAME_client}  LANGUAGES CXX)
add_executable(${APPNAME_client} ${HEADERS} ${SOURCES} )

find_package(Boost 1.65.1 REQUIRED COMPONENTS system filesystem)
include_directories(... ${Boost_INCLUDE_DIRS})
link_directories(... ${Boost_LIBRARY_DIRS})
target_link_libraries(${APPNAME_client} ${Boost_LIBRARIES})

include_directories(client)