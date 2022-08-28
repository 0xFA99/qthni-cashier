#ifndef HMATERIALRAISEDBUTTON_H
#define HMATERIALRAISEDBUTTON_H

#include "hmaterialflatbutton.h"

class HMaterialRaisedButtonPrivate;

class HMaterialRaisedButton : public HMaterialFlatButton
{
    Q_OBJECT

public:
    explicit HMaterialRaisedButton(QWidget *parent = nullptr);
    explicit HMaterialRaisedButton(const QString &text, QWidget *parent = 0);
    ~HMaterialRaisedButton();

protected:
    HMaterialRaisedButton(HMaterialRaisedButtonPrivate &d, QWidget *parent = nullptr);

    bool event(QEvent *event) Q_DECL_OVERRIDE;

private:
    Q_DISABLE_COPY(HMaterialRaisedButton);
    Q_DECLARE_PRIVATE(HMaterialRaisedButton);
};

#endif
