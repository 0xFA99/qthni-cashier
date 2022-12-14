#ifndef QTHNI_MEMBER_P_H
#define QTHNI_MEMBER_P_H

#include <QImage>

class Member;
class MemberPrivate
{
    Q_DISABLE_COPY(MemberPrivate)
    Q_DECLARE_PUBLIC(Member)

public:
    explicit MemberPrivate(Member *q);
    ~MemberPrivate();

    void init();

    Member *const   q_ptr;
    QImage          m_image;
    QString         m_name;
    QString         m_id;
};

#endif //QTHNI_MEMBER_P_H
