#ifndef HMEMBERITEM_PRIVATE_H
#define HMEMBERITEM_PRIVATE_H

#include "hmaterialavatar.h"
#include "hmateriallabel.h"
#include "hmaterialflatbutton.h"

class QGridLayout;

class HMemberItem;
class HMemberItemPrivate
{
    Q_DISABLE_COPY(HMemberItemPrivate)
    Q_DECLARE_PUBLIC(HMemberItem)

public:
    HMemberItemPrivate(HMemberItem *q);
    ~HMemberItemPrivate();

    void init();

    HMemberItem *const  q_ptr;

    QGridLayout         *m_layout;

    HMaterialAvatar     *m_avatar;
    HMaterialLabel      *m_name;
    HMaterialLabel      *m_id;
    HMaterialFlatButton *m_editButton;
    HMaterialFlatButton *m_removeButton;
};

#endif
