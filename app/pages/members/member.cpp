#include "members/member.h"
#include "members/member_p.h"

MemberPrivate::MemberPrivate(Member *q)
    : q_ptr(q)
{
}

MemberPrivate::~MemberPrivate() = default;

void MemberPrivate::init()
{
    Q_Q(Member);

    m_name      = QString("Anonymous");
    m_id        = QString("abc");
}

Member::Member(QObject *parent)
    : QObject(parent)
    , d_ptr(new MemberPrivate(this))
{
    d_func()->init();
}

Member::Member(const QString &name, const QString &id, QObject *parent)
    : QObject(parent)
    , d_ptr(new MemberPrivate(this))
{
    d_func()->init();

    setName(name);
    setID(id);
}

Member::~Member() = default;

void Member::setImage(const QImage &image)
{
    Q_D(Member);

    d->m_image = image;
}

QImage Member::image() const
{
    Q_D(const Member);

    return d->m_image;
}

void Member::setName(const QString &name)
{
    Q_D(Member);

    d->m_name = name;
}

QString Member::name() const
{
    Q_D(const Member);

    return d->m_name;
}

void Member::setID(const QString &id)
{
    Q_D(Member);

    d->m_id = id;
}

QString Member::id() const
{
    Q_D(const Member);

    return d->m_id;
}