#ifndef QTHNI_MEMBERMANAGER_H
#define QTHNI_MEMBERMANAGER_H

#include <QObject>

class Member;
class MemberManagerPrivate;
class MemberManager : public QObject
{
    Q_OBJECT

public:
    explicit MemberManager(QObject *parent = nullptr);
    ~MemberManager();

    void addMember(Member *);
    void deleteMember(int index);

    Member* getMember(int index);

    [[nodiscard]] QString getMemberName(int index) const;
    [[nodiscard]] QString getMemberID(int index) const;

    [[nodiscard]] int lastItemIndex() const;

public slots:
    void updateMember(int, Member *);

protected:
    const QScopedPointer<MemberManagerPrivate> d_ptr;

private:
    Q_DISABLE_COPY(MemberManager)
    Q_DECLARE_PRIVATE(MemberManager)
};

#endif //QTHNI_MEMBERMANAGER_H
