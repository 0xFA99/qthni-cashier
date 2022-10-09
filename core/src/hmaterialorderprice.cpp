#include "hmaterialorderprice.h"
#include "hmaterialorderprice_p.h"

#include <QGridLayout>

#include "hmaterialtheme.h"

HMaterialOrderPricePrivate::HMaterialOrderPricePrivate(HMaterialOrderPrice *q)
    : q_ptr(q)
{
}

HMaterialOrderPricePrivate::~HMaterialOrderPricePrivate()
{
}

void HMaterialOrderPricePrivate::init()
{
    Q_Q(HMaterialOrderPrice);

    m_layout        = new QGridLayout(q);
    m_subTotalLabel = new HMaterialLabel("Sub Total", q);
    m_discountLabel = new HMaterialLabel("Discount", q);
    m_totalLabel    = new HMaterialLabel("Total", q);
    m_subTotal      = new HMaterialCurrency(0, q);
    m_discount      = new HMaterialCurrency(0, q);
    m_total         = new HMaterialCurrency(0, q);
    m_button        = new HMaterialFlatButton("Purchase", q);
    m_sperator      = new HMaterialSperator(q);

    m_sperator->setSperatorStyle(Qt::DashLine);

    m_button->setRole(HMaterial::Primary);
    m_button->setHaloVisible(false);
    m_button->setBackgroundMode(Qt::OpaqueMode);

    m_layout->addWidget(m_subTotalLabel, 0, 0);
    m_layout->addWidget(m_discountLabel, 1, 0);
    m_layout->addWidget(m_totalLabel, 3, 0);
    
    m_layout->addWidget(m_subTotal, 0, 1);
    m_layout->addWidget(m_discount, 1, 1);
    m_layout->addWidget(m_sperator, 2, 0, 1, 2);
    m_layout->addWidget(m_total, 3, 1);

    m_layout->setRowStretch(m_layout->rowCount(), 1);
    
    m_layout->addWidget(m_button, 5, 0, 1, 2);
}

HMaterialOrderPrice::HMaterialOrderPrice(QWidget *parent)
    : HMaterialFrame(parent)
    , d_ptr(new HMaterialOrderPricePrivate(this))
{
    d_func()->init();
}

HMaterialOrderPrice::~HMaterialOrderPrice()
{
}

void HMaterialOrderPrice::increaseSubTotal(int value)
{
    Q_D(HMaterialOrderPrice);

    d->m_subTotal->increaseMoney(value);
    
    d->m_total->increaseMoney(value);
}

void HMaterialOrderPrice::decreaseSubTotal(int value)
{
    Q_D(HMaterialOrderPrice);

    d->m_subTotal->decreaseMoney(value);

    d->m_total->decreaseMoney(value);
}

int HMaterialOrderPrice::subTotal() const
{
    Q_D(const HMaterialOrderPrice);

    return d->m_subTotal->money();
}

void HMaterialOrderPrice::increaseDiscount(int value)
{
    Q_D(HMaterialOrderPrice);

    d->m_discount->increaseMoney(value);

    d->m_total->decreaseMoney(value);
}

void HMaterialOrderPrice::decreaseDiscount(int value)
{
    Q_D(HMaterialOrderPrice);

    d->m_discount->decreaseMoney(value);

    d->m_total->increaseMoney(value);
}

int HMaterialOrderPrice::discount() const
{
    Q_D(const HMaterialOrderPrice);

    return d->m_discount->money();
}

int HMaterialOrderPrice::total() const
{
    Q_D(const HMaterialOrderPrice);

    return d->m_total->money();
}
