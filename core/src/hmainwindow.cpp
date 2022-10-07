#include "hmainwindow.h"
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>

#include "hmaterialtheme.h"
#include "hmaterialpanel.h"
#include "hmaterialsmallproduct.h"

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

    //HMaterialPanel *panel = new HMaterialPanel(m_centralWidget);

    /*panel->addItem(QIcon(":/icons/icons/sun.svg"));
    panel->addItem(QIcon(":/icons/icons/moon.svg"));
    panel->addItem(QIcon(":/icons/icons/bag.svg"));
    panel->addItem(QIcon(":/icons/icons/option.svg"));
    panel->addStretch(1);
    panel->addThemeControl();

    panel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);

    // 
    // layout->addWidget(panel);

    // test
    QStackedWidget *stack = new QStackedWidget(m_centralWidget);
    
    // Widget Collection
    HMaterialFrame *w1 = new HMaterialFrame(HMaterial::Level1, stack);
    HMaterialFrame *w2 = new HMaterialFrame(HMaterial::Level2, stack);
    HMaterialFrame *w3 = new HMaterialFrame(HMaterial::Level3, stack);
    HMaterialFrame *w4 = new HMaterialFrame(HMaterial::Level4, stack);
    */

    /*
     * W3 Product List
     */
    //QHBoxLayout *w3Layout = new QHBoxLayout(w3);

    //HMaterialImage *i1 = new HMaterialImage(QImage(":/images/images/ANDRO.png"), QSize(300, 300));

    //w3Layout->addWidget(i1);
    // ------------------------------
    HMaterialSmallProduct *image = new HMaterialSmallProduct("Android", m_centralWidget);
    image->setImage(QImage(":/images/images/ANDRO.png"));
    HMaterialSmallProduct *image2 = new HMaterialSmallProduct("Android", m_centralWidget);
    image2->setImage(QImage(":/images/images/ANDRO.png"));
    //stack->addWidget(w1);
    //stack->addWidget(w2);
    //stack->addWidget(w3);
    //stack->addWidget(w4);

    //QObject::connect(panel, &HMaterialPanel::currentChanged, stack, &QStackedWidget::setCurrentIndex);
    //layout->addWidget(stack);
    //layout->setSpacing(10);
    //
    //HMaterialImage *image = new HMaterialImage(QImage(":/images/images/ANDRO.png"), QSize(300, 300), m_centralWidget);
    //image->setImageSize(QSize(200, 200));
    

    layout->addWidget(image);
    layout->addWidget(image2);
}

HMainWindow::~HMainWindow()
{
}

void HMainWindow::test(int index)
{
    qDebug() << index;
}
