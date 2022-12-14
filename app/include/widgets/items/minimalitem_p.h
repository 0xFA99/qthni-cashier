#ifndef QTHNI_MINIMALITEM_P_H
#define QTHNI_MINIMALITEM_P_H

#include <QLabel>
#include "qtmaterial/components/qtmaterialavatar.h"

class QHBoxLayout;

class MinimalItem;
class MinimalItemPrivate
{
    Q_DISABLE_COPY(MinimalItemPrivate)
    Q_DECLARE_PUBLIC(MinimalItem)

public:
    explicit MinimalItemPrivate(MinimalItem *q);
    ~MinimalItemPrivate();

    void init();

    MinimalItem *const      q_ptr;
    QHBoxLayout             *m_layout;

    QtMaterialAvatar        *m_avatar;

    QLabel                  *m_title;
    QLabel                  *m_extraTitle;
};

#endif //QTHNI_MINIMALITEM_P_H
