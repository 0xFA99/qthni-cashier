#include "hmainwindow.h"

#include <QWidget>
#include <QHBoxLayout>
#include <QWidget>

#include <QStackedWidget>
#include <QGridLayout>
#include <QSizePolicy>

#include "hpanel.h"
#include "hpurchasepage.h"
#include "hanalysicpage.h"
#include "hproductpage.h"
#include "hmemberpage.h"
#include "hnotificationpage.h"
#include "hoptionpage.h"

HMainWindow::HMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_centralWidget(new QWidget(this))
{
    setCentralWidget(m_centralWidget);

    QHBoxLayout *m_layout = new QHBoxLayout(m_centralWidget);
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->setSpacing(0);

    HPanel *panel = new HPanel(m_centralWidget);
    panel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);

    panel->addItem("\uE648");
    panel->addItem("\uE654");
    panel->addItem("\uE626");
    panel->addItem("\uE65B");
    panel->addStretch();
    panel->addItem("\uE629");
    panel->addItem("\uE637");
    panel->addLogo();


    m_layout->addWidget(panel);

    /*
    HMaterialFlatButton *button = new HMaterialFlatButton("EXIT", m_centralWidget);
    button->setBackgroundColor(QColor(225, 231, 255));
    button->setForegroundColor(QColor(101, 126, 248));
    button->setHaloVisible(false);
    button->setOverlayStyle(HMaterial::TintedOverlay);
    button->setBaseOpacity(1);
    button->setCornerRadius(button->sizeHint().height() / 2);

    HMaterialFlatButton *button2 = new HMaterialFlatButton(m_centralWidget);
    button2->setFont(QFont("iconfont", 18, QFont::Medium));
    button2->setText("\uE626");
    button2->setForegroundColor(QColor(0, 0, 0, 115));
    button2->setHaloVisible(false);
    button2->setOverlayStyle(HMaterial::GrayOverlay);
    button2->setBaseOpacity(1);
    button2->setCornerRadius(button2->sizeHint().height() / 2);
    button2->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    */
    QStackedWidget *stack = new QStackedWidget(m_centralWidget);

    HAnalysicPage       *page1 = new HAnalysicPage(stack);
    HPurchasePage       *page2 = new HPurchasePage(stack);
    HProductPage        *page3 = new HProductPage(stack);
    HMemberPage         *page4 = new HMemberPage(stack);
    HNotificationPage   *page5 = new HNotificationPage(stack);
    HOptionPage         *page6 = new HOptionPage(stack);

    stack->addWidget(page1);
    stack->addWidget(page2);
    stack->addWidget(page3);
    stack->addWidget(page4);
    stack->addWidget(page5);
    stack->addWidget(page6);

    m_layout->addWidget(stack);

    QObject::connect(panel, &HPanel::currentChanged, [stack](int index) {
        stack->setCurrentIndex(index - 1);
    });
}

HMainWindow::~HMainWindow()
{
}
