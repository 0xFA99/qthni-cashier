#ifndef QTHNI_MEMBERDIALOG_H
#define QTHNI_MEMBERDIALOG_H

#include <QWidget>


class Member;

class MemberDialogPrivate;
class MemberDialog : public QWidget
{
    Q_OBJECT

public:
    explicit MemberDialog(QWidget *parent = nullptr);
    ~MemberDialog();

    enum Mode { Edit, Add };
    void setMode(Mode mode);

    void setNameField(const QString &name);
    void setIDField(const QString &id);
    void setIndex(int index);

signals:
    void closedMemberDialog();
    void addedMember(Member *);
    void editedMember(int, Member *);

protected:
    const QScopedPointer<MemberDialogPrivate> d_ptr;

private:
    void clearField();
    void addMode();
    void editMode();

    Q_DISABLE_COPY(MemberDialog)
    Q_DECLARE_PRIVATE(MemberDialog)

private slots:
    void addSlot();
    void editSlot();
};

#endif //QTHNI_MEMBERDIALOG_H
