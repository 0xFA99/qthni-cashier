#ifndef HMEMBERLISTITEM_H
#define HMEMBERLISTITEM_H

#include <QWidget>

class HMemberList;
class HMemberListItem : public QWidget
{
    Q_OBJECT

public:
    HMemberListItem(QWidget *parent = nullptr);
    ~HMemberListItem();

protected:
    const QScopedPointer<HMemberListItemPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HMemberListItem)
    Q_DECLARE_PRIVATE(HMemberListItem)
};

#endif
