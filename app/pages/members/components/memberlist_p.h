#ifndef QTHNI_MEMBERLIST_P_H
#define QTHNI_MEMBERLIST_P_H

class QVBoxLayout;

class MemberList;
class MemberListPrivate
{
    Q_DISABLE_COPY(MemberListPrivate)
    Q_DECLARE_PUBLIC(MemberList)

public:
    explicit MemberListPrivate(MemberList *q);
    ~MemberListPrivate();

    void init();

    MemberList *const       q_ptr;
    QVBoxLayout             *m_layout;
};

#endif //QTHNI_MEMBERLIST_P_H
