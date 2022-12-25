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

void OrderList::addProduct(int productIndex)
{
    Q_D(OrderList);

    ProductObject* product = d->m_productManager->getProductObject(productIndex);

    auto *item = new ExtendItem(this);
    item->setImage(product->image());
    item->setTitle(product->name());
    item->setStock(product->stock());
    item->setIndex(productIndex);

    product->Attach(item);

    d->m_layout->insertWidget(d->m_layout->count() - 1, item);
}

void OrderList::removeProduct(int productIndex)
{
    Q_D(OrderList);

    ExtendItem *item;
    QLayoutItem *litem = d->m_layout->itemAt(productIndex);
    if ((item = dynamic_cast<ExtendItem *>(litem->widget()))) {
        item->deleteLater();
    }
}

void OrderList::addManager(ProductObjectManager *manager)
{
    Q_D(OrderList);

    d->m_productManager = manager;
}