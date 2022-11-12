#include "hproductview.h"
#include "hproductview_p.h"

#include <QVBoxLayout>

#include "hproductitem.h"

HProductViewPrivate::HProductViewPrivate(HProductView *q)
    : q_ptr(q)
{
}

HProductViewPrivate::~HProductViewPrivate()
{
}

void HProductViewPrivate::init()
{
    Q_Q(HProductView);

    m_layout    = new QVBoxLayout(q);

    m_layout->addStretch(1);
    m_layout->setContentsMargins(0, 0, 0, 0);
}

HProductView::HProductView(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HProductViewPrivate(this))
{
    d_func()->init();

    setStyleSheet("QWidget { background-color: white; };");
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
}

HProductView::~HProductView()
{
}

void HProductView::addItem(HProductItem *item)
{
    Q_D(HProductView);

    d->m_layout->insertWidget(d->m_layout->count() - 1, item);
}

void HProductView::removeItem(const QString &name)
{
    Q_D(HProductView);

    HProductItem *product;
    for (int i = 0; i < d->m_layout->count(); i++) {
        QLayoutItem *item = d->m_layout->itemAt(i);
        if ((product = dynamic_cast<HProductItem *>(item->widget()))) {
            if (product->name() == name) {
                d->m_layout->removeItem(reinterpret_cast<QLayoutItem *>(item));
                delete product;
            }
        }
    }
}