#include "hmemberedit.h"
#include "hmemberedit_p.h"

#include <QGridLayout>

HMemberEditPrivate::HMemberEditPrivate(HMemberEdit *q)
    : q_ptr(q)
{
}

HMemberEditPrivate::~HMemberEditPrivate()
{
}

void HMemberEditPrivate::init()
{
    Q_Q(HMemberEdit);

    m_layout        = new QGridLayout(q);

    m_avatar        = new HMaterialAvatar(QImage(":/images/images/default.png"), q);
    m_name          = new HMaterialTextField(q);
    m_id            = new HMaterialTextField(q);
    m_avatarButton  = new HMaterialFlatButton(q);
    m_cancelButton  = new HMaterialFlatButton(q);
    m_submitButton  = new HMaterialFlatButton(q);

    m_layout->addWidget(m_avatar, 0, 0, 1, 2);
    m_layout->addWidget(m_name, 2, 0, 1, 2);
    m_layout->addWidget(m_id, 3, 0, 1, 2);
    m_layout->addWidget(m_avatarButton, 0, 1, 1, 2);
    m_layout->addWidget(m_cancelButton, 4, 0, 1, 1);
    m_layout->addWidget(m_submitButton, 4, 1, 1, 1);
}

HMemberEdit::HMemberEdit(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HMemberEditPrivate(this))
{
    d_func()->init();
}

HMemberEdit::~HMemberEdit()
{
}

void HMemberEdit::setImage(const QImage &image)
{
    Q_D(HMemberEdit);

    d->m_avatar->setImage(image);
}

void HMemberEdit::setName(const QString &name)
{
    Q_D(HMemberEdit);

    d->m_name->setText(name);
}

void HMemberEdit::setID(const QString &id)
{
    Q_D(HMemberEdit);

    d->m_id->setText(id);
}


