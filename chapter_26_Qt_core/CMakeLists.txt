#https://doc.qt.io/qt-6/cmake-get-started.html

cmake_minimum_required(VERSION 3.16.0)
set(APPNAME "Chapter_26")
set (CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "~/Qt/6.1.2")

set (SOURCES
    src/main.cpp
    src/TestClass.cpp
)

set(HEADERS
)

set(CMAKE_AUTOMOC ON) #Qt
set(CMAKE_AUTORCC ON) #Qt
set(CMAKE_AUTOUIC ON) #Qt

project(${APPNAME}  LANGUAGES CXX)
add_executable(${APPNAME} ${HEADERS} ${SOURCES} )
target_compile_options(${APPNAME} PRIVATE -Wall -Wcast-align -Wconversion -Wctor-dtor-privacy -Werror -Wextra -Wpedantic -Wshadow -Wsign-conversion)  #Enable warning

include_directories(src)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Widgets REQUIRED)

target_link_libraries(${APPNAME}  Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets)
