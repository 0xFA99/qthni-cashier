#ifndef QTHNI_MEMBERPAGE_H
#define QTHNI_MEMBERPAGE_H

#include <QWidget>

class MemberObject;
class OperateItem;
class MemberPagePrivate;
class MemberPage : public QWidget
{
    Q_OBJECT

public:
    explicit MemberPage(QWidget *parent = nullptr);
    ~MemberPage();

public slots:
    void addingMember(MemberObject *);
    void editMember(int);
    void updateMember(int, MemberObject*);
    void deleteMember(int);

protected:
    const QScopedPointer<MemberPagePrivate> d_ptr;

private:
    Q_DISABLE_COPY(MemberPage)
    Q_DECLARE_PRIVATE(MemberPage)
};

#endif //QTHNI_MEMBERPAGE_H
