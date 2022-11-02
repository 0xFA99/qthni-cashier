#ifndef HMATERIALLABEL_PRIVATE_H
#define HMATERIALLABEL_PRIVATE_H

#include <QFont>
#include <QColor>

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
    int                     m_size;
    QFont::Weight           m_weight;
    QColor                  m_color;
};

#endif
