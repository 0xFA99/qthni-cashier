#ifndef QTHNI_MEMBERLIST_H
#define QTHNI_MEMBERLIST_H

#include <QWidget>

class OperateItem;

class MemberListPrivate;
class MemberList : public QWidget
{
    Q_OBJECT

public:
    explicit MemberList(QWidget *parent = nullptr);
    ~MemberList();

    void addMemberItem(OperateItem *item);
    void deleteMemberItem(QUuid);

protected:
    const QScopedPointer<MemberListPrivate> d_ptr;

private:
    Q_DISABLE_COPY(MemberList)
    Q_DECLARE_PRIVATE(MemberList)
};

#endif //QTHNI_MEMBERLIST_H
