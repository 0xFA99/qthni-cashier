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
    include/hpanel.h
    include/hpanel_p.h
    include/hpanel_internal.h
    include/hproductnormalview.h
    include/hproductnormalview_p.h
    include/hproductsmallview.h
    include/hproductsmallview_p.h
    include/horderlist.h
    include/horderlist_p.h
    include/hproductdetail.h
    include/hproductdetail_p.h
    include/horderprice.h
    include/horderprice_p.h
    include/hpurchasepage.h
    include/hpurchasepage_p.h
    include/hproductchoose.h
    include/hproductchoose_p.h
    include/hanalysicpage.h
    include/hanalysicpage_p.h
    include/hconstructorpage.h
    include/hoptionpage.h
    include/hoptionpage_p.h
    include/hproductpage.h
    include/hproductpage_p.h
    include/hnotificationpage.h
    include/hnotificationpage_p.h
    include/hproductresult.h
    include/hproductresult_p.h

    include/hmember.h
    include/hmember_p.h
    include/hmemberpage.h
    include/hmemberpage_p.h
    include/hmemberlist.h
    include/hmemberlist_p.h
    include/hmemberitem.h
    include/hmemberitem_p.h
    include/hmemberview.h
    include/hmemberview_p.h)

set(SOURCE_FILES
    src/hmainwindow.cpp
    src/hpanel.cpp
    src/hpanel_internal.cpp
    src/hproductnormalview.cpp
    src/hproductsmallview.cpp
    src/horderlist.cpp
    src/hproductdetail.cpp
    src/horderprice.cpp
    src/hpurchasepage.cpp
    src/hproductchoose.cpp
    src/hanalysicpage.cpp
    src/hconstructorpage.cpp
    src/hoptionpage.cpp
    src/hproductpage.cpp
    src/hnotificationpage.cpp
    src/hproductresult.cpp

    src/hmember.cpp
    src/hmemberpage.cpp
    src/hmemberlist.cpp
    src/hmemberitem.cpp
    src/hmemberview.cpp)

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
