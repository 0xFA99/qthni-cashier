#include "widgets/items/defaultitem.h"
#include "widgets/items/defaultitem_p.h"

#include <QGridLayout>

DefaultItemPrivate::DefaultItemPrivate(DefaultItem *q)
    : q_ptr(q)
{
}

DefaultItemPrivate::~DefaultItemPrivate() = default;

void DefaultItemPrivate::init()
{
    Q_Q(DefaultItem);

    m_layout        = new QGridLayout(q);
    m_avatar        = new QtMaterialAvatar(q);

    m_title         = new QLabel("Untitled", q);
    m_subTitle      = new QLabel("Subtitled", q);
    m_extraTitle    = new QLabel("Extra Titled", q);

    m_titleColor        = QColor(Qt::black);
    m_subTitleColor     = QColor(Qt::black);
    m_extraTitleColor   = QColor(Qt::black);

    m_titleSize         = 12;
    m_subTitleSize      = 10;
    m_extraTitleSize    = 12;

    m_hasImage          = false;

    QString firstLetter = m_title->text();
    m_avatar->setLetter(QChar(firstLetter.at(0)));
    m_avatar->setSize(42);
    m_avatar->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);

    QFont font("Roboto", m_titleSize, QFont::Normal);
    m_title->setFont(font);
    m_title->setAlignment(Qt::AlignBottom);

    m_extraTitle->setFont(font);
    m_extraTitle->setAlignment(Qt::AlignCenter);

    font.setPixelSize(14);
    m_subTitle->setFont(font);
    m_subTitle->setAlignment(Qt::AlignTop);

    m_layout->addWidget(m_avatar, 0, 0, 2, 1);
    m_layout->addWidget(m_title, 0, 1, 1, 1);
    m_layout->addWidget(m_subTitle, 1, 1, 1, 1);
    m_layout->addWidget(m_extraTitle, 0, 2, 2, 1, Qt::AlignRight);
    m_layout->setContentsMargins(0, 10, 0, 0);
}

DefaultItem::DefaultItem(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new DefaultItemPrivate(this))
{
    d_func()->init();

    setTitleColor(QRgb(0x212121));
    setSubTitleColor(QRgb(0x616161));
    setExtraTitleColor(QRgb(0x212121));
}

DefaultItem::~DefaultItem() = default;

void DefaultItem::setTitle(const QString &text)
{
    Q_D(DefaultItem);

    if (text == "")
        d->m_title->setText("Untitled");

    d->m_title->setText(text);

    if (!d->m_hasImage) {
        QString firstLetter = d->m_title->text();
        d->m_avatar->setLetter(QChar(firstLetter.at(0)));
    }
}

QString DefaultItem::title() const
{
    Q_D(const DefaultItem);

    return d->m_title->text();
}

void DefaultItem::setTitleColor(const QColor &color)
{
    Q_D(DefaultItem);

    d->m_titleColor = color;

    QPalette palette = d->m_title->palette();
    palette.setColor(d->m_title->foregroundRole(), color);
    d->m_title->setPalette(palette);
}

QColor DefaultItem::titleColor() const
{
    Q_D(const DefaultItem);

    return d->m_titleColor;
}

void DefaultItem::setTitleSize(int size)
{
    Q_D(DefaultItem);

    d->m_titleSize = size;

    QFont font = d->m_title->font();
    font.setPointSize(size);

    d->m_title->setFont(font);
}

int DefaultItem::titleSize() const
{
    Q_D(const DefaultItem);

    return d->m_titleSize;
}

void DefaultItem::setSubTitle(const QString &text)
{
    Q_D(const DefaultItem);

    if (text == "")
        d->m_subTitle->setText("SubUntitled");

    d->m_subTitle->setText(text);
}

QString DefaultItem::subTitle() const
{
    Q_D(const DefaultItem);

    return d->m_subTitle->text();
}

void DefaultItem::setSubTitleColor(const QColor &color)
{
    Q_D(DefaultItem);

    d->m_subTitleColor = color;

    QPalette palette = d->m_subTitle->palette();
    palette.setColor(d->m_subTitle->foregroundRole(), color);
    d->m_subTitle->setPalette(palette);
}

QColor DefaultItem::subTitleColor() const
{
    Q_D(const DefaultItem);

    return d->m_subTitleColor;
}

void DefaultItem::setSubTitleSize(int size)
{
    Q_D(DefaultItem);

    d->m_subTitleSize = size;

    QFont font = d->m_subTitle->font();
    font.setPointSize(size);

    d->m_subTitle->setFont(font);
}

int DefaultItem::subTitleSize() const
{
    Q_D(const DefaultItem);

    return d->m_subTitleSize;
}

void DefaultItem::setExtraTitle(const QString &text)
{
    Q_D(DefaultItem);

    d->m_extraTitle->setText(text);
}

QString DefaultItem::extraTitle() const
{
    Q_D(const DefaultItem);

    return d->m_extraTitle->text();
}

void DefaultItem::setExtraTitleColor(const QColor &color)
{
    Q_D(DefaultItem);

    d->m_extraTitleColor = color;

    QPalette palette = d->m_extraTitle->palette();
    palette.setColor(d->m_extraTitle->foregroundRole(), color);
    d->m_extraTitle->setPalette(palette);
}

QColor DefaultItem::extraTitleColor() const
{
    Q_D(const DefaultItem);

    return d->m_extraTitleColor;
}

void DefaultItem::setExtraTitleSize(int size)
{
    Q_D(DefaultItem);

    d->m_extraTitleSize = size;

    QFont font = d->m_extraTitle->font();
    font.setPointSize(size);

    d->m_extraTitle->setFont(font);
}

int DefaultItem::extraTitleSize() const
{
    Q_D(const DefaultItem);

    return d->m_extraTitleSize;
}

void DefaultItem::setImage(const QImage &image)
{
    Q_D(DefaultItem);

    d->m_hasImage = true;

    d->m_avatar->setImage(image);
}

void DefaultItem::removeImage()
{
    Q_D(DefaultItem);

    if (d->m_hasImage) {
        QString firstLetter = d->m_title->text();
        d->m_avatar->setLetter(QChar(firstLetter.at(0)));
    }
}