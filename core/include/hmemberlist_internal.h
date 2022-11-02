#ifndef HMEMBERLIST_INTERNAL_H
#define HMEMBERLIST_INTERNAL_H

#include <QWidget>

class HMemberList;
class HMemberListItem : public QWidget
{
    Q_OBJECT

public:
    HMemberListItem(HMemberList *parent);
    ~HMemberListItem();

private:
    Q_DISABLE_COPY(HMemberListItem)

    HMemberList *const  m_memberList;
};

#endif
