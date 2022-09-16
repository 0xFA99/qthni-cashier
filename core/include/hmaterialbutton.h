#ifndef HMATERIALBUTTON_H
#define HMATERIALBUTTON_H

#include "hmaterialflatbutton.h"
#include "hinterfacewidget.h"

class HMaterialButton : public HMaterialFlatButton, public HInterfaceWidget
{
    Q_OBJECT

public:
    HMaterialButton(QWidget *parent = nullptr);
    HMaterialButton(const QString &text, QWidget *parent = nullptr);
    HMaterialButton(QIcon icon, const QString &text, QWidget *parent = nullptr);
    ~HMaterialButton();

    void setDarkTheme() override;
    void setLightTheme() override;
};

#endif
