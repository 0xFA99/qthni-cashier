#ifndef QTHNI_MAINWINDOW_H
#define QTHNI_MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

#include "widgets/panel.h"

// include All Pages
#include "analysic/analysicpage.h"
#include "members/memberpage.h"
#include "notifications/notificationpage.h"
#include "options/optionpage.h"
#include "products/productpage.h"
#include "purchase/purchasepage.h"

#include "products/ProductObjectManager.h"
#include "members/MemberObjectManager.h"

class QHBoxLayout;
class MainWindow : public QMainWindow {

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QHBoxLayout         *m_layout;
    QWidget             *m_centralWidget;
    QStackedWidget      *m_stackedWidget;
    Panel               *m_panel;

    // Pages
    AnalysicPage        *m_analysicPage;
    MemberPage          *m_memberPage;
    NotificationPage    *m_notificationPage;
    OptionPage          *m_optionPage;
    ProductPage         *m_productPage;
    PurchasePage        *m_purchasePage;

    ProductObjectManager    *m_productObjectManager;
    MemberObjectManager     *m_memberObjectManager;
};

#endif //QTHNI_MAINWINDOW_H
