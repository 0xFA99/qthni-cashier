cmake_minimum_required(VERSION 3.22.4)
project(qthni-cashier)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Core    CONFIG REQUIRED)
find_package(Qt5Widget  CONFIG REQUIRED)
find_package(Qt5Gui     CONFIG REQUIRED)

add_executable(qthni-cashier
    src/main.cpp
    src/HMainWindow.cpp
    include/HMainWindow.h)

target_include_directories(qthni-cashier PUBLIC
    include)

target_link_libraries(qthni-cashier
    Qt5::Core
    Qt5::Widgets
    Qt5::Gui
    hni-lib)
