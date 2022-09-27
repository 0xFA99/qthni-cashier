#include "hmainwindow.h"
#include <QHBoxLayout>

#include "hmateriallabel.h"
#include "hmaterialtheme.h"

HMainWindow::HMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_centralWidget(new HMaterialFrame(0, this))
{
    setCentralWidget(m_centralWidget);

    QHBoxLayout *layout = new QHBoxLayout(m_centralWidget);

    HMaterialLabel *label = new HMaterialLabel("Nama Saya", m_centralWidget);
    HMaterialLabel *label2 = new HMaterialLabel("Nur Fajar Hidayatullah", m_centralWidget);

    label->setLabelStyle(HMaterial::Heading);

    layout->addWidget(label);
    layout->addWidget(label2);

}

HMainWindow::~HMainWindow()
{
}
