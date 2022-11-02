#ifndef HORDERPRICE_PRIVATE_H
#define HORDERPRICE_PRIVATE_H

#include "hmaterialcurrency.h"
#include "hmaterialflatbutton.h"

class QGridLayout;

class HOrderPrice;
class HOrderPricePrivate
{
    Q_DISABLE_COPY(HOrderPricePrivate)
    Q_DECLARE_PUBLIC(HOrderPrice)

public:
    HOrderPricePrivate(HOrderPrice *q);
    ~HOrderPricePrivate();

    void init();

    HOrderPrice *const  q_ptr;
    QGridLayout         *m_layout;
    HMaterialCurrency      *m_subTotal;
    HMaterialCurrency      *m_discount;
    HMaterialCurrency      *m_total;
    HMaterialFlatButton     *m_button;
};

#endif
