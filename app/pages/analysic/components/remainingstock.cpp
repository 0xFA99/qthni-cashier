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

    m_layout->addStretch(1);
    m_layout->setContentsMargins(0, 0, 0, 0);
}

RemainingStock::RemainingStock(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new RemainingStockPrivate(this))
{
    d_func()->init();
}

RemainingStock::~RemainingStock() = default;

void RemainingStock::addRemaindItem(MinimalItem *item)
{
    Q_D(RemainingStock);

    item->setParent(this);

    d->m_layout->insertWidget(d->m_layout->count() - 1, item);
}

void RemainingStock::deleteRemaindItem(int index)
{
    Q_D(RemainingStock);

    MinimalItem *item;
    for (int i = 0; i < d->m_layout->count(); i++) {
        QLayoutItem *litem = d->m_layout->itemAt(i);
        if ((item = dynamic_cast<MinimalItem *>(litem->widget()))) {
            /*
            if (item->index() == index)
                item->deleteLater();
            */
        }
    }
}