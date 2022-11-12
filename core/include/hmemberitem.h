#ifndef HMEMBERITEM_H
#define HMEMBERITEM_H

#include <QWidget>

#include "hmember.h"

class HMemberItemPrivate;
class HMemberItem : public QWidget
{
    Q_OBJECT

public:
    explicit HMemberItem(HMember *member, QWidget *parent = nullptr);
    ~HMemberItem();
    
    void setMemberObject(HMember *member);

    QString getID() const;

public slots:
    void removeSlot();
    void editSlot();

    void updateMember(HMember *);

signals:
    void removeItem(const QString &id);
    void editItem(HMember *);
    // void updateItem(HMember *);

    // void editMember(HMember *);

protected:
    const QScopedPointer<HMemberItemPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HMemberItem)
    Q_DECLARE_PRIVATE(HMemberItem)
};

#endif
