#include "hmaterialpanel.h"

HMaterialPanel::HMaterialPanel(QWidget *parent)
    : HMaterialFrame(LevelColor::Level1, parent)
    , m_layout(new QVBoxLayout(this))
{
    themeControl = HThemeControl::getThemeControl();

    button1 = new HMaterialButton(QIcon(":/icons/icons/analysic.svg"), "", this);
    button2 = new HMaterialButton(QIcon(":/icons/icons/purchase.svg"), "", this);
    button3 = new HMaterialButton(QIcon(":/icons/icons/addProduct.svg"), "", this);
    button4 = new HMaterialButton(QIcon(":/icons/icons/addMember.svg"), "", this);
    button5 = new HMaterialButton(QIcon(":/icons/icons/option.svg"), "", this);

    button1->setIconPlacement(HMaterial::CenterIcon);
    button2->setIconPlacement(HMaterial::CenterIcon);
    button3->setIconPlacement(HMaterial::CenterIcon);
    button4->setIconPlacement(HMaterial::CenterIcon);
    button5->setIconPlacement(HMaterial::CenterIcon);
    themeControl->setIconPlacement(HMaterial::CenterIcon);

    m_layout->addWidget(button1);
    m_layout->addWidget(button2);
    m_layout->addWidget(button3);
    m_layout->addWidget(button4);
    m_layout->addStretch(1);
    m_layout->addWidget(themeControl);
    m_layout->addWidget(button5);

    QObject::connect(button1, &QPushButton::clicked, [=]() { changeCheckedButton(1); });
    QObject::connect(button2, &QPushButton::clicked, [=]() { changeCheckedButton(2); });
    QObject::connect(button3, &QPushButton::clicked, [=]() { changeCheckedButton(3); });
    QObject::connect(button4, &QPushButton::clicked, [=]() { changeCheckedButton(4); });
    QObject::connect(button5, &QPushButton::clicked, [=]() { changeCheckedButton(5); });
}

HMaterialPanel::~HMaterialPanel()
{
}

void HMaterialPanel::changeCheckedButton(int number)
{
    QColor defaultColor = themeControl->foregroundColor();

    button1->setForegroundColor(defaultColor);
    button2->setForegroundColor(defaultColor);
    button3->setForegroundColor(defaultColor);
    button4->setForegroundColor(defaultColor);
    button5->setForegroundColor(defaultColor);

	button1->setHaloVisible(false);
	button2->setHaloVisible(false);
	button3->setHaloVisible(false);
	button4->setHaloVisible(false);
	button5->setHaloVisible(false);

    button1->locked = false;
    button2->locked = false;
    button3->locked = false;
    button4->locked = false;
    button5->locked = false;

    switch (number) {
        case 1:
            button1->setForegroundColor(QColor(28, 174, 129));
			button1->setHaloVisible(true);
            button1->locked = true;
            changingPageIndex(0);
            break;
        case 2:
            button2->setForegroundColor(QColor(28, 174, 129));
			button2->setHaloVisible(true);
            button2->locked = true;
            changingPageIndex(1);
            break;
        case 3:
            button3->setForegroundColor(QColor(28, 174, 129));
			button3->setHaloVisible(true);
            button3->locked = true;
            changingPageIndex(2);
            break;
        case 4:
            button4->setForegroundColor(QColor(28, 174, 129));
			button4->setHaloVisible(true);
            button4->locked = true;
            changingPageIndex(3);
            break;
        case 5:
            button5->setForegroundColor(QColor(28, 174, 129));
			button5->setHaloVisible(true);
            button5->locked = true;
            changingPageIndex(4);
            break;
    }
}
