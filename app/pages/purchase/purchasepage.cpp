#include "purchase/purchasepage.h"
#include "purchase/purchasepage_p.h"

#include <QHBoxLayout>
#include <QFrame>

#include "purchase/components/orderlist.h"
#include "qtmaterial/components/qtmaterialscrollbar.h"

#include "products/productmanager.h"

// TEST
#include "purchase/components/searchfield.h"
#include "purchase/components/pricewidgets.h"

PurchasePagePrivate::PurchasePagePrivate(PurchasePage *q)
    : q_ptr(q)
{
}

PurchasePagePrivate::~PurchasePagePrivate() = default;

void PurchasePagePrivate::init()
{
    Q_Q(PurchasePage);

    m_layout    = new QHBoxLayout(q);

    m_searchFieldFrame  = new FrameTitle("Hasil Pencarian", q);
    m_orderScrollArea   = new QScrollArea(q);
    m_orderFrame        = new FrameTitle("Daftar Pesanan");
    m_totalFrame        = new FrameTitle("Total Harga");

    m_totalFrame->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    SearchField *searchField = new SearchField(q);

    m_resultList        = new ResultList(q);
    m_resultScroll      = new QScrollArea(q);

    m_resultScroll->setWidget(m_resultList);
    m_resultScroll->setWidgetResizable(true);
    m_resultScroll->setStyleSheet("background-color: transparent");
    m_resultScroll->setVerticalScrollBar(new QtMaterialScrollBar(m_resultScroll));

    // Temp Widgets
    QWidget *temp2 = new QWidget(q);
    PriceWidget *priceWidget = new PriceWidget(q);

    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    temp2->setSizePolicy(sizePolicy);

    // TEST
    OrderList *order1 = new OrderList(q);

    m_orderScrollArea->setWidget(order1);
    m_orderScrollArea->setWidgetResizable(true);
    m_orderScrollArea->setStyleSheet("background-color: transparent;");
    m_orderScrollArea->setVerticalScrollBar(new QtMaterialScrollBar(m_orderScrollArea));
    m_orderScrollArea->setHorizontalScrollBar(new QtMaterialScrollBar(m_orderScrollArea));

    m_searchFieldFrame->addChildWidget(m_resultScroll);
    m_orderFrame->addChildWidget(m_orderScrollArea);
    m_totalFrame->addChildWidget(priceWidget);

    QFrame *leftFrame = new QFrame(q);
    QFrame *rightFrame = new QFrame(q);

    m_orderFrame->setParent(leftFrame);
    m_totalFrame->setParent(rightFrame);

    QSizePolicy leftFramePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    QSizePolicy rightFramePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    leftFramePolicy.setHorizontalStretch(3);
    rightFramePolicy.setHorizontalStretch(1);

    leftFrame->setSizePolicy(leftFramePolicy);
    rightFrame->setSizePolicy(rightFramePolicy);

    QGridLayout *leftFrameLayout = new QGridLayout(leftFrame);
    QVBoxLayout *rightFrameLayout = new QVBoxLayout(rightFrame);

    leftFrameLayout->setSpacing(16);
    rightFrameLayout->setSpacing(16);

    leftFrameLayout->addWidget(searchField);
    leftFrameLayout->addWidget(m_searchFieldFrame);

    rightFrameLayout->addWidget(m_orderFrame);
    rightFrameLayout->addWidget(m_totalFrame);

    m_layout->addWidget(leftFrame);
    m_layout->addWidget(rightFrame);
}

PurchasePage::PurchasePage(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new PurchasePagePrivate(this))
{
    d_func()->init();
}

PurchasePage::~PurchasePage() = default;

void PurchasePage::addedShowProduct(Product *product)
{
    Q_D(PurchasePage);

    d->m_resultList->addProductShow(product);
}

void PurchasePage::updatedShowProduct(int index, Product *product)
{
    Q_D(PurchasePage);

    d->m_resultList->updateProductShow(index, product);
}