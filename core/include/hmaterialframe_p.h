#ifndef HMATERIALFRAME_INTERNAL_H
#define HMATERIALFRAME_INTERNAL_H

#include <QColor>

class HMaterialFrame;

class HMaterialFramePrivate
{
    Q_DISABLE_COPY(HMaterialFramePrivate)
    Q_DECLARE_PUBLIC(HMaterialFrame)

public:
    HMaterialFramePrivate(HMaterialFrame *q);
    ~HMaterialFramePrivate();

    void init();

    HMaterialFrame *const   q_ptr;
    QColor                  m_backgroundColor;
    qreal                   m_roundCorner;
    QList<QColor>           m_darkColors;
    QList<QColor>           m_lightColors;
    int                     m_colorLevel;
    bool                    m_followTheme;
};

#endif
