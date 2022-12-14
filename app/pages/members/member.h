#ifndef QTHNI_MEMBER_H
#define QTHNI_MEMBER_H

#include <QObject>

class MemberPrivate;
class Member : public QObject
{
public:
    explicit Member(QObject *parent = nullptr);
    Member(const QString &, const QString &, QObject *parent = nullptr);
    ~Member();

    void setName(const QString &name);
    [[nodiscard]] QString name() const;

    void setID(const QString &id);
    [[nodiscard]] QString id() const;

protected:
    const QScopedPointer<MemberPrivate> d_ptr;

private:
    Q_DISABLE_COPY(Member)
    Q_DECLARE_PRIVATE(Member)
};

#endif //QTHNI_MEMBER_H
