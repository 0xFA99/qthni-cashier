#ifndef QTHNI_MEMBERDIALOG_H
#define QTHNI_MEMBERDIALOG_H

#include <QWidget>

class MemberObject;

class MemberDialogPrivate;
class MemberDialog : public QWidget
{
    Q_OBJECT

public:
    explicit MemberDialog(QWidget *parent = nullptr);
    ~MemberDialog();

    enum Mode { Edit, Add };
    void setMode(Mode mode);

    void setImageField(const QImage &image);
    void setNameField(const QString &name);
    void setIDField(const QString &id);
    void setIndex(int index);

signals:
    void closedMemberDialog();
    void addedMember(MemberObject *);
    void editedMember(int, MemberObject *);
    void showProfileDialog();

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
