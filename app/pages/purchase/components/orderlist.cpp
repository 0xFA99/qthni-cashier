#include "purchase/components/orderlist.h"
#include "purchase/components/orderlist_p.h"

#include <QVBoxLayout>

// Test
#include "widgets/items/extenditem.h"

OrderListPrivate::OrderListPrivate(OrderList *q)
    : q_ptr(q)
{
}

OrderListPrivate::~OrderListPrivate() = default;

void OrderListPrivate::init()
{
    Q_Q(OrderList);

    m_layout        = new QVBoxLayout(q);

    ExtendItem *item1 = new ExtendItem(q);
    ExtendItem *item2 = new ExtendItem(q);
    ExtendItem *item3 = new ExtendItem(q);
    ExtendItem *item4 = new ExtendItem(q);
    ExtendItem *item5 = new ExtendItem(q);

    m_layout->addWidget(item1);
    m_layout->addWidget(item2);
    m_layout->addWidget(item3);
    m_layout->addWidget(item4);
    m_layout->addWidget(item5);
    m_layout->addStretch(1);
    m_layout->setContentsMargins(0, 0, 0, 0);

}

OrderList::OrderList(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new OrderListPrivate(this))
{
    d_func()->init();

    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
}

OrderList::~OrderList() = default;

void OrderList::addProduct(int productIndex, int maxStock)
{
    Q_D(OrderList);

    ExtendItem *newItem = new ExtendItem(this);

    d->m_layout->addWidget(newItem);
}

void OrderList::removeProduct(int productIndex)
{
    Q_D(OrderList);

}