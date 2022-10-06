#ifndef HMATERIALLABEL_PRIVATE_H
#define HMATERIALLABEL_PRIVATE_H

#include <QColor>

#include "hmaterialtheme.h"

class HMaterialLabel;

class HMaterialLabelPrivate
{
    Q_DISABLE_COPY(HMaterialLabelPrivate)
    Q_DECLARE_PUBLIC(HMaterialLabel)

public:
    HMaterialLabelPrivate(HMaterialLabel *q);
    ~HMaterialLabelPrivate();

    void init();

    HMaterialLabel *const   q_ptr;
    HMaterial::LabelStyle   m_labelStyle;
    HMaterial::Role         m_role;
    QList<QColor>           m_darkColor;
    QList<QColor>           m_lightColor;
    QColor                  m_textColor;
    bool                    m_followTheme;
};

#endif

