#ifndef QTHNI_OPERATEITEM_P_H
#define QTHNI_OPERATEITEM_P_H

#include "qtmaterial/components/qtmaterialavatar.h"
#include "qtmaterial/components/qtmaterialflatbutton.h"

class QGridLayout;
class QLabel;

class OperateItem;
class OperateItemPrivate
{
    Q_DISABLE_COPY(OperateItemPrivate)
    Q_DECLARE_PUBLIC(OperateItem)

public:
    explicit OperateItemPrivate(OperateItem *q);
    ~OperateItemPrivate();

    void init();

    OperateItem *const      q_ptr;

    QGridLayout             *m_layout;
    QtMaterialAvatar        *m_avatar;
    QtMaterialFlatButton    *m_editButton;
    QtMaterialFlatButton    *m_deleteButton;
    QLabel                  *m_title;
    QLabel                  *m_subTitle;
    int                     m_index;
};

#endif //QTHNI_OPERATEITEM_P_H
