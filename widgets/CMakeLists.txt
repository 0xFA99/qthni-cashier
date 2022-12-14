cmake_minimum_required(VERSION 3.24)

project(qtmaterial VERSION 1.0
        DESCRIPTION "QtMaterial - https://github.com/laserpants/qt-material-widgets"
        LANGUAGES CXX)

find_package(Qt5Core        REQUIRED CONFIG)
find_package(Qt5Widgets     REQUIRED CONFIG)
find_package(Qt5Gui         REQUIRED CONFIG)

add_library(qtmaterial SHARED)
target_sources(qtmaterial PRIVATE
        # Lib Directory
        material/qtmaterial/lib/qtmaterialcheckable.cpp
        material/qtmaterial/lib/qtmaterialcheckable_internal.cpp
        material/qtmaterial/lib/qtmaterialoverlaywidget.cpp
        material/qtmaterial/lib/qtmaterialripple.cpp
        material/qtmaterial/lib/qtmaterialrippleoverlay.cpp
        material/qtmaterial/lib/qtmaterialstatetransition.cpp
        material/qtmaterial/lib/qtmaterialstyle.cpp
        material/qtmaterial/lib/qtmaterialtheme.cpp

        # Component Directory
        material/qtmaterial/components/qtmaterialappbar.cpp
        material/qtmaterial/components/qtmaterialautocomplete.cpp
        material/qtmaterial/components/qtmaterialautocomplete_internal.cpp
        material/qtmaterial/components/qtmaterialavatar.cpp
        material/qtmaterial/components/qtmaterialbadge.cpp
        material/qtmaterial/components/qtmaterialcheckbox.cpp
        material/qtmaterial/components/qtmaterialcircularprogress.cpp
        material/qtmaterial/components/qtmaterialcircularprogress_internal.cpp
        material/qtmaterial/components/qtmaterialdialog.cpp
        material/qtmaterial/components/qtmaterialdialog_internal.cpp
        material/qtmaterial/components/qtmaterialdrawer.cpp
        material/qtmaterial/components/qtmaterialdrawer_internal.cpp
        material/qtmaterial/components/qtmaterialfab.cpp
        material/qtmaterial/components/qtmaterialflatbutton.cpp
        material/qtmaterial/components/qtmaterialflatbutton_internal.cpp
        material/qtmaterial/components/qtmaterialiconbutton.cpp
        material/qtmaterial/components/qtmateriallist.cpp
        material/qtmaterial/components/qtmateriallistitem.cpp
        material/qtmaterial/components/qtmaterialmenu.cpp
        material/qtmaterial/components/qtmaterialmenu_internal.cpp
        material/qtmaterial/components/qtmaterialpaper.cpp
        material/qtmaterial/components/qtmaterialprogress.cpp
        material/qtmaterial/components/qtmaterialprogress_internal.cpp
        material/qtmaterial/components/qtmaterialradiobutton.cpp
        material/qtmaterial/components/qtmaterialraisedbutton.cpp
        material/qtmaterial/components/qtmaterialscrollbar.cpp
        material/qtmaterial/components/qtmaterialscrollbar_internal.cpp
        material/qtmaterial/components/qtmaterialslider.cpp
        material/qtmaterial/components/qtmaterialslider_internal.cpp
        material/qtmaterial/components/qtmaterialsnackbar.cpp
        material/qtmaterial/components/qtmaterialsnackbar_internal.cpp
        material/qtmaterial/components/qtmaterialtable.cpp
        material/qtmaterial/components/qtmaterialtabs.cpp
        material/qtmaterial/components/qtmaterialtabs_internal.cpp
        material/qtmaterial/components/qtmaterialtextfield.cpp
        material/qtmaterial/components/qtmaterialtextfield_internal.cpp
        material/qtmaterial/components/qtmaterialtoggle.cpp
        material/qtmaterial/components/qtmaterialtoggle_internal.cpp

        # Resources Directory
        material/qtmaterial/resources/resources.qrc
        )

target_compile_features(qtmaterial PUBLIC cxx_std_17)

target_include_directories(qtmaterial PUBLIC material)

target_link_libraries(qtmaterial
        Qt5::Core
        Qt5::Widgets
        Qt5::Gui)