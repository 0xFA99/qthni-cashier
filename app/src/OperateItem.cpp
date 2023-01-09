#include "widgets/items/OperateItem.h"
#include "widgets/items/OperateItem_p.h"

#include <QGridLayout>
#include <QLabel>

OperateItemPrivate::OperateItemPrivate(OperateItem *q)
    : q_ptr(q)
{
}

OperateItemPrivate::~OperateItemPrivate() = default;

void OperateItemPrivate::init()
{
    Q_Q(OperateItem);

    m_layout        = new QGridLayout(q);
    m_avatar        = new QtMaterialAvatar(QImage(":/images/images/profiles/defaultimage.png"), q);
    m_title         = new QLabel("Untitled", q);
    m_subTitle      = new QLabel("Subtitled", q);
    m_editButton    = new QtMaterialFlatButton("Edit", q);
    m_deleteButton  = new QtMaterialFlatButton("Delete", q);
    m_locale        = QLocale("id_ID");

    m_avatar->setSize(42);
    m_avatar->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);

    QFont font("Roboto", 12, QFont::Normal);
    m_title->setFont(font);
    m_title->setAlignment(Qt::AlignBottom);
    q->setTitleColor(QRgb(0x212121));

    font.setPixelSize(14);
    m_subTitle->setFont(font);
    m_subTitle->setAlignment(Qt::AlignTop);
    q->setSubTitleColor(QRgb(0x616161));

    QSizePolicy buttonPolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    m_editButton->setHaloVisible(false);
    m_editButton->setRole(Material::Primary);
    m_editButton->setOverlayStyle(Material::TintedOverlay);
    m_editButton->setIcon(QtMaterialTheme::icon("image", "edit"));
    m_editButton->setSizePolicy(buttonPolicy);

    m_deleteButton->setHaloVisible(false);
    m_deleteButton->setRole(Material::Secondary);
    m_deleteButton->setRippleStyle(Material::NoRipple);
    m_deleteButton->setOverlayStyle(Material::TintedOverlay);
    m_deleteButton->setIcon(QtMaterialTheme::icon("action", "delete"));
    m_deleteButton->setSizePolicy(buttonPolicy);

    m_layout->addWidget(m_avatar, 0, 0, 2, 1);
    m_layout->addWidget(m_title, 0, 1, 1, 1);
    m_layout->addWidget(m_subTitle, 1, 1, 1, 1);
    m_layout->addWidget(m_editButton, 0, 2, 2, 1);
    m_layout->addWidget(m_deleteButton, 0, 3, 2, 1);
    m_layout->setContentsMargins(0, 10, 0, 0);
}

OperateItem::OperateItem(ISubject &subject, QWidget *parent)
    : QWidget(parent)
    , d_ptr(new OperateItemPrivate(this))
    , m_subject(subject)
{
    d_func()->init();

    this->m_subject.Attach(this);
}

OperateItem::~OperateItem() = default;

void OperateItem::Update(const QImage &image, const QString &title, const QString &subtitle)
{
    setImage(image);
    setTitle(title);
    setSubTitle(subtitle);
}

void
OperateItem::ExtraUpdate(const QUuid &tag, int memPrice, int cusPrice, int point, int stock)
{
    Q_D(OperateItem);

    d->m_subTitle->setText("Rp " + d->m_locale.toString(cusPrice));
}

void OperateItem::setImage(const QImage &image)
{
    Q_D(OperateItem);

    d->m_avatar->setImage(image);
}

void OperateItem::setTitle(const QString &title)
{
    Q_D(OperateItem);

    d->m_title->setText(title);
}

void OperateItem::setTitleColor(const QColor &color)
{
    Q_D(OperateItem);

    QPalette palette = d->m_title->palette();
    palette.setColor(d->m_title->foregroundRole(), color);
    d->m_title->setPalette(palette);
}

void OperateItem::setSubTitle(const QString &subtitle)
{
    Q_D(OperateItem);

    d->m_subTitle->setText(subtitle);
}

void OperateItem::setSubTitleColor(const QColor &color)
{
    Q_D(OperateItem);

    QPalette palette = d->m_subTitle->palette();
    palette.setColor(d->m_subTitle->foregroundRole(), color);
    d->m_subTitle->setPalette(palette);
}

void
OperateItem::removeFromSubject()
{
    m_subject.Detach(this);
}

void
OperateItem::setUUID(QUuid uuid)
{
    Q_D(OperateItem);

    d->m_uuid = uuid;

    QObject::connect(d->m_editButton, &QPushButton::clicked, [=]() { s_editButton(this->uuid()); });
    QObject::connect(d->m_deleteButton, &QPushButton::clicked, [=]() { s_deleteButton(this->uuid()); });
}

QUuid
OperateItem::uuid() const
{
    Q_D(const OperateItem);

    return d->m_uuid;
}