#ifndef HMATERIALRAISEDBUTTON_P_H
#define HMATERIALRAISEDBUTTON_P_H

#include "hmaterialflatbutton_p.h"

class QStateMachine;
class QState;
class QGraphicsDropShadowEffect;
class HMaterialRaisedButton;

class HMaterialRaisedButtonPrivate : public HMaterialFlatButtonPrivate
{
    Q_DISABLE_COPY(HMaterialRaisedButtonPrivate)
    Q_DECLARE_PUBLIC(HMaterialRaisedButton)

public:
    HMaterialRaisedButtonPrivate(HMaterialRaisedButton *q);
    ~HMaterialRaisedButtonPrivate();

    void init();

    QStateMachine               *shadowStateMachine;
    QState                      *normalState;
    QState                      *pressedState;
    QGraphicsDropShadowEffect   *effect;
};

#endif
