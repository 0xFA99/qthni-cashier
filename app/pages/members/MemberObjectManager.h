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

    [[nodiscard]] int lastItemIndex() const;

    MemberObject* getMemberObject(int);

    void addMember(MemberObject*);
    void updateMember(int, MemberObject*);
    void deleteMember(int);

protected:
    const QScopedPointer<MemberObjectManagerPrivate> d_ptr;

private:
    Q_DISABLE_COPY(MemberObjectManager)
    Q_DECLARE_PRIVATE(MemberObjectManager)
};


#endif //QTHNI_MEMBEROBJECTMANAGER_H
