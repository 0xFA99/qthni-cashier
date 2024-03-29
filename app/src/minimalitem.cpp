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
    m_subTitle    = new QLabel("Extra Title", q);

    QFont font("Roboto", 12, QFont::Normal);
    m_title->setFont(font);
    m_subTitle->setFont(font);

    m_avatar->setLetter(QChar('A'));
    m_avatar->setSize(42);
    m_avatar->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);

    m_subTitle->setAlignment(Qt::AlignCenter | Qt::AlignRight);

    m_layout->addWidget(m_avatar);
    m_layout->addWidget(m_title);
    m_layout->addWidget(m_subTitle, Qt::AlignRight);
    m_layout->setContentsMargins(0, 0, 0, 0);
}

MinimalItem::MinimalItem(ISubject &subject, QWidget *parent)
    : QWidget(parent)
    , d_ptr(new MinimalItemPrivate(this))
    , m_subject(subject)
{
    d_func()->init();

    setMinimumHeight(54);
    this->m_subject.Attach(this);
}

MinimalItem::~MinimalItem() = default;

void MinimalItem::Update(const QImage& image, const QString& title, const QString& subtitle)
{
    setImage(image);
    setTitle(title);
}

// void MinimalItem::extraItem(int stock)
void MinimalItem::ExtraUpdate(const QUuid &tagUUID, int memPrice, int cusPrice, int point, int stock)
{
    Q_D(MinimalItem);

    d->m_subTitle->setText(QString::number(stock));
}

void MinimalItem::setImage(const QImage &image)
{
    Q_D(MinimalItem);

    d->m_avatar->setImage(image);
}

void MinimalItem::setTitle(const QString &title)
{
    Q_D(MinimalItem);

    d->m_title->setText(title);
}

void MinimalItem::setTitleColor(const QColor &color)
{
    Q_D(MinimalItem);

    QPalette palette = d->m_title->palette();
    palette.setColor(d->m_title->foregroundRole(), color);
    d->m_title->setPalette(palette);
}

void MinimalItem::setSubTitle(const QString &subtitle)
{
    Q_D(MinimalItem);

    d->m_subTitle->setText(subtitle);
}

void MinimalItem::setSubTitleColor(const QColor &color)
{
    Q_D(MinimalItem);

    QPalette palette = d->m_subTitle->palette();
    palette.setColor(d->m_subTitle->foregroundRole(), color);
    d->m_subTitle->setPalette(palette);
}

void
MinimalItem::removeFromSubject()
{
    m_subject.Detach(this);
}