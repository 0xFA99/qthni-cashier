#ifndef HMEMBERVIEW_H
#define HMEMBERVIEW_H

#include <QWidget>

class HMember;
class HMemberItem;
class HMemberViewPrivate;
class HMemberView : public QWidget
{
    Q_OBJECT

public:
    explicit HMemberView(QWidget *parent = nullptr);
    ~HMemberView();

public slots:
    void addItem(HMemberItem *);
    void removeItem(const QString &id);

protected:
    const QScopedPointer<HMemberViewPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HMemberView)
    Q_DECLARE_PRIVATE(HMemberView)
};

#endif
