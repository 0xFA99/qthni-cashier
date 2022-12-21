#include "widgets/items/searchitem.h"
#include "widgets/items/searchitem_p.h"

#include <QVBoxLayout>
#include <QLocale>

SearchItemPrivate::SearchItemPrivate(SearchItem *q)
    : q_ptr(q)
{
}

SearchItemPrivate::~SearchItemPrivate() = default;

void SearchItemPrivate::init()
{
    Q_Q(SearchItem);

    m_layout        = new QVBoxLayout(q);
    m_avatar        = new QtMaterialAvatar(q);
    m_title         = new QLabel("Untitled", q);
    m_price         = new QLabel("0", q);
    m_button        = new QtMaterialFlatButton("BUY NOW", q);
    m_hasAdded      = false;

    m_avatar->setSize(72);
    m_avatar->setLetter(QChar('U'));
    m_avatar->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    m_title->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    m_price->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    QFont font("Roboto", 12, QFont::Normal);
    m_title->setFont(font);
    font.setPointSize(10);
    m_price->setFont(font);

    m_button->setRippleStyle(Material::NoRipple);
    m_button->setRole(Material::Primary);

    m_layout->addWidget(m_avatar);
    m_layout->addWidget(m_title);
    m_layout->addWidget(m_price);
    m_layout->addWidget(m_button);

    QObject::connect(m_button, &QPushButton::clicked, [q]() {
        q->changeStat();
    });
}

SearchItem::SearchItem(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new SearchItemPrivate(this))
{
    d_func()->init();
    setMinimumSize(160, 200);
}

SearchItem::~SearchItem() = default;

void SearchItem::changeStat()
{
    Q_D(SearchItem);

    if (!d->m_hasAdded) {
        d->m_button->setText("HAPUS PESANAN");
        d->m_button->setRole(Material::Secondary);
        d->m_hasAdded = true;
    } else {
        d->m_button->setText("TAMBAH PESANAN");
        d->m_button->setRole(Material::Primary);
        d->m_hasAdded = false;
    }
}

void SearchItem::setImage(const QImage &image)
{
    Q_D(SearchItem);

    d->m_avatar->setImage(image);
}

QImage SearchItem::image() const
{
    Q_D(const SearchItem);

    return d->m_avatar->image();
}

void SearchItem::setTitle(const QString &text)
{
    Q_D(SearchItem);

    d->m_title->setText(text);
}

QString SearchItem::title() const
{
    Q_D(const SearchItem);

    return d->m_title->text();
}

void SearchItem::setPrice(int price)
{
    Q_D(SearchItem);

    QLocale indo("id_ID");

    d->m_price->setText("Rp " + indo.toString(price));
}

int SearchItem::price() const
{
    Q_D(const SearchItem);

    QString price = d->m_price->text().split(" ")[1];
    price.replace('.', "");

    return price.toInt();
}

void SearchItem::setStock(int stock)
{
    Q_D(SearchItem);

    d->m_stock = stock;
}

int SearchItem::stock() const
{
    Q_D(const SearchItem);

    return d->m_stock;
}