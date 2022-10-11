#include "hmainwindow.h"
#include <QWidget>
#include <QHBoxLayout>

#include "hmaterialdialog.h"
#include "hmaterialflatbutton.h"

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
    //stack->addWidget(w1);
    //stack->addWidget(w2);
    //stack->addWidget(w3);
    //stack->addWidget(w4);

    //QObject::connect(panel, &HMaterialPanel::currentChanged, stack, &QStackedWidget::setCurrentIndex);
    //layout->addWidget(stack);
    //layout->setSpacing(10);

    HMaterialFlatButton *showButton = new HMaterialFlatButton("Show", m_centralWidget);
    layout->addWidget(showButton);

    HMaterialDialog *dialog = new HMaterialDialog;
    dialog->setParent(m_centralWidget);
    QHBoxLayout *dialogLayout = new QHBoxLayout;

    // fill the dialog
    QWidget *dialogWidget = new QWidget;
    QHBoxLayout *dialogWidgetLayout = new QHBoxLayout;
    dialogWidget->setLayout(dialogWidgetLayout);

    HMaterialFlatButton *closeButton = new HMaterialFlatButton("Close");
    dialogWidgetLayout->addWidget(closeButton);
    dialogWidgetLayout->setAlignment(closeButton, Qt::AlignBottom | Qt::AlignCenter);

    closeButton->setMaximumWidth(150);
    dialogWidget->setMinimumHeight(300);

    dialog->setWindowLayout(dialogLayout);

    dialogLayout->addWidget(dialogWidget);

    QObject::connect(showButton, &QPushButton::pressed, [=]() {
        dialog->showDialog();
    });

    QObject::connect(closeButton, &QPushButton::pressed, [=]() {
        dialog->hideDialog();
    });
}

HMainWindow::~HMainWindow()
{
}

void HMainWindow::test(int index)
{
    qDebug() << index;
}
