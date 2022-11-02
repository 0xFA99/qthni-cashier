#ifndef HMEMBER_H
#define HMEMBER_H

#include <QObject>

class HMemberPrivate;
class HMember : public QObject
{
    Q_OBJECT

public:
    explicit HMember(QObject *parent = nullptr);
    ~HMember();

    void setAvatar(const QImage &image);
    QImage avatar() const;

    void setName(const QString &name);
    QString name() const;

    void setID(const QString &id);
    QString id() const;

protected:
    const QScopedPointer<HMemberPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HMember)
    Q_DECLARE_PRIVATE(HMember)
};

#endif
