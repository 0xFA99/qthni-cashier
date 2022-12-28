#ifndef QTHNI_PURCHASEPAGE_P_H
#define QTHNI_PURCHASEPAGE_P_H

#include "widgets/frametitle.h"
#include "purchase/components/resultlist.h"
#include "purchase/components/orderlist.h"
#include "purchase/components/pricewidgets.h"
#include "purchase/components/searchfield.h"

#include "products/ProductObjectManager.h"

#include <QScrollArea>
#include <QLocale>
#include <QFrame>

class QGridLayout;
class QVBoxLayout;
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

    QFrame                  *m_leftFrame;
    QFrame                  *m_rightFrame;

    QGridLayout             *m_leftFrameLayout;
    QVBoxLayout             *m_rightFrameLayout;

    SearchField             *m_searchField;

    FrameTitle              *m_searchFieldFrame;
    FrameTitle              *m_orderFrame;
    FrameTitle              *m_totalFrame;

    QScrollArea             *m_orderScrollArea;

    ResultList              *m_resultList;
    QScrollArea             *m_resultScroll;

    OrderList               *m_orderList;
    ProductObjectManager    *m_productManager;

    PriceWidget             *m_priceWidget;
    QLocale                 m_locale;
};

#endif //QTHNI_PURCHASEPAGE_P_H
