#ifndef QTHNI_EXTENDITEM_P_H
#define QTHNI_EXTENDITEM_P_H

#include <QLabel>
#include <QUuid>

#include "qtmaterial/components/qtmaterialimage.h"
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
    QtMaterialImage         *m_avatar;

    QtMaterialFlatButton    *m_decreaseButton;
    QtMaterialFlatButton    *m_increaseButton;

    QLabel                  *m_title;
    QLabel                  *m_amount;
    int                     m_memberPrice;
    int                     m_customerPrice;
    int                     m_stock;
    QUuid                   m_uuid;
};

#endif //QTHNI_EXTENDITEM_P_H
