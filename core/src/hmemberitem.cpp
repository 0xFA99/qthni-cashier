#include "hmemberitem.h"
#include "hmemberitem_p.h"

#include <QGridLayout>

HMemberItemPrivate::HMemberItemPrivate(HMemberItem *q)
    : q_ptr(q)
{
}

HMemberItemPrivate::~HMemberItemPrivate() = default;

void HMemberItemPrivate::init()
{
    Q_Q(HMemberItem);

    m_layout        = new QGridLayout(q);
    m_avatar        = new HMaterialAvatar(QImage(":/images/images/default.png"), q);
    m_name          = new HMaterialLabel("Anonymous", q);
    m_id            = new HMaterialLabel("xxxxxxxxx", q);
    m_editButton    = new HMaterialFlatButton("\uE626", q);
    m_removeButton  = new HMaterialFlatButton("\uE61F", q);

    m_avatar->setSize(48);
    m_avatar->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);

    m_name->setAlignment(Qt::AlignBottom);

    m_id->setTextColor(QColor("#657ef8"));
    m_id->setAlignment(Qt::AlignTop);
    m_id->setFontSize(12);

    QFont font("iconfont", 15, QFont::Medium);

    m_editButton->setFont(font);
    m_editButton->setForegroundColor(QColor("#8592a3"));
    m_editButton->setFixedWidth(m_editButton->sizeHint().height());
    m_editButton->setHaloVisible(false);
    m_editButton->setRippleStyle(HMaterial::NoRipple);

    m_removeButton->setFont(font);
    m_removeButton->setForegroundColor(QColor("#ff6273"));
    m_removeButton->setFixedWidth(m_removeButton->sizeHint().height());
    m_removeButton->setHaloVisible(false);
    m_removeButton->setRippleStyle(HMaterial::NoRipple);
    QObject::connect(
            m_removeButton, &QPushButton::clicked,
            q, &HMemberItem::removeSlot);
    QObject::connect(
            m_editButton, &QPushButton::clicked,
            q, &HMemberItem::editSlot);

    m_layout->addWidget(m_avatar, 0, 0, 2, 1);
    m_layout->addWidget(m_name, 0, 1, 1, 1);
    m_layout->addWidget(m_id, 1, 1, 1, 1);
    m_layout->addWidget(m_editButton, 0, 2, 2, 1);
    m_layout->addWidget(m_removeButton, 0, 3, 2, 1);
    m_layout->setContentsMargins(0, 0, 0, 0);
}

HMemberItem::HMemberItem(HMember *member, QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HMemberItemPrivate(this))
{
    d_func()->init();

    setMemberObject(member);
}

HMemberItem::~HMemberItem() = default;

void HMemberItem::setMemberObject(HMember *member)
{
    Q_D(HMemberItem);

    d->m_member = member;
    d->m_avatar->setImage(member->avatar());
    d->m_name->setText(member->name());
    d->m_id->setText(member->id());

    QObject::connect(d->m_member, &HMember::updateSignal, this, &HMemberItem::updateMember);
}

void HMemberItem::removeSlot()
{
    Q_D(HMemberItem);

    emit removeItem(d->m_id->text());
}

void HMemberItem::editSlot()
{
    Q_D(HMemberItem);

    emit editItem(d->m_member);
}

QString HMemberItem::getID() const
{
    Q_D(const HMemberItem);

    return d->m_id->text();
}

void HMemberItem::updateMember(HMember *member)
{
    Q_D(HMemberItem);

    d->m_avatar->setImage(member->avatar());
    d->m_name->setText(member->name());
    d->m_id->setText(member->id());
}