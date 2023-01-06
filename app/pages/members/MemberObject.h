#ifndef QTHNI_MEMBEROBJECT_H
#define QTHNI_MEMBEROBJECT_H

#include "interfaces/IObserver.h"
#include "interfaces/ISubject.h"

#include <QObject>

class MemberObjectPrivate;
class MemberObject : public QObject, public ISubject
{
    Q_OBJECT

public:
    explicit MemberObject(QObject *parent = nullptr);
    ~MemberObject();

    void editMember(MemberObject&);

    void setUUID(QUuid);
    [[nodiscard]] QUuid uuid() const;

    void setImage(const QImage &image);
    [[nodiscard]] QImage image() const;

    void setName(const QString &name);
    [[nodiscard]] QString name() const;

    void setID(const QString &id);
    [[nodiscard]] QString id() const;

    void Attach(IObserver *observer) override;
    void Detach(IObserver *observer) override;
    void Update() override;

protected:
    const QScopedPointer<MemberObjectPrivate> d_ptr;

private:
    Q_DISABLE_COPY(MemberObject)
    Q_DECLARE_PRIVATE(MemberObject)
};


#endif //QTHNI_MEMBEROBJECT_H
