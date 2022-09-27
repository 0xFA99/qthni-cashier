#include "hmainwindow.h"
#include <QHBoxLayout>

#include "hmaterialframe.h"
#include "hmaterialtheme.h"

HMainWindow::HMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_centralWidget(new HMaterialFrame(this))
{
    setCentralWidget(m_centralWidget);

    QHBoxLayout *layout = new QHBoxLayout(m_centralWidget);


    HMaterialFrame *frame1 = new HMaterialFrame(m_centralWidget);
    HMaterialFrame *frame2 = new HMaterialFrame(HMaterial::Level2, m_centralWidget);
    HMaterialFrame *frame3 = new HMaterialFrame(HMaterial::Level3, m_centralWidget);
    HMaterialFrame *frame4 = new HMaterialFrame(HMaterial::Level4, m_centralWidget);

    layout->addWidget(frame1);
    layout->addWidget(frame2);
    layout->addWidget(frame3);
    layout->addWidget(frame4);
}

HMainWindow::~HMainWindow()
{
}
