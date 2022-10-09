#ifndef HMATERIALSPERATOR_PRIVATE_H
#define HMATERIALSPERATOR_PRIVATE_H

#include <QColor>

class HMaterialSperator;
class HMaterialSperatorPrivate
{
    Q_DISABLE_COPY(HMaterialSperatorPrivate)
    Q_DECLARE_PUBLIC(HMaterialSperator)

public:
    HMaterialSperatorPrivate(HMaterialSperator *q);
    ~HMaterialSperatorPrivate();

    void init();

    HMaterialSperator *const        q_ptr;
    QColor                          m_color;
    Qt::PenStyle                    m_style;
    int                             m_width;

};

#endif
