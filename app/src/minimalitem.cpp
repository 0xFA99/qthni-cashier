#include "widgets/items/minimalitem.h"
#include "widgets/items/minimalitem_p.h"

#include <QHBoxLayout>

MinimalItemPrivate::MinimalItemPrivate(MinimalItem *q)
    : q_ptr(q)
{
}

MinimalItemPrivate::~MinimalItemPrivate() = default;

void MinimalItemPrivate::init()
{
    Q_Q(MinimalItem);

    m_layout        = new QHBoxLayout(q);
    m_avatar        = new QtMaterialAvatar(q);
    m_title         = new QLabel("Untitled", q);
    m_extraTitle    = new QLabel("Extra Title", q);

    QFont font("Roboto", 12, QFont::Normal);
    m_title->setFont(font);
    m_extraTitle->setFont(font);

    m_avatar->setLetter(QChar('A'));
    m_avatar->setSize(42);
    m_avatar->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);

    m_extraTitle->setAlignment(Qt::AlignCenter | Qt::AlignRight);

    m_layout->addWidget(m_avatar);
    m_layout->addWidget(m_title);
    m_layout->addWidget(m_extraTitle, Qt::AlignRight);
    m_layout->setContentsMargins(0, 0, 0, 0);
}

MinimalItem::MinimalItem(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new MinimalItemPrivate(this))
{
    d_func()->init();

    setMinimumHeight(54);
}

MinimalItem::~MinimalItem() = default;

void MinimalItem::setTitle(const QString &title)
{
    Q_D(MinimalItem);

    d->m_title->setText(title);
}

QString MinimalItem::title() const
{
    Q_D(const MinimalItem);

    return d->m_title->text();
}

void MinimalItem::setExtraTitle(const QString &extra)
{
    Q_D(MinimalItem);

    d->m_extraTitle->setText(extra);
}

QString MinimalItem::extraTitle() const
{
    Q_D(const MinimalItem);

    return d->m_extraTitle->text();
}

void MinimalItem::setAvatarImage(const QImage &image)
{
    Q_D(MinimalItem);

    d->m_avatar->setImage(image);
}