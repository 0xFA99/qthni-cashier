#ifndef QTHNI_MEMBERPAGE_H
#define QTHNI_MEMBERPAGE_H

#include <QWidget>

class MemberObjectManager;
class MemberObject;
class OperateItem;

class MemberPagePrivate;
class MemberPage : public QWidget
{
    Q_OBJECT

public:
    explicit MemberPage(MemberObjectManager *manager, QWidget *parent = nullptr);
    ~MemberPage();

    void syncMemberFromDB();

public slots:
    void addingMember(MemberObject&);
    void editMember(QUuid);
    void updateMember(QUuid, MemberObject&);
    void deleteMember(QUuid);

protected:
    const QScopedPointer<MemberPagePrivate> d_ptr;

private:
    void addMemberManager(MemberObjectManager *manager);

    void addMemberToManager(MemberObject&);
    void addMemberToItemList(MemberObject*);

    void addMemberToDB(MemberObject&);

    Q_DISABLE_COPY(MemberPage)
    Q_DECLARE_PRIVATE(MemberPage)
};

#endif //QTHNI_MEMBERPAGE_H
