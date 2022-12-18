#include "widgets/items/searchitem.h"
#include "widgets/items/searchitem_p.h"

#include <QVBoxLayout>

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

    QFont font("Roboto", 10, QFont::Medium);
    m_title->setFont(font);
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

    if (d->m_hasAdded) {
        d->m_button->setText("BUY NOW");
        d->m_button->setRole(Material::Primary);
        d->m_hasAdded = false;
    } else {
        d->m_button->setText("DELETE FROM LIST");
        d->m_button->setRole(Material::Secondary);
        d->m_hasAdded = true;
    }
}