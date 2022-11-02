#ifndef HPURCHASEPAGE_PRIVATE_H
#define HPURCHASEPAGE_PRIVATE_H

#include "horderlist.h"
#include "horderprice.h"
#include "hmaterialsearch.h"
#include "hproductresult.h"

class QHBoxLayout;

class HPurchasePage;
class HPurchasePagePrivate
{
    Q_DISABLE_COPY(HPurchasePagePrivate)
    Q_DECLARE_PUBLIC(HPurchasePage)

public:
    HPurchasePagePrivate(HPurchasePage *q);
    ~HPurchasePagePrivate();

    void init();

    HPurchasePage *const    q_ptr;
    QHBoxLayout             *m_layout;
    HOrderList              *m_orderList;
    HOrderPrice             *m_orderPrice;
    HMaterialSearch         *m_searchField;
    HProductResult          *m_productSearch;
};

#endif
