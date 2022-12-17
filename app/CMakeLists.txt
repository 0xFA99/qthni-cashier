cmake_minimum_required(VERSION 3.24)

project(hni_components VERSION 1.0
        DESCRIPTION "HNI Application"
        LANGUAGES CXX)

add_library(${PROJECT_NAME} SHARED

        pages/analysic/analysicpage.cpp
        pages/analysic/analysicpage.h
        pages/analysic/analysicpage_p.h

        pages/members/memberpage.cpp
        pages/members/memberpage.h
        pages/members/memberpage_p.h

        pages/members/components/memberdialog.cpp
        pages/members/components/memberdialog.h
        pages/members/components/memberdialog_p.h

        pages/notifications/notificationpage.cpp
        pages/notifications/notificationpage.h
        pages/notifications/notificationpage_p.h

        pages/options/optionpage.cpp
        pages/options/optionpage.h
        pages/options/optionpage_p.h

        pages/products/productpage.cpp
        pages/products/productpage.h
        pages/products/productpage_p.h

        pages/products/components/productlist.cpp
        pages/products/components/productlist.h
        pages/products/components/productlist_p.h

        pages/purchase/purchasepage.cpp
        pages/purchase/purchasepage.h
        pages/purchase/purchasepage_p.h

        include/widgets/frametitle.h
        include/widgets/frametitle_p.h
        src/frametitle.cpp

        include/widgets/items/defaultitem_p.h
        include/widgets/items/defaultitem.h
        src/defaultitem.cpp

        include/widgets/items/operateitem_p.h
        include/widgets/items/operateitem.h
        src/operateitem.cpp

        include/widgets/items/extenditem_p.h
        include/widgets/items/extenditem.h
        src/extenditem.cpp
        pages/products/components/productdialog.h pages/products/components/productdialog_p.h pages/products/components/productdialog.cpp pages/members/components/memberlist.cpp pages/members/components/memberlist.h pages/members/components/memberlist_p.h pages/purchase/components/orderlist.cpp pages/purchase/components/orderlist.h pages/purchase/components/orderlist_p.h pages/analysic/components/lastpurchase.cpp pages/analysic/components/lastpurchase.h pages/analysic/components/lastpurchase_p.h include/widgets/items/minimalitem.h include/widgets/items/minimalitem_p.h src/minimalitem.cpp pages/analysic/components/remainingstock.cpp pages/analysic/components/remainingstock.h pages/analysic/components/remainingstock_p.h pages/analysic/components/chartwidget.cpp pages/analysic/components/chartwidget.h pages/analysic/components/chartwidget_p.h src/searchitem.cpp include/widgets/items/searchitem.h include/widgets/items/searchitem_p.h pages/purchase/components/flowlayout.cpp pages/purchase/components/flowlayout.h pages/purchase/components/resultlist.cpp pages/purchase/components/resultlist.h pages/purchase/components/resultlist_p.h pages/purchase/components/searchfield.cpp pages/purchase/components/searchfield.h pages/purchase/components/searchfield_p.h pages/members/member.cpp pages/members/member.h pages/members/member_p.h pages/products/product.cpp pages/products/product.h pages/products/product_p.h pages/purchase/components/orderprice.cpp pages/purchase/components/orderprice.h pages/purchase/components/orderprice_p.h pages/members/membermanager.cpp pages/members/membermanager.h pages/members/membermanager.cpp pages/members/membermanager.h pages/members/membermanager_p.h pages/products/productmanager.cpp pages/products/productmanager.h pages/products/productmanager_p.h pages/members/components/profiledialog.cpp pages/members/components/profiledialog.h pages/members/components/profiledialog_p.h)


target_sources(
        ${PROJECT_NAME} PRIVATE

        # MainWindow
        src/mainwindow.cpp
        include/widgets/mainwindow.h

        # Panel
        src/panel.cpp
        src/panel_internal.cpp
        include/widgets/panel.h
        include/widgets/panel_p.h
        include/widgets/panel_internal.h

        # Resources
        resources/hni_resources.qrc
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

target_include_directories(
        ${PROJECT_NAME} PUBLIC include pages
)

target_link_libraries(${PROJECT_NAME} PRIVATE
        Qt5::Core
        Qt5::Widgets
        Qt5::Gui
        Qt5::Charts
        qtmaterial)

include(GNUInstallDirs)

install(TARGETS ${PROJECT_NAME})

install(
        DIRECTORY ${PROJECT_SOURCE_DIR}/include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)