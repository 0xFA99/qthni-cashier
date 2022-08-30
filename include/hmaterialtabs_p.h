#ifndef HMATERIALTABS_P_H
#define HMATERIALTABS_P_H

#include <QtGlobal>

#include "hmaterialtheme.h"

class QHBoxLayout;
class HMaterialTabs;
class HMaterialTabsInkBar;

class HMaterialTabsPrivate
{
    Q_DISABLE_COPY(HMaterialTabsPrivate)
    Q_DECLARE_PUBLIC(HMaterialTabs)

public:
    HMaterialTabsPrivate(HMaterialTabs *q);
    ~HMaterialTabsPrivate();

    void init();

    HMaterialTabs           *const q_ptr;
    HMaterialTabsInkBar     *inkBar;
    QHBoxLayout             *tabLayout;
    HMaterial::RippleStyle  rippleStyle;
    QColor                  inkColor;
    QColor                  backgroundColor;
    QColor                  textColor;
    int                     tab;
    bool                    showHalo;
    bool                    useThemeColors;
};

#endif
