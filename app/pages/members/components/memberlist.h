#ifndef QTHNI_MEMBERLIST_H
#define QTHNI_MEMBERLIST_H

#include <QWidget>

#include "widgets/items/OperateItem_p.h"

class MemberListPrivate;
class MemberList : public QWidget
{
    Q_OBJECT

public:
    explicit MemberList(QWidget *parent = nullptr);
    ~MemberList();

    void addMemberItem(OperateItem *item);
    // void updateMemberItem(int index, Member *);
    void deleteMemberItem(int index);

protected:
    const QScopedPointer<MemberListPrivate> d_ptr;

private:
    Q_DISABLE_COPY(MemberList)
    Q_DECLARE_PRIVATE(MemberList)
};

#endif //QTHNI_MEMBERLIST_H
