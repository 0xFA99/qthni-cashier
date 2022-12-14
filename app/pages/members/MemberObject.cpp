#include "members/MemberObject.h"
#include "members/MemberObject_p.h"

MemberObjectPrivate::MemberObjectPrivate(MemberObject *q)
    : q_ptr(q)
{
}

MemberObjectPrivate::~MemberObjectPrivate() = default;

void MemberObjectPrivate::init()
{
    Q_Q(MemberObject);
    m_image         = QImage(":/images/images/profiles/defaultimage.png");
    m_name          = QString("Anonymous");
    m_id            = QString("000000");

    m_observerList  = QVector<IObserver *>();
}

MemberObject::MemberObject(QObject *parent)
    : QObject(parent)
    , d_ptr(new MemberObjectPrivate(this))
{
    d_func()->init();
}

MemberObject::~MemberObject() = default;

void MemberObject::setUUID(QUuid uuid) // Copy UUID
{
    Q_D(MemberObject);

    d->m_uuid = uuid;
}

QUuid MemberObject::uuid() const
{
    Q_D(const MemberObject);

    return d->m_uuid;
}

void MemberObject::setImage(const QImage &image)
{
    Q_D(MemberObject);

    d->m_image = image;
}

QImage MemberObject::image() const
{
    Q_D(const MemberObject);

    return d->m_image;
}

void MemberObject::setName(const QString &name)
{
    Q_D(MemberObject);

    d->m_name = name;
}

QString MemberObject::name() const
{
    Q_D(const MemberObject);

    return d->m_name;
}

void MemberObject::setID(const QString &id)
{
    Q_D(MemberObject);

    d->m_id = id;
}

QString MemberObject::id() const
{
    Q_D(const MemberObject);

    return d->m_id;
}

void MemberObject::Attach(IObserver *observer)
{
    Q_D(MemberObject);

    d->m_observerList.push_back(observer);
}

void MemberObject::Detach(IObserver *observer)
{
    Q_D(MemberObject);

    d->m_observerList.removeOne(observer);
}

void MemberObject::Update()
{
    Q_D(MemberObject);

    QVector<IObserver *>::iterator iterator = d->m_observerList.begin();
    while (iterator != d->m_observerList.end()) {
        (*iterator)->Update(image(), name(), id());
        ++iterator;
    }
}

void
MemberObject::editMember(MemberObject& member)
{
    setImage(member.image());
    setName(member.name());
    setID(member.id());
}