#ifndef QTHNI_DEFAULTITEM_P_H
#define QTHNI_DEFAULTITEM_P_H

#include <QLabel>
#include "qtmaterial/components/qtmaterialavatar.h"

class QGridLayout;

class DefaultItem;
class DefaultItemPrivate
{
    Q_DISABLE_COPY(DefaultItemPrivate)
    Q_DECLARE_PUBLIC(DefaultItem)

public:
    explicit DefaultItemPrivate(DefaultItem *q);
    ~DefaultItemPrivate();

    void init();

    DefaultItem *const  q_ptr;
    QGridLayout         *m_layout;
    QtMaterialAvatar    *m_avatar;

    QLabel              *m_title;
    QLabel              *m_subTitle;
    QLabel              *m_extraTitle;

    QColor              m_titleColor;
    QColor              m_subTitleColor;
    QColor              m_extraTitleColor;

    int                 m_titleSize;
    int                 m_subTitleSize;
    int                 m_extraTitleSize;

    bool                m_hasImage;
};

#endif //QTHNI_DEFAULTITEM_P_H
