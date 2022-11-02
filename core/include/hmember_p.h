#ifndef HMEMBER_PRIVATE_H
#define HMEMBER_PRIVATE_H

#include <QImage>

class HMember;
class HMemberPrivate
{
    Q_DISABLE_COPY(HMemberPrivate)
    Q_DECLARE_PUBLIC(HMember)

public:
    HMemberPrivate(HMember *q);
    ~HMemberPrivate();

    void init();

    HMember *const  q_ptr;
    
    QImage          m_avatar;
    QString         m_name;
    QString         m_id;
};

#endif
