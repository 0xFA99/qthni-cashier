#include "hmembermodel.h"
#include "hmembermodel_p.h"

#include <QGridLayout>

HMemberModelPrivate::HMemberModelPrivate(HMemberModel *q)
    : q_ptr(q)
{
}

HMemberModelPrivate::~HMemberModelPrivate()
{
}

void HMemberModelPrivate::init()
{
    Q_Q(HMemberModel);

    m_image = QImage(":/images/images/default.png");
    m_name  = QString("Anonymous");
    m_id    = QString("xxxxxxxxxx");

    m_layout        = new QGridLayout(q);
    m_avatar        = new HMaterialAvatar(m_image, q);
    m_nameLabel     = new HMaterialLabel(m_name, q);
    m_idLabel       = new HMaterialLabel(m_id, q);
    m_editButton    = new HMaterialFlatButton("\uE626", q);
    m_removeButton  = new HMaterialFlatButton("\uE61F", q);

    // Avatar Configuration
    m_avatar->setSize(48);
    m_avatar->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);

    // Name Label Configuration
    m_nameLabel->setAlignment(Qt::AlignBottom);

    // ID Label Configuration
    m_idLabel->setTextColor(QColor("#657ef8"));
    m_idLabel->setAlignment(Qt::AlignTop);
    m_idLabel->setFontSize(12);

    // Edit & Remove Button Configuration
    QFont font("iconfont", 15, QFont::Medium);
    int cr = m_editButton->sizeHint().height() / 2;

    m_editButton->setFont(font);
    m_editButton->setForegroundColor(QColor("#8592a3"));
    m_editButton->setFixedWidth(cr);
    m_editButton->setHaloVisible(false);
    m_editButton->setRippleStyle(HMaterial::NoRipple);

    m_removeButton->setFont(font);
    m_removeButton->setForegroundColor(QColor("#ff6273"));
    m_removeButton->setFixedWidth(cr);
    m_removeButton->setHaloVisible(false);
    m_removeButton->setRippleStyle(HMaterial::NoRipple);

    // Layout Configuration
    m_layout->addWidget(m_avatar, 0, 0, 2, 1);
    m_layout->addWidget(m_nameLabel, 0, 1, 1, 1);
    m_layout->addWidget(m_idLabel, 1, 1, 1, 1);
    m_layout->addWidget(m_editButton, 0, 2, 2, 1);
    m_layout->addWidget(m_removeButton, 0, 3, 2, 1);
    m_layout->setContentsMargins(0, 0, 0, 0);

    // Connection Widget
    QObject::connect(m_editButton, &QPushButton::clicked, q, &HMemberModel::editSlot);
    QObject::connect(m_removeButton, &QPushButton::clicked, q, &HMemberModel::removeSlot);
}

HMemberModel::HMemberModel(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HMemberModelPrivate(this))
{
    d_func()->init();
}

HMemberModel::~HMemberModel()
{
}

void HMemberModel::setImage(const QImage &image)
{
    Q_D(HMemberModel);

    d->m_image = image;
    d->m_avatar->setImage(image);
}

QImage HMemberModel::getImage() const
{
    Q_D(const HMemberModel);

    return d->m_image;
}

void HMemberModel::setName(const QString &name)
{
    Q_D(HMemberModel);

    d->m_name = name;
    d->m_nameLabel->setText(name);
}

QString HMemberModel::getName() const
{
    Q_D(const HMemberModel);

    return d->m_name;
}

void HMemberModel::setID(const QString &id)
{
    Q_D(HMemberModel);

    d->m_id = id;
    d->m_idLabel->setText(id);
}

QString HMemberModel::getID() const
{
    Q_D(const HMemberModel);

    return d->m_id;
}

void HMemberModel::editSlot()
{
    emit editMember();
}

void HMemberModel::removeSlot()
{
    emit removeMember();
}
