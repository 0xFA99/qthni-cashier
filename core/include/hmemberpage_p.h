#ifndef HMEMBERPAGE_PRIVATE_H
#define HMEMBERPAGE_PRIVATE_H

#include "hmemberlist.h"

class QGridLayout;

class HMemberPage;
class HMemberPagePrivate
{
    Q_DISABLE_COPY(HMemberPagePrivate)
    Q_DECLARE_PUBLIC(HMemberPage)

public:
    HMemberPagePrivate(HMemberPage *q);
    ~HMemberPagePrivate();

    void init();

    HMemberPage *const  q_ptr;
    QGridLayout         *m_layout;
    HMemberList         *m_memberList;
};

#endif
