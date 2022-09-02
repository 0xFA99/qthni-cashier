set(INCLUDE_FILES
    hmaterialoverlaywidget.h
    hmaterialripple.h
    hmaterialrippleoverlay.h
    hmaterialstatetransition.h
    hmaterialstatetransitionevent.h
    hmaterialstyle.h
    hmaterialstyle_p.h
    hmaterialtheme.h
    hmaterialtheme_p.h)

set(SOURCE_FILES
    hmaterialoverlaywidget.cpp
    hmaterialripple.cpp
    hmaterialrippleoverlay.cpp
    hmaterialstatetransition.cpp
    hmaterialstyle.cpp
    hmaterialtheme.cpp)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Core    CONFIG REQUIRED)
find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Gui     CONFIG REQUIRED)

add_library(hmateriallib SHARED ${SOURCE_FILES} ${INCLUDE_FILES})

target_link_libraries(hmateriallib
    Qt5::Core
    Qt5::Widgets
    Qt5::Gui)
