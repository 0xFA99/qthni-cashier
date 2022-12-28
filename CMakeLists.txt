cmake_minimum_required(VERSION 3.24)

project(QTHNI VERSION 1.0
        DESCRIPTION "QTHNI Applicaiton for Help HNI store in Karanganyar to manage their product"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Core      REQUIRED CONFIG)
find_package(Qt5Widgets   REQUIRED CONFIG)
find_package(Qt5Gui       REQUIRED CONFIG)
find_package(Qt5Charts    REQUIRED CONFIG)
find_package(Qt5Sql       REQUIRED CONFIG)

# Option to exclude application from build
set(QTHNI_BUILD_APPLICATION TRUE CACHE BOOL "Executing building required. Default: True")

# Hide option from GUI by default
mark_as_advanced(QTHNI_BUILD_APPLICATION)

# MSVC requires these two flags to be set in order to link executable against
# shared library.
if(CMAKE_SYSTEM_NAME STREQUAL "Window")
    message(VERBOSE "Windows environment detected, overriding default symbol visibility to `visible` instead of `hiddend`")
endif()

add_subdirectory(widgets)

add_subdirectory(core)
add_subdirectory(app)
if(QTHNI_BUILD_APPLICATION)
endif()