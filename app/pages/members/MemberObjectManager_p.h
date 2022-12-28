#ifndef QTHNI_MEMBEROBJECTMANAGER_P_H
#define QTHNI_MEMBEROBJECTMANAGER_P_H

#include <QVector>

class MemberObject;
class MemberObjectManager;
class MemberObjectManagerPrivate
{
    Q_DISABLE_COPY(MemberObjectManagerPrivate)
    Q_DECLARE_PUBLIC(MemberObjectManager)

public:
    explicit MemberObjectManagerPrivate(MemberObjectManager *q);
    ~MemberObjectManagerPrivate();

    void init();

    MemberObjectManager *const  q_ptr;
    QVector<MemberObject *>     m_memberList;
};

#endif //QTHNI_MEMBEROBJECTMANAGER_P_H
