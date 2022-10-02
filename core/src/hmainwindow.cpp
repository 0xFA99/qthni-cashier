#include "hmainwindow.h"
#include <QHBoxLayout>

#include "hmaterialtheme.h"
#include "hmaterialbutton.h"
#include "hmaterialpanel.h"
#include "hmaterialimage.h"

#include <QSizePolicy>

#include <QStackedWidget>
#include <QDebug>

HMainWindow::HMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_centralWidget(new HMaterialFrame(HMaterial::Level2, this))
{
    setCentralWidget(m_centralWidget);
    m_centralWidget->setCornerRadius(0);

    QHBoxLayout *layout = new QHBoxLayout(m_centralWidget);

    HMaterialPanel *panel = new HMaterialPanel(m_centralWidget);

    panel->addItem(QIcon(":/icons/icons/sun.svg"));
    panel->addItem(QIcon(":/icons/icons/moon.svg"));
    panel->addItem(QIcon(":/icons/icons/bag.svg"));
    panel->addItem(QIcon(":/icons/icons/option.svg"));
    panel->addStretch(1);
    panel->addThemeControl();

    panel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);

    // HMaterialButton *button = new HMaterialButton(m_centralWidget);
    // button->setIcon(QIcon(":/icons/icons/moon.svg"));

    layout->addWidget(panel);

    // QObject::connect(panel, &HMaterialPanel::currentChanged, this, &HMainWindow::test);



    // test
    QStackedWidget *stack = new QStackedWidget(m_centralWidget);
    
    // Widget Collection
    HMaterialFrame *w1 = new HMaterialFrame(HMaterial::Level1, stack);
    HMaterialFrame *w2 = new HMaterialFrame(HMaterial::Level2, stack);
    HMaterialFrame *w3 = new HMaterialFrame(HMaterial::Level3, stack);
    HMaterialFrame *w4 = new HMaterialFrame(HMaterial::Level4, stack);

    /*
     * W3 Product List
     */
    QHBoxLayout *w3Layout = new QHBoxLayout(w3);
    HMaterialImage *image = new HMaterialImage(m_centralWidget);

    HMaterialImage *image2 = new HMaterialImage(QImage(":/images/images/ANDRO.png"), m_centralWidget);
    image2->setImageSize(QSize(300, 300));

    w3Layout->addWidget(image);
    w3Layout->addWidget(image2);
    // ------------------------------
    stack->addWidget(w1);
    stack->addWidget(w2);
    stack->addWidget(w3);
    stack->addWidget(w4);

    QObject::connect(panel, &HMaterialPanel::currentChanged, stack, &QStackedWidget::setCurrentIndex);
    layout->addWidget(stack);
    layout->setSpacing(10);
}

HMainWindow::~HMainWindow()
{
}

void HMainWindow::test(int index)
{
    qDebug() << index;
}
