#include "hmaterialprofile.h"
#include "hmaterialprofile_p.h"

#include <QGridLayout>
#include <QSizePolicy>

#include "hmaterialtheme.h"

HMaterialProfilePrivate::HMaterialProfilePrivate(HMaterialProfile *q)
    : q_ptr(q)
{
}

HMaterialProfilePrivate::~HMaterialProfilePrivate()
{
}

void HMaterialProfilePrivate::init()
{
    Q_Q(HMaterialProfile);

    m_layout        = new QGridLayout(q);
    m_avatar        = new HMaterialAvatar(q);
    m_name          = new HMaterialLabel("Anonymous", q);
    m_id            = new HMaterialLabel("abc", q);
    m_editButton    = new HMaterialFlatButton("Edit", q);

    m_avatar->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    m_editButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);

    m_layout->addWidget(m_avatar, 0, 0, 2, 1);
    m_layout->addWidget(m_name, 0, 1);
    m_layout->addWidget(m_id, 1, 1);
    m_layout->addWidget(m_editButton, 0, 2, 2, 1);
    m_layout->setSpacing(10);

    m_editButton->setRole(HMaterial::Secondary);
    m_editButton->setBackgroundMode(Qt::OpaqueMode);
    m_editButton->setHaloVisible(false);
}

HMaterialProfile::HMaterialProfile(QWidget *parent)
    : HMaterialFrame(parent)
    , d_ptr(new HMaterialProfilePrivate(this))
{
    d_func()->init();
}

HMaterialProfile::HMaterialProfile(const QString &name, const QString &id, QWidget *parent)
    : HMaterialFrame(parent)
    , d_ptr(new HMaterialProfilePrivate(this))
{
    d_func()->init();

    setName(name);
    setId(id);
}

HMaterialProfile::~HMaterialProfile()
{
}

void HMaterialProfile::setImage(const QImage &image)
{
    Q_D(HMaterialProfile);

    d->m_avatar->setImage(image);
}

void HMaterialProfile::setName(const QString &name)
{
    Q_D(HMaterialProfile);

    d->m_name->setText(name);

    d->m_avatar->setLetter(QChar(name.at(0)));
}

void HMaterialProfile::setId(const QString &id)
{
    Q_D(HMaterialProfile);

    d->m_id->setText(id);
}
