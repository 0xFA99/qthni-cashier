#include "widgets/items/operateitem.h"
#include "widgets/items/operateitem_p.h"
#include "members/member.h"

#include <QGridLayout>

OperateItemPrivate::OperateItemPrivate(OperateItem *q)
    : q_ptr(q)
{
}

OperateItemPrivate::~OperateItemPrivate() = default;

void OperateItemPrivate::init()
{
    Q_Q(OperateItem);

    m_layout    = new QGridLayout(q);
    m_avatar    = new QtMaterialAvatar(q);

    m_title     = new QLabel("Untitled", q);
    m_subTitle  = new QLabel("SubTitled", q);

    m_editButton    = new QtMaterialFlatButton(q);
    m_deleteButton  = new QtMaterialFlatButton(q);
    m_index         = 0;

    m_titleSize     = 12;
    m_subTitleSize  = 0;

    m_avatar->setLetter(QChar('A'));
    m_avatar->setSize(42);
    m_avatar->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);

    QFont font("Roboto", m_titleSize, QFont::Normal);
    m_title->setFont(font);
    m_title->setAlignment(Qt::AlignBottom);

    font.setPixelSize(14);
    m_subTitle->setFont(font);
    m_subTitle->setAlignment(Qt::AlignTop);

    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    m_editButton->setText("Edit");
    m_editButton->setHaloVisible(false);
    m_editButton->setRole(Material::Primary);
    m_editButton->setIcon(QtMaterialTheme::icon("image", "edit"));
    m_editButton->setSizePolicy(sizePolicy);

    m_deleteButton->setText("Delete");
    m_deleteButton->setHaloVisible(false);
    m_deleteButton->setRole(Material::Secondary);
    m_deleteButton->setIcon(QtMaterialTheme::icon("action", "delete"));
    m_deleteButton->setSizePolicy(sizePolicy);

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

    setTitleColor(QRgb(0x212121));
    setSubTitleColor(QRgb(0x616161));
}

OperateItem::OperateItem(int index, QWidget *parent)
        : QWidget(parent)
        , d_ptr(new OperateItemPrivate(this))
{
    d_func()->init();

    setIndex(index);

    setTitleColor(QRgb(0x212121));
    setSubTitleColor(QRgb(0x616161));
}

OperateItem::~OperateItem() = default;

void OperateItem::setImage(const QImage &image)
{
    Q_D(OperateItem);

    d->m_avatar->setImage(image);
}

QImage OperateItem::image() const
{
    Q_D(const OperateItem);

    return d->m_avatar->image();
}

void OperateItem::setTitle(const QString &text)
{
    Q_D(OperateItem);

    d->m_title->setText(text);
}

QString OperateItem::title() const
{
    Q_D(const OperateItem);

    return d->m_title->text();
}

void OperateItem::setTitleColor(const QColor &color)
{
    Q_D(OperateItem);

    d->m_titleColor = color;

    QPalette palette = d->m_title->palette();
    palette.setColor(d->m_title->foregroundRole(), color);
    d->m_title->setPalette(palette);
}

QColor OperateItem::titleColor() const
{
    Q_D(const OperateItem);

    return d->m_titleColor;
}

void OperateItem::setTitleSize(int size)
{
    Q_D(OperateItem);

    d->m_titleSize = size;

    QFont font = d->m_title->font();
    font.setPointSize(size);

    d->m_title->setFont(font);
}

int OperateItem::titleSize() const
{
    Q_D(const OperateItem);

    return d->m_titleSize;
}

void OperateItem::setSubTitle(const QString &text)
{
    Q_D(OperateItem);

    d->m_subTitle->setText(text);
}

QString OperateItem::subTitle() const
{
    Q_D(const OperateItem);

    return d->m_subTitle->text();
}

void OperateItem::setSubTitleColor(const QColor &color)
{
    Q_D(OperateItem);

    d->m_subTitleColor = color;

    QPalette palette = d->m_subTitle->palette();
    palette.setColor(d->m_subTitle->foregroundRole(), color);
    d->m_subTitle->setPalette(palette);
}

QColor OperateItem::subTitleColor() const
{
    Q_D(const OperateItem);

    return d->m_subTitleColor;
}

void OperateItem::setSubTitleSize(int size)
{
    Q_D(OperateItem);

    d->m_subTitleSize = size;

    QFont font = d->m_subTitle->font();
    font.setPointSize(size);

    d->m_subTitle->setFont(font);
}

int OperateItem::subTitleSize() const
{
    Q_D(const OperateItem);

    return d->m_subTitleSize;
}

void OperateItem::setIndex(int index)
{
    Q_D(OperateItem);

    d->m_index = index;

    QObject::connect(d->m_editButton, &QPushButton::clicked, [=]() {
        editItem(d->m_index);
    });

    QObject::connect(d->m_deleteButton, &QPushButton::clicked, [=]() {
        deleteItem(d->m_index);
    });
}

int OperateItem::getIndex() const
{
    Q_D(const OperateItem);

    return d->m_index;
}