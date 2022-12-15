#ifndef QTHNI_MEMBERPAGE_H
#define QTHNI_MEMBERPAGE_H

#include <QWidget>

class Member;
class OperateItem;
class MemberPagePrivate;
class MemberPage : public QWidget
{
    Q_OBJECT

public:
    explicit MemberPage(QWidget *parent = nullptr);
    ~MemberPage();

public slots:
    void addingMember(Member *);
    void editMember(int);
    void updateMember(int, Member *);
    void deleteMember(int);

protected:
    const QScopedPointer<MemberPagePrivate> d_ptr;

private:
    Q_DISABLE_COPY(MemberPage)
    Q_DECLARE_PRIVATE(MemberPage)
};

#endif //QTHNI_MEMBERPAGE_H
