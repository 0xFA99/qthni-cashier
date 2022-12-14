#include "analysic/components/lastpurchase.h"
#include "analysic/components/lastpurchase_p.h"

#include <QVBoxLayout>

#include "widgets/items/defaultitem.h"

LastPurchasePrivate::LastPurchasePrivate(LastPurchase *q)
    : q_ptr(q)
{
}

LastPurchasePrivate::~LastPurchasePrivate() = default;

void LastPurchasePrivate::init()
{
    Q_Q(LastPurchase);

    m_layout    = new QVBoxLayout(q);

    DefaultItem *item1 = new DefaultItem(q);
    DefaultItem *item2 = new DefaultItem(q);
    DefaultItem *item3 = new DefaultItem(q);
    DefaultItem *item4 = new DefaultItem(q);
    DefaultItem *item5 = new DefaultItem(q);
    DefaultItem *item6 = new DefaultItem(q);
    DefaultItem *item7 = new DefaultItem(q);
    DefaultItem *item8 = new DefaultItem(q);
    DefaultItem *item9 = new DefaultItem(q);
    DefaultItem *item10 = new DefaultItem(q);
    DefaultItem *item11 = new DefaultItem(q);

    m_layout->addWidget(item1);
    m_layout->addWidget(item2);
    m_layout->addWidget(item3);
    m_layout->addWidget(item4);
    m_layout->addWidget(item5);
    m_layout->addWidget(item6);
    m_layout->addWidget(item7);
    m_layout->addWidget(item8);
    m_layout->addWidget(item9);
    m_layout->addWidget(item10);
    m_layout->addWidget(item11);

    m_layout->setContentsMargins(0, 0, 0, 0);
}

LastPurchase::LastPurchase(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new LastPurchasePrivate(this))
{
    d_func()->init();
}

LastPurchase::~LastPurchase() = default;