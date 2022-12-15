#include "products/components/productlist.h"
#include "products/components/productlist_p.h"

#include <QVBoxLayout>

#include "widgets/items/operateitem.h"
#include "products/product.h"

ProductListPrivate::ProductListPrivate(ProductList *q)
    : q_ptr(q)
{
}

ProductListPrivate::~ProductListPrivate() = default;

void ProductListPrivate::init()
{
    Q_Q(ProductList);

    m_layout    = new QVBoxLayout(q);

    m_layout->addStretch(1);
    m_layout->setContentsMargins(0, 0, 0, 0);
}

ProductList::ProductList(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new ProductListPrivate(this))
{
    d_func()->init();

    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
}

ProductList::~ProductList() = default;

void ProductList::addProductItem(OperateItem *item)
{
    Q_D(ProductList);

    item->setParent(this);
    d->m_layout->insertWidget(d->m_layout->count() - 1, item);
}

void ProductList::updateProductItem(int index, Product *product)
{
    Q_D(ProductList);

    QLayoutItem *item = d->m_layout->itemAt(index);
    auto pro = dynamic_cast<OperateItem *>(item->widget());
    pro->setTitle(product->name());
    pro->setSubTitle(QString::number(product->price()));
}

void ProductList::deleteProductItem(int index)
{
    Q_D(ProductList);

    OperateItem *item;
    for (int i = 0; i < d->m_layout->count(); i++) {
        QLayoutItem *litem = d->m_layout->itemAt(i);

        if (i > index && (item = dynamic_cast<OperateItem *>(litem->widget()))) {
            item->setIndex(item->getIndex() - 1);
        }
    }

    QLayoutItem *litem = d->m_layout->itemAt(index);
    if ((item = dynamic_cast<OperateItem *>(litem->widget()))) {
        delete item;
    }
}