cmake_minimum_required(VERSION 3.24)

project(hni_components VERSION 1.0
        DESCRIPTION "HNI Application"
        LANGUAGES CXX)


set(INTERFACE_FILES
        include/interfaces/IObserver.h
        include/interfaces/ISubject.h
        include/interfaces/IItem.h)

set(LAYOUT_FILES
        src/flowlayout.cpp
        include/layout/flowlayout.h)

set(WIDGETS_FILES
        src/mainwindow.cpp
        include/widgets/mainwindow.h
        src/frametitle.cpp
        include/widgets/frametitle.h
        include/widgets/frametitle_p.h
        src/panel.cpp
        src/panel_internal.cpp
        include/widgets/panel.h
        include/widgets/panel_p.h
        include/widgets/panel_internal.h
        src/defaultitem.cpp
        include/widgets/items/defaultitem.h
        include/widgets/items/defaultitem_p.h
        src/extenditem.cpp
        include/widgets/items/extenditem.h
        include/widgets/items/extenditem_p.h
        src/minimalitem.cpp
        include/widgets/items/minimalitem.h
        include/widgets/items/minimalitem_p.h
        src/OperateItem.cpp
        include/widgets/items/OperateItem.h
        include/widgets/items/OperateItem_p.h
        src/searchitem.cpp
        include/widgets/items/searchitem.h
        include/widgets/items/searchitem_p.h include/widgets/items/finalwidget.h include/widgets/items/finalwidget_p.h src/finalwidget.cpp)

set(ANALYSIS_FILES
        pages/analysic/analysicpage.cpp
        pages/analysic/analysicpage.h
        pages/analysic/analysicpage_p.h
        pages/analysic/components/chartwidget.cpp
        pages/analysic/components/chartwidget.h
        pages/analysic/components/chartwidget_p.h
        pages/analysic/components/lastpurchase.cpp
        pages/analysic/components/lastpurchase.h
        pages/analysic/components/lastpurchase_p.h
        pages/analysic/components/remainingstock.cpp
        pages/analysic/components/remainingstock.h
        pages/analysic/components/remainingstock_p.h)

set(MEMBERS_FILES
        pages/members/MemberObject.cpp
        pages/members/MemberObject.h
        pages/members/MemberObject_p.h
        pages/members/MemberObjectManager.cpp
        pages/members/MemberObjectManager.h
        pages/members/MemberObjectManager_p.h
        pages/members/memberpage.cpp
        pages/members/memberpage.h
        pages/members/memberpage_p.h
        pages/members/components/memberdialog.cpp
        pages/members/components/memberdialog.h
        pages/members/components/memberdialog_p.h
        pages/members/components/memberlist.cpp
        pages/members/components/memberlist.h
        pages/members/components/memberlist_p.h
        pages/members/components/profiledialog.cpp
        pages/members/components/profiledialog.h
        pages/members/components/profiledialog_p.h)

set(NOTIFICATION_FILES
        pages/notifications/notificationpage.cpp
        pages/notifications/notificationpage.h
        pages/notifications/notificationpage_p.h)

set(OPTIONS_FILES
        pages/options/optionpage.cpp
        pages/options/optionpage.h
        pages/options/optionpage_p.h)

set(PRODUCT_FILES
        pages/products/ProductObject.cpp
        pages/products/ProductObject.h
        pages/products/ProductObject_p.h
        pages/products/ProductObjectManager.cpp
        pages/products/ProductObjectManager.h
        pages/products/ProductObjectManager_p.h
        pages/products/productpage.cpp
        pages/products/productpage.h
        pages/products/productpage_p.h
        pages/products/components/productdialog.cpp
        pages/products/components/productdialog.h
        pages/products/components/productdialog_p.h
        pages/products/components/productlist.cpp
        pages/products/components/productlist.h
        pages/products/components/productlist_p.h
        pages/products/product_tag.cpp
        pages/products/product_tag.h
        pages/products/product_tag_p.h)

set(PURCHASE_FILES
        pages/purchase/purchasepage.cpp
        pages/purchase/purchasepage.h
        pages/purchase/purchasepage_p.h
        pages/purchase/components/memberchooser.cpp
        pages/purchase/components/memberchooser.h
        pages/purchase/components/memberchooser_p.h
        pages/purchase/components/orderlist.cpp
        pages/purchase/components/orderlist.h
        pages/purchase/components/orderlist_p.h
        pages/purchase/components/pricewidgets.cpp
        pages/purchase/components/pricewidgets.h
        pages/purchase/components/pricewidgets_p.h
        pages/purchase/components/resultlist.cpp
        pages/purchase/components/resultlist.h
        pages/purchase/components/resultlist_p.h
        pages/purchase/components/resultpurchase.cpp
        pages/purchase/components/resultpurchase.h
        pages/purchase/components/resultpurchase_p.h
        pages/purchase/components/searchfield.cpp
        pages/purchase/components/searchfield.h
        pages/purchase/components/searchfield_p.h
        pages/purchase/components/purchase_order_dialog.cpp
        pages/purchase/components/purchase_order_dialog.h
        pages/purchase/components/choosememberwidget.cpp
        pages/purchase/components/choosememberwidget.h
        pages/purchase/components/choosememberwidget_p.h
        pages/purchase/components/membernamewidget.cpp
        pages/purchase/components/membernamewidget.h
        pages/purchase/components/membernamewidget_p.h)

set(RESOURCE_FILES
        resources/hni_resources.qrc
        resources/database/HNIDatabase.cpp
        resources/database/HNIDatabase.h pages/purchase/components/purchase_order_dialog_p.h)

add_library(${PROJECT_NAME} SHARED
        ${INTERFACE_FILES}
        ${LAYOUT_FILES}
        ${WIDGETS_FILES}
        ${ANALYSIS_FILES}
        ${MEMBERS_FILES}
        ${NOTIFICATION_FILES}
        ${OPTIONS_FILES}
        ${PRODUCT_FILES}
        ${PURCHASE_FILES}
        ${RESOURCE_FILES})

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
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

target_include_directories(
        ${PROJECT_NAME} PUBLIC include pages resources
)

target_link_libraries(${PROJECT_NAME} PRIVATE
        Qt5::Core
        Qt5::Widgets
        Qt5::Gui
        Qt5::Charts
        Qt5::Sql
        qtmaterial)

include(GNUInstallDirs)

install(TARGETS ${PROJECT_NAME})

install(
        DIRECTORY ${PROJECT_SOURCE_DIR}/include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)