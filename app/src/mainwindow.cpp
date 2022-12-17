#include "widgets/mainwindow.h"

#include <QHBoxLayout>
#include <QDirIterator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_centralWidget     = new QWidget(this);
    m_layout            = new QHBoxLayout(m_centralWidget);
    m_stackedWidget     = new QStackedWidget(m_centralWidget);
    m_panel             = new Panel(m_centralWidget);

    m_analysicPage      = new AnalysicPage(m_centralWidget);
    m_purchasePage      = new PurchasePage(m_centralWidget);
    m_productPage       = new ProductPage(m_centralWidget);
    m_memberPage        = new MemberPage(m_centralWidget);
    m_notificationPage  = new NotificationPage(m_centralWidget);
    m_optionPage        = new OptionPage(m_centralWidget);

    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->setSpacing(0);

    setCentralWidget(m_centralWidget);

    m_panel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
    m_panel->setInkColor(QRgb(0x657ef8));
    m_panel->addTab("\uE631");
    m_panel->addTab("\uE62B");
    m_panel->addTab("\uE64D");
    m_panel->addTab("\uE65C");
    m_panel->addStretch();

    m_stackedWidget->addWidget(m_analysicPage);
    m_stackedWidget->addWidget(m_purchasePage);
    m_stackedWidget->addWidget(m_productPage);
    m_stackedWidget->addWidget(m_memberPage);
    // m_stackedWidget->addWidget(m_notificationPage);
    // m_stackedWidget->addWidget(m_optionPage);

    m_layout->addWidget(m_panel);
    m_layout->addWidget(m_stackedWidget);

    QObject::connect(m_panel, &Panel::currentChanged, m_stackedWidget, &QStackedWidget::setCurrentIndex);
}

MainWindow::~MainWindow()
{
}
