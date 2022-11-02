#include "hmemberitem.h"
#include "hmemberitem_p.h"

#include <QGridLayout>

HMemberItemPrivate::HMemberItemPrivate(HMemberItem *q)
    : q_ptr(q)
{
}

HMemberItemPrivate::~HMemberItemPrivate()
{
}

void HMemberItemPrivate::init()
{
    Q_Q(HMemberItem);

    m_layout        = new QGridLayout(q);

    m_avatar        = new HMaterialAvatar(QImage(":/images/images/default.png"), q);
    m_name          = new HMaterialLabel("Anonymouse", q);
    m_id            = new HMaterialLabel("xxxxxxxxxx", q);
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

    m_layout->addWidget(m_avatar, 0, 0, 2, 1);
    m_layout->addWidget(m_name, 0, 1, 1, 1);
    m_layout->addWidget(m_id, 1, 1, 1, 1);
    m_layout->addWidget(m_editButton, 0, 2, 2, 1);
    m_layout->addWidget(m_removeButton, 0, 3, 2, 1);
    m_layout->setContentsMargins(0, 0, 0, 0);
}

HMemberItem::HMemberItem(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HMemberItemPrivate(this))
{
    d_func()->init();
}

HMemberItem::~HMemberItem()
{
}
