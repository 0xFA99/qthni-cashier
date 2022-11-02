#ifndef HMATERIALFLATBUTTON_P_H
#define HMATERIALFLATBUTTON_P_H

#include <QtGlobal>
#include <QColor>
#include "hmaterialtheme.h"

class HMaterialFlatButton;
class HMaterialRippleOverlay;
class HMaterialFlatButtonStateMachine;

class HMaterialFlatButtonPrivate
{
    Q_DISABLE_COPY(HMaterialFlatButtonPrivate)
    Q_DECLARE_PUBLIC(HMaterialFlatButton)

public:
    HMaterialFlatButtonPrivate(HMaterialFlatButton *q);
    virtual ~HMaterialFlatButtonPrivate();

    void init();

    HMaterialFlatButton                 *const q_ptr;
    HMaterialRippleOverlay              *rippleOverlay;
    HMaterialFlatButtonStateMachine     *stateMachine;
    HMaterial::Role                     role;
    HMaterial::RippleStyle              rippleStyle;
    HMaterial::ButtonIconPlacement      iconPlacement;
    HMaterial::OverlayStyle             overlayStyle;
    Qt::BGMode                          bgMode;
    Qt::Alignment                       textAlignment;
    QColor                              backgroundColor;
    QColor                              foregroundColor;
    QColor                              overlayColor;
    QColor                              rippleColor;
    QColor                              disabledColor;
    QColor                              disabledBackgroundColor;
    qreal                               fixedRippleRadius;
    qreal                               cornerRadius;
    qreal                               baseOpacity;
    qreal                               fontSize;
    bool                                useThemeColors;
    bool                                useFixedRippleRadius;
    bool                                haloVisible;
};

#endif
