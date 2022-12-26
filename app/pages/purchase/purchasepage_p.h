#ifndef QTHNI_PURCHASEPAGE_P_H
#define QTHNI_PURCHASEPAGE_P_H

#include "widgets/frametitle.h"
#include "purchase/components/resultlist.h"
#include "purchase/components/orderlist.h"
#include "purchase/components/pricewidgets.h"

#include "products/ProductObjectManager.h"

#include <QScrollArea>

class QHBoxLayout;

class PurchasePage;
class PurchasePagePrivate
{
    Q_DISABLE_COPY(PurchasePagePrivate)
    Q_DECLARE_PUBLIC(PurchasePage)

public:
    explicit PurchasePagePrivate(PurchasePage *q);
    ~PurchasePagePrivate();

    void init();

    PurchasePage *const     q_ptr;
    QHBoxLayout             *m_layout;

    // Search Result
    FrameTitle              *m_searchFieldFrame;
    FrameTitle              *m_orderFrame;
    FrameTitle              *m_totalFrame;

    QScrollArea             *m_orderScrollArea;

    ResultList              *m_resultList;
    QScrollArea             *m_resultScroll;

    OrderList               *m_orderList;
    ProductObjectManager    *m_productManager;

    PriceWidget             *m_priceWidget;
};

#endif //QTHNI_PURCHASEPAGE_P_H
