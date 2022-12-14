#include "analysic/components/remainingstock.h"
#include "analysic/components/remainingstock_p.h"

#include <QVBoxLayout>

#include "widgets/items/minimalitem.h"

RemainingStockPrivate::RemainingStockPrivate(RemainingStock *q)
    : q_ptr(q)
{
}

RemainingStockPrivate::~RemainingStockPrivate() = default;

void RemainingStockPrivate::init()
{
    Q_Q(RemainingStock);

    m_layout    = new QVBoxLayout(q);

    MinimalItem *item1 = new MinimalItem(q);
    MinimalItem *item2 = new MinimalItem(q);
    MinimalItem *item3 = new MinimalItem(q);
    MinimalItem *item4 = new MinimalItem(q);
    MinimalItem *item5 = new MinimalItem(q);
    MinimalItem *item6 = new MinimalItem(q);
    MinimalItem *item7 = new MinimalItem(q);
    MinimalItem *item8 = new MinimalItem(q);
    MinimalItem *item9 = new MinimalItem(q);
    MinimalItem *item10 = new MinimalItem(q);

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
    m_layout->setContentsMargins(0, 0, 0, 0);
}

RemainingStock::RemainingStock(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new RemainingStockPrivate(this))
{
    d_func()->init();
}

RemainingStock::~RemainingStock() = default;