#include "hmainwindow.h"
#include <QHBoxLayout>

#include "hmaterialbutton.h"

HMainWindow::HMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_centralWidget(new HMaterialFrame(3, this))
{
    setCentralWidget(m_centralWidget);

    QHBoxLayout *layout = new QHBoxLayout(m_centralWidget);

    HMaterialButton *button = new HMaterialButton("Example Button", m_centralWidget);

    layout->addWidget(button);

}

HMainWindow::~HMainWindow()
{
}
