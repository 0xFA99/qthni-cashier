#ifndef HMATERIALORDERPRICE_PRIVATE_H
#define HMATERIALORDERPRICE_PRIVATE_H

#include "hmateriallabel.h"
#include "hmaterialcurrency.h"
#include "hmaterialflatbutton.h"
#include "hmaterialsperator.h"

class QGridLayout;

class HMaterialOrderPrice;
class HMaterialOrderPricePrivate
{
    Q_DISABLE_COPY(HMaterialOrderPricePrivate)
    Q_DECLARE_PUBLIC(HMaterialOrderPrice)

public:
    HMaterialOrderPricePrivate(HMaterialOrderPrice *q);
    ~HMaterialOrderPricePrivate();

    void init();

    HMaterialOrderPrice *const  q_ptr;
    
    QGridLayout                 *m_layout;

    HMaterialLabel              *m_subTotalLabel;
    HMaterialLabel              *m_discountLabel;
    HMaterialLabel              *m_totalLabel;

    HMaterialCurrency           *m_subTotal;
    HMaterialCurrency           *m_discount;
    HMaterialCurrency           *m_total;

    HMaterialSperator           *m_sperator;

    HMaterialFlatButton         *m_button;
};

#endif
