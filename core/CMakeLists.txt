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
    include/hthemecontrol.h
    include/hmaterialframe.h
    include/hmaterialframe_p.h
    include/hmaterialbutton.h
    include/hmaterialbutton_p.h
    include/hmateriallabel.h
    include/hmateriallabel_p.h)
    

set(SOURCE_FILES
    src/hmainwindow.cpp
    src/hthemecontrol.cpp
    src/hmaterialframe.cpp
    src/hmaterialbutton.cpp
    src/hmateriallabel.cpp)

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
