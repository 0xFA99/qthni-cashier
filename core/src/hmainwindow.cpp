#include "hmainwindow.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

#include "hanalysicpage.h"
#include "hpurchasepage.h"
#include "haddproductpage.h"
#include "haddmemberpage.h"
#include "hoptionpage.h"

HMainWindow::HMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_centralWidget(new HMaterialFrame(LevelColor::Level1, this))
    , m_panel(new HMaterialPanel(m_centralWidget))
    , m_stack(new QStackedWidget(m_centralWidget))
{
    QHBoxLayout *layout = new QHBoxLayout(m_centralWidget);

    m_centralWidget->setCornerRadius(0);

    // Create all pages
    HAnalysicPage *page1 = new HAnalysicPage(m_centralWidget);
    HPurchasePage *page2 = new HPurchasePage(m_centralWidget);
    HAddProductPage *page3 = new HAddProductPage(m_centralWidget);
    HAddMemberPage *page4 = new HAddMemberPage(m_centralWidget);
    HOptionPage *page5 = new HOptionPage(m_centralWidget);

    m_stack->addWidget(page1);
    m_stack->addWidget(page2);
    m_stack->addWidget(page3);
    m_stack->addWidget(page4);
    m_stack->addWidget(page5);

    layout->addWidget(m_panel);
    layout->addWidget(m_stack);

    setCentralWidget(m_centralWidget);

    QObject::connect(m_panel, &HMaterialPanel::changingPageIndex,
            [=](int index) { m_stack->setCurrentIndex(index); });
}

HMainWindow::~HMainWindow()
{
}
