#include "hmainwindow.h"
#include <QHBoxLayout>

#include "hmaterialtheme.h"
#include "hmaterialbutton.h"
#include "hmaterialpanel.h"

#include <QSizePolicy>
#include <QDebug>

HMainWindow::HMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_centralWidget(new HMaterialFrame(this))
{
    setCentralWidget(m_centralWidget);

    QHBoxLayout *layout = new QHBoxLayout(m_centralWidget);

    HMaterialPanel *panel = new HMaterialPanel(m_centralWidget);

    panel->addItem(QIcon(":/icons/icons/sun.svg"));
    panel->addItem(QIcon(":/icons/icons/moon.svg"));
    panel->addItem(QIcon(":/icons/icons/bag.svg"));
    panel->addItem(QIcon(":/icons/icons/option.svg"));
    panel->addStretch(1);
    panel->addThemeControl();

    panel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);

    HMaterialButton *button = new HMaterialButton(m_centralWidget);
    button->setIcon(QIcon(":/icons/icons/moon.svg"));

    layout->addWidget(panel);
    layout->addWidget(button);

    QObject::connect(panel, &HMaterialPanel::currentChanged, this, &HMainWindow::test);
}

HMainWindow::~HMainWindow()
{
}

void HMainWindow::test(int index)
{
    qDebug() << index;
}
