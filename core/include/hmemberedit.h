#ifndef HMEMBEREDIT_H
#define HMEMBEREDIT_H

#include <QWidget>

class HMember;
class HMemberEditPrivate;
class HMemberEdit : public QWidget
{
    Q_OBJECT

public:
    explicit HMemberEdit(QWidget *parent = nullptr);
    ~HMemberEdit();

    enum Mode { AddMode, EditMode };

    void setTargetMember(HMember *);

    void setMode(Mode mode);
    void editMode();
    void addMode();

public slots:
    void addSlot();
    void editSlot();

signals:
    void hideDialog();
    void addSignal(const QImage &, const QString &, const QString &);

protected:
    const QScopedPointer<HMemberEditPrivate> d_ptr;

private:
    void setEmptyField();

    Q_DISABLE_COPY(HMemberEdit)
    Q_DECLARE_PRIVATE(HMemberEdit)
};

#endif
