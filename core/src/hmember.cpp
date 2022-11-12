#include "hmember.h"
#include "hmember_p.h"

HMemberPrivate::HMemberPrivate(HMember *q)
    : q_ptr(q)
{
}

HMemberPrivate::~HMemberPrivate()
{
}

void HMemberPrivate::init()
{
    Q_Q(HMember);

    m_avatar    = QImage(":/image/images/default.png");
    m_name      = QString("Anonymous");
    m_id        = QString("0000000000");
}

HMember::HMember(QObject *parent)
    : QObject(parent)
    , d_ptr(new HMemberPrivate(this))
{
    d_func()->init();
}

HMember::~HMember()
{
}

void HMember::setAvatar(const QImage &image)
{
    Q_D(HMember);

    d->m_avatar = image;
}

QImage HMember::avatar() const
{
    Q_D(const HMember);

    return d->m_avatar;
}

void HMember::setName(const QString &name)
{
    Q_D(HMember);
    
    if (d->m_name != name)
        d->m_name = name;
}

QString HMember::name() const
{
    Q_D(const HMember);

    return d->m_name;
}

void HMember::setID(const QString &id)
{
    Q_D(HMember);

    if (d->m_id != id)
        d->m_id = id;
}

QString HMember::id() const
{
    Q_D(const HMember);

    return d->m_id;
}

void HMember::updateSlot()
{
    Q_D(HMember);

    emit updateSignal(this);
}