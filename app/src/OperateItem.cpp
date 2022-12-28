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
    m_index         = 0;

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
    m_deleteButton->setOverlayStyle(Material::TintedOverlay);
    m_deleteButton->setIcon(QtMaterialTheme::icon("action", "delete"));
    m_deleteButton->setSizePolicy(buttonPolicy);

    QObject::connect(m_editButton, &QPushButton::clicked, [=]() { q->s_editButton(m_index); });
    QObject::connect(m_deleteButton, &QPushButton::clicked, [=]() { q->s_deleteButton(m_index); });

    m_layout->addWidget(m_avatar, 0, 0, 2, 1);
    m_layout->addWidget(m_title, 0, 1, 1, 1);
    m_layout->addWidget(m_subTitle, 1, 1, 1, 1);
    m_layout->addWidget(m_editButton, 0, 2, 2, 1);
    m_layout->addWidget(m_deleteButton, 0, 3, 2, 1);
    m_layout->setContentsMargins(0, 10, 0, 0);
}

OperateItem::OperateItem(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new OperateItemPrivate(this))
{
    d_func()->init();
}

OperateItem::~OperateItem() = default;

void OperateItem::Update(const QImage &image, const QString &title, const QString &subtitle)
{
    setImage(image);
    setTitle(title);
    setSubTitle(subtitle);
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

void OperateItem::setIndex(int index)
{
    Q_D(OperateItem);

    d->m_index = index;
}

int OperateItem::index() const
{
    Q_D(const OperateItem);

    return d->m_index;
}