#include "widgets/items/searchitem.h"
#include "widgets/items/searchitem_p.h"

#include <QVBoxLayout>
#include <QLabel>


SearchItemPrivate::SearchItemPrivate(SearchItem *q)
    : q_ptr(q)
{
}

SearchItemPrivate::~SearchItemPrivate() = default;

void SearchItemPrivate::init()
{
    Q_Q(SearchItem);

    m_layout        = new QVBoxLayout(q);
    m_avatar        = new QtMaterialImage(QImage(":/images/images/profiles/defaultimage.png"), q);
    m_title         = new QLabel("Untitled", q);
    m_subTitle      = new QLabel("0", q);
    m_button        = new QtMaterialFlatButton("TAMBAH PESANAN", q);
    m_hasAdded      = false;
    m_locale        = QLocale("id_ID");

    m_avatar->setSize(80);
    m_avatar->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    m_title->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    m_subTitle->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    QFont font("Roboto", 12, QFont::Normal);
    m_title->setFont(font);
    font.setPointSize(10);
    m_subTitle->setFont(font);

    m_button->setHaloVisible(false);
    m_button->setBackgroundMode(Qt::OpaqueMode);
    m_button->setRole(Material::Primary);
    m_button->setOverlayColor(Material::TintedOverlay);
    m_button->setRippleStyle(Material::NoRipple);
    m_button->setRole(Material::Primary);

    m_layout->addWidget(m_avatar, Qt::AlignHCenter);
    m_layout->addWidget(m_title);
    m_layout->addWidget(m_subTitle);
    m_layout->addWidget(m_button);

    QObject::connect(m_button, &QPushButton::clicked, [q]() { q->changeStat(); });
}

SearchItem::SearchItem(ISubject &subject, QWidget *parent)
    : QWidget(parent)
    , d_ptr(new SearchItemPrivate(this))
    , m_subject(subject)
{
    d_func()->init();
    // setMinimumSize(160, 160);
    setFixedSize(160, 200);

    this->m_subject.Attach(this);
}

SearchItem::~SearchItem() = default;

void SearchItem::changeStat()
{
    Q_D(SearchItem);

    if (!d->m_hasAdded) {
        d->m_button->setText("HAPUS PESANAN");
        d->m_button->setRole(Material::Secondary);
        d->m_hasAdded = true;

        addedToOrder(uuid());
    } else {
        d->m_button->setText("TAMBAH PESANAN");
        d->m_button->setRole(Material::Primary);
        d->m_hasAdded = false;

        deleteToOrder(uuid());
    }
}

void SearchItem::Update(const QImage &image, const QString &title, const QString &subTitle)
{
    setImage(image);
    setTitle(title);
    setSubTitle(subTitle);
}

void SearchItem::ExtraUpdate(const QUuid &tag, int memPrice, int cusPrice, int point, int stock)
{
    Q_D(SearchItem);

    d->m_subTitle->setText("Rp " + d->m_locale.toString(cusPrice));
}

void SearchItem::setImage(const QImage &image)
{
    Q_D(SearchItem);

    d->m_avatar->setImage(image);
}

void SearchItem::setTitle(const QString &title)
{
    Q_D(SearchItem);

    QFontMetrics metrics(d->m_title->font());
    QString elidedText = metrics.elidedText(title, Qt::ElideRight, d->m_title->width());
    d->m_title->setText(elidedText);
}

void SearchItem::setTitleColor(const QColor &color)
{
    Q_D(SearchItem);

    QPalette palette = d->m_title->palette();
    palette.setColor(d->m_title->foregroundRole(), color);
    d->m_title->setPalette(palette);
}

void SearchItem::setSubTitle(const QString &subTitle)
{
    Q_D(SearchItem);

    d->m_subTitle->setText(subTitle);
}

void SearchItem::setSubTitleColor(const QColor &color)
{
    Q_D(SearchItem);

    QPalette palette = d->m_subTitle->palette();
    palette.setColor(d->m_subTitle->foregroundRole(), color);
    d->m_subTitle->setPalette(palette);
}

void
SearchItem::removeFromSubject()
{
    m_subject.Detach(this);
}

void SearchItem::setUUID(const QUuid &uuid)
{
    Q_D(SearchItem);

    d->m_uuid = uuid;
}

QUuid SearchItem::uuid() const
{
    Q_D(const SearchItem);

    return d->m_uuid;
}