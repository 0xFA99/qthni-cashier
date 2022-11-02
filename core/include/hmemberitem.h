#ifndef HMEMBERITEM_H
#define HMEMBERITEM_H

#include <QWidget>

class HMemberItemPrivate;
class HMemberItem : public QWidget
{
    Q_OBJECT

public:
    explicit HMemberItem(QWidget *parent = nullptr);
    ~HMemberItem();

protected:
    const QScopedPointer<HMemberItemPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HMemberItem)
    Q_DECLARE_PRIVATE(HMemberItem)
};

#endif
