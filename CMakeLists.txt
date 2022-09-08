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

set(RESOURCE_FILE
    resources/hni_sources.qrc)

set(INCLUDE_FILES
    include/hmaterialflatbutton.h
    include/hmaterialflatbutton_p.h
    include/hmaterialflatbutton_internal.h
    include/hmaterialraisedbutton.h
    include/hmaterialraisedbutton_p.h
    include/hmaterialiconbutton.h
    include/hmaterialiconbutton_p.h
    include/hmaterialtextfield.h
    include/hmaterialtextfield_p.h
    include/hmaterialtextfield_internal.h
    include/hmaterialautocomplete.h
    include/hmaterialautocomplete_p.h
    include/hmaterialautocomplete_internal.h
    include/hmaterialtabs.h
    include/hmaterialtabs_p.h
    include/hmaterialtabs_internal.h
    include/hmaterialavatar.h
    include/hmaterialavatar_p.h
    include/hmaterialbadge.h
    include/hmaterialbadge_p.h
    include/hmaterialsnackbar.h
    include/hmaterialsnackbar_p.h
    include/hmaterialsnackbar_internal.h)
    
set(SOURCE_FILES
    src/hmaterialflatbutton.cpp
    src/hmaterialflatbutton_internal.cpp
    src/hmaterialraisedbutton.cpp
    src/hmaterialiconbutton.cpp
    src/hmaterialtextfield.cpp
    src/hmaterialtextfield_internal.cpp
    src/hmaterialautocomplete.cpp
    src/hmaterialautocomplete_internal.cpp
    src/hmaterialtabs.cpp
    src/hmaterialtabs_internal.cpp
    src/hmaterialavatar.cpp
    src/hmaterialbadge.cpp
    src/hmaterialsnackbar.cpp
    src/hmaterialsnackbar_internal.cpp)

add_library(hni-lib STATIC
    ${INCLUDE_FILES}
    ${SOURCE_FILES}
    ${RESOURCE_FILE})

target_include_directories(hni-lib PUBLIC
    include lib)

target_link_libraries(hni-lib
    Qt5::Core
    Qt5::Widgets
    Qt5::Gui
    hmateriallib)
