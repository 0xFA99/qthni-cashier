#ifndef HMEMBERLIST_PRIVATE_H
#define HMEMBERLIST_PRIVATE_H

#include "hmaterialbadge.h"
#include "hmateriallabel.h"
#include "hmaterialflatbutton.h"

class QGridLayout;

class HMemberList;
class HMemberListPrivate
{
    Q_DISABLE_COPY(HMemberListPrivate)
    Q_DECLARE_PUBLIC(HMemberList)

public:
    HMemberListPrivate(HMemberList *q);
    ~HMemberListPrivate();

    void init();

    HMemberList *const  q_ptr;

    QGridLayout         *m_layout;
    HMaterialBadge      *m_badge;
    HMaterialLabel      *m_title;
    HMaterialFlatButton *m_gridButton;
    HMaterialFlatButton *m_vertButton;
};

#endif
