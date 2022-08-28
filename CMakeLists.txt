cmake_minimum_required(VERSION 3.22.4)
project(hnilib)

option(BUILD_EXE "Executing building requried" Off)

if (${BUILD_EXE})
    add_subdirectory(core)
endif()

add_subdirectory(lib)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Core    CONFIG REQUIRED)
find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Gui     CONFIG REQUIRED)

set(INCLUDE_FILES
    include/hmaterialflatbutton.h
    include/hmaterialflatbutton_p.h
    include/hmaterialflatbutton_internal.h)

set(SOURCE_FILES
    src/hmaterialflatbutton.cpp
    src/hmaterialflatbutton_internal.cpp)

add_library(hni-lib STATIC
    ${INCLUDE_FILES}
    ${SOURCE_FILES})

target_include_directories(hni-lib PUBLIC
    include lib)

target_link_libraries(hni-lib
    Qt5::Core
    Qt5::Widgets
    Qt5::Gui
    hmateriallib)