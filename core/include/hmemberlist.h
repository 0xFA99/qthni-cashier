#ifndef HMEMBERLIST_H
#define HMEMBERLIST_H

#include <QWidget>

class HMemberListItem;
class HMemberListPrivate;
class HMemberList : public QWidget
{
    Q_OBJECT

public:
    explicit HMemberList(QWidget *parent = nullptr);
    ~HMemberList();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    const QScopedPointer<HMemberListPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HMemberList)
    Q_DECLARE_PRIVATE(HMemberList)
};

#endif
