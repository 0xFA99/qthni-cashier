#include "purchase/components/orderlist.h"
#include "purchase/components/orderlist_p.h"

#include <QVBoxLayout>

#include "products/ProductObject.h"
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

void OrderList::addProduct(ExtendItem *item)
{
    Q_D(OrderList);

    item->setParent(this);
    d->m_layout->insertWidget(d->m_layout->count() - 1, item);
}

void OrderList::removeProduct(QUuid uuid)
{
    Q_D(OrderList);

    ExtendItem *item;
    for (int i = 0; i < d->m_layout->count(); i++) {
        QLayoutItem *litem = d->m_layout->itemAt(i);

        if ((item = dynamic_cast<ExtendItem *>(litem->widget()))) {

            if (item->uuid() == uuid) {
                item->deleteLater();
                break;
            }
        }
    }
}
