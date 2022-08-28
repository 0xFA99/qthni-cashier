#ifndef HMATERIALICONBUTTON_P_H
#define HMATERIALICONBUTTON_P_H

#include <QtGlobal>

class HMaterialIconButton;
class HMaterialRippleOverlay;
class QColor;

class HMaterialIconButtonPrivate
{
    Q_DISABLE_COPY(HMaterialIconButtonPrivate)
    Q_DECLARE_PUBLIC(HMaterialIconButton)

public:
    HMaterialIconButtonPrivate(HMaterialIconButton *q);
    virtual ~HMaterialIconButtonPrivate();

    void init();
    void updateRipple();

    HMaterialIconButton     *const q_ptr;
    HMaterialRippleOverlay  *rippleOverlay;
    QColor                  color;
    QColor                  disabledColor;
    bool                    useThemeColors;
};

#endif
