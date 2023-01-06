#ifndef QTHNI_MEMBEROBJECTMANAGER_H
#define QTHNI_MEMBEROBJECTMANAGER_H

#include <QObject>

class MemberObject;
class MemberObjectManagerPrivate;
class MemberObjectManager : public QObject
{
    Q_OBJECT

public:
    explicit MemberObjectManager(QObject *parent = nullptr);
    ~MemberObjectManager();

    MemberObject* getMemberObject(const QUuid &);

    void addMember(MemberObject*);
    void updateMember(QUuid, MemberObject&);
    void deleteMember(QUuid);

protected:
    const QScopedPointer<MemberObjectManagerPrivate> d_ptr;

private:
    Q_DISABLE_COPY(MemberObjectManager)
    Q_DECLARE_PRIVATE(MemberObjectManager)
};


#endif //QTHNI_MEMBEROBJECTMANAGER_H
