cmake_minimum_required(VERSION 3.5)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")


# Threads
find_package(Threads REQUIRED)
include_directories(${Threads_INCLUDE_DIRS})
link_directories(${Threads_LIBRARY_DIRS})

# Boost
find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

#client
set(APPNAME_client "Chapter_05_e1_client")

set (SOURCES
    client/main.cpp
)

set(HEADERS
)


project(${APPNAME_client}  LANGUAGES CXX)
add_executable(${APPNAME_client} ${HEADERS} ${SOURCES} )
target_link_libraries(${APPNAME_client} ${Boost_LIBRARIES})

include_directories(client)

#server
set(APPNAME_server "Chapter_05_e1_server")

set (SOURCES
    server/main.cpp
)

set(HEADERS
)

project(${APPNAME_server}  LANGUAGES CXX)
add_executable(${APPNAME_server} ${HEADERS} ${SOURCES} )
target_link_libraries(${APPNAME_server} ${Boost_LIBRARIES})

include_directories(server)