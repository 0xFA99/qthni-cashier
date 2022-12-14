#ifndef QTHNI_PANEL_PRIVATE_H
#define QTHNI_PANEL_PRIVATE_H

#include <QtGlobal>

#include "qtmaterial/lib/qtmaterialtheme.h"

class QVBoxLayout;
class Panel;
class PanelInkBar;

class PanelPrivate
{
    Q_DISABLE_COPY(PanelPrivate)
    Q_DECLARE_PUBLIC(Panel)

public:
    explicit PanelPrivate(Panel *q);
    ~PanelPrivate();

    void init();

    Panel *const            q_ptr;
    PanelInkBar             *inkBar;
    QVBoxLayout             *tabLayout;
    Material::RippleStyle   rippleStyle;
    QColor                  inkColor;
    QColor                  backgroundColor;
    QColor                  textColor;
    int                     tab;
    bool                    showHalo;
    bool                    useThemeColors;
};

#endif // QTHNI_PANEL_PRIVATE_H
