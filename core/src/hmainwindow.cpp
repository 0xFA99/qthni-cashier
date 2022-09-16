#include "hmainwindow.h"

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "hthemecontrol.h"
#include "hmateriallabel.h"
#include "hmaterialframe.h"
#include "hmaterialbutton.h"

HMainWindow::HMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *widget = new QWidget(this);
    QHBoxLayout *layout = new QHBoxLayout(widget);

    HThemeControl *control = HThemeControl::getThemeControl();

    HMaterialFrame *frame1 = new HMaterialFrame(LevelColor::Level1, widget);
    HMaterialFrame *frame2 = new HMaterialFrame(LevelColor::Level3, widget);

    HMaterialLabel *label1 = new HMaterialLabel("Heading Label", LabelStyle::Heading, frame1);
    HMaterialLabel *label2 = new HMaterialLabel("Subheading Label", LabelStyle::Subheading, frame1);
    HMaterialLabel *label3 = new HMaterialLabel("Body Label", LabelStyle::Body, frame2);
    HMaterialLabel *label4 = new HMaterialLabel("Caption Label", LabelStyle::Caption, frame2);
    
    HMaterialButton *button1 = new HMaterialButton("Button 1", frame1);
    HMaterialButton *button2 = new HMaterialButton(QIcon(":/icons/icons/sun.svg"), "Button1", frame1);
    HMaterialButton *button3 = new HMaterialButton("Button 2", frame2);
    HMaterialButton *button4 = new HMaterialButton(QIcon(":/icons/icons/moon.svg"), "Button2", frame2);
   
    QVBoxLayout *layout1 = new QVBoxLayout(frame1);
    QVBoxLayout *layout2 = new QVBoxLayout(frame2);

    layout1->addWidget(label1);
    layout1->addWidget(label2);
    layout1->addWidget(button1);
    layout1->addWidget(button2);

    layout2->addWidget(label3);
    layout2->addWidget(label4);
    layout2->addWidget(button3);
    layout2->addWidget(button4);

    layout->addWidget(control);
    layout->addWidget(frame1);
    layout->addWidget(frame2);
    layout->setContentsMargins(0, 0, 0, 0);

    setCentralWidget(widget);
}

HMainWindow::~HMainWindow()
{
}
