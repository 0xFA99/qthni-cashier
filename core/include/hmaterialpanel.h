#ifndef HMATERIALPANEL_H
#define HMATERIALPANEL_H

#include "hmaterialframe.h"
#include "hmaterialbutton.h"
#include "hthemecontrol.h"

#include <QVBoxLayout>

class HMaterialPanel : public HMaterialFrame
{
    Q_OBJECT

public:
    HMaterialPanel(QWidget *parent = nullptr);
    ~HMaterialPanel();

signals:
    void changingPageIndex(int index);

private:
    void changeCheckedButton(int number);

	HMaterialButton *button1;
	HMaterialButton *button2;
	HMaterialButton *button3;
	HMaterialButton *button4;
	HMaterialButton *button5;

    HThemeControl *themeControl;

    QVBoxLayout *m_layout;
};

#endif
