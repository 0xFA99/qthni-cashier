#ifndef QTHNI_OPERATEITEM_P_H
#define QTHNI_OPERATEITEM_P_H

#include <QLabel>

#include "qtmaterial/components/qtmaterialavatar.h"
#include "qtmaterial/components/qtmaterialflatbutton.h"

class QGridLayout;

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

    QColor                  m_titleColor;
    QColor                  m_subTitleColor;

    int                     m_titleSize;
    int                     m_subTitleSize;

    // QObject                 *m_object;
    int                     m_index;
};

#endif //QTHNI_OPERATEITEM_P_H
