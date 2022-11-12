#ifndef HMEMBERLIST_H
#define HMEMBERLIST_H

#include <QWidget>

class HMember;
class HMemberItem;
class HMemberListPrivate;
class HMemberList : public QWidget
{
    Q_OBJECT

public:
    explicit HMemberList(QWidget *parent = nullptr);
    ~HMemberList();

    void syncMemberDB();
    void performConnection();

public slots:
    void addMember(const QImage &, const QString &, const QString &);
    void editMember(HMember *);
    // void updateMember(HMember *);
    void removeMember(const QString &);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    const QScopedPointer<HMemberListPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HMemberList)
    Q_DECLARE_PRIVATE(HMemberList)
};

#endif
