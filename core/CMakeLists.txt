cmake_minimum_required(VERSION 3.22.4)
project(qthni-cashier)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Core    CONFIG REQUIRED)
find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Gui     CONFIG REQUIRED)

set(INCLUDE_FILES
    include/hmainwindow.h
    include/hmaterialpanel.h
    include/hmaterialpanel_p.h
    include/hmaterialpanel_internal.h
    include/hmaterialsmallproduct.h
    include/hmaterialsmallproduct_p.h)
    

set(SOURCE_FILES
    src/hmainwindow.cpp
    src/hmaterialpanel.cpp
    src/hmaterialpanel_internal.cpp
    src/hmaterialsmallproduct.cpp)

add_executable(qthni-cashier
    src/main.cpp
    ${SOURCE_FILES}
    ${INCLUDE_FILES})

target_include_directories(qthni-cashier PUBLIC
    include)

target_link_libraries(qthni-cashier
    Qt5::Core
    Qt5::Widgets
    Qt5::Gui
    hni-lib)
