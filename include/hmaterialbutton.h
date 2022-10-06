#ifndef HMATERIALBUTTON_H
#define HMATERIALBUTTON_H

#include "hmaterialflatbutton.h"
#include "hinterfacewidget.h"

class HMaterialButtonPrivate;

class HMaterialButton : public HMaterialFlatButton, public HInterfaceWidget
{
    Q_OBJECT

public:
    HMaterialButton(QWidget *parent = nullptr);
    HMaterialButton(const QString &text, QWidget *parent = nullptr);
    HMaterialButton(QIcon icon, const QString &text, QWidget *parent = nullptr);
    ~HMaterialButton();
    
    void setLightTheme() override;
    void setDarkTheme() override;

    void setFollowTheme(bool value);
    bool isFollowTheme() const;

    void setColor(const QColor &color);

protected:
    const QScopedPointer<HMaterialButtonPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HMaterialButton);
    Q_DECLARE_PRIVATE(HMaterialButton);
};

#endif
