#ifndef HMATERIALPANEL_PRIVATE_H
#define HMATERIALPANEL_PRIVATE_H

#include <QtGlobal>

#include "hmaterialtheme.h"

class QVBoxLayout;
class HMaterialPanel;

class HMaterialPanelPrivate
{
    Q_DISABLE_COPY(HMaterialPanelPrivate)
    Q_DECLARE_PUBLIC(HMaterialPanel)

public:
    HMaterialPanelPrivate(HMaterialPanel *q);
    ~HMaterialPanelPrivate();

    void init();

    HMaterialPanel *const   q_ptr;
    QVBoxLayout             *m_panelLayout;
    HMaterial::RippleStyle  m_rippleStyle;
    QColor                  m_backgroundColor;
    QColor                  m_textColor;
    int                     m_item;
};

#endif
