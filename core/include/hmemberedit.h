#ifndef HMEMBEREDIT_H
#define HMEMBEREDIT_H

#include <QWidget>

class HMemberEditPrivate;
class HMemberEdit : public QWidget
{
    Q_OBJECT

public:
    explicit HMemberEdit(QWidget *parent = nullptr);
    ~HMemberEdit();

    void setImage(const QImage &image);

    void setName(const QString &name);

    void setID(const QString &id);

protected:
    const QScopedPointer<HMemberEditPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HMemberEdit)
    Q_DECLARE_PRIVATE(HMemberEdit)
};

#endif
