#ifndef HMEMBERLISTITEM_PRIVATE_H
#define HMEMBERLISTITEM_PRIVATE_H

#include "hmaterialavatar.h"
#include "hmateriallabel.h"
#include "hmaterialflatbutton.h"

class QGridLayout;

class HMemberList;
class HMemberListItem
{
    Q_DISABLE_COPY(HMemberListItem)
    Q_DECLARE_PUBLIC(HMemberList)

public:
    HMemberListItem(HMemberList *q);
    ~HMemberListItem();

    void init();

    HMemberListItem *const  q_ptr;
    QGridLayout             *m_layout;
    HMaterialAvatar         *m_avatar;
    HMaterialLabel          *m_name;
    HMaterialLabel          *m_id;
    HMaterialFlatButton     *m_editButton;
    HMaterialFlatButton     *m_removeButton;
};

#endif
