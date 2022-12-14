#ifndef QTHNI_EXTENDITEM_P_H
#define QTHNI_EXTENDITEM_P_H

#include <QLabel>

#include "qtmaterial/components/qtmaterialavatar.h"
#include "qtmaterial/components/qtmaterialflatbutton.h"

class QHBoxLayout;

class ExtendItem;
class ExtendItemPrivate
{
    Q_DISABLE_COPY(ExtendItemPrivate)
    Q_DECLARE_PUBLIC(ExtendItem)

public:
    explicit ExtendItemPrivate(ExtendItem *q);
    ~ExtendItemPrivate();

    void init();

    ExtendItem *const       q_ptr;
    QHBoxLayout             *m_layout;
    QtMaterialAvatar        *m_avatar;

    QtMaterialFlatButton    *m_decreaseButton;
    QtMaterialFlatButton    *m_increaseButton;
    QtMaterialFlatButton    *m_removeButton;

    QLabel                  *m_title;
    QLabel                  *m_amount;

    QColor                  m_titleColor;
    QColor                  m_amountColor;

    int                     m_titleSize;
    int                     m_amountSize;
};

#endif //QTHNI_EXTENDITEM_P_H
