#ifndef QTHNI_MEMBERMANAGER_P_H
#define QTHNI_MEMBERMANAGER_P_H

#include <QVector>

class Member;
class MemberManager;
class MemberManagerPrivate
{
    Q_DISABLE_COPY(MemberManagerPrivate)
    Q_DECLARE_PUBLIC(MemberManager)

public:
    explicit MemberManagerPrivate(MemberManager *q);
    ~MemberManagerPrivate();

    void init();

    MemberManager *const    q_ptr;
    QVector<Member *>       m_memberList;
};

#endif //QTHNI_MEMBERMANAGER_P_H
