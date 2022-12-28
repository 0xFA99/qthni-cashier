#include "purchase/purchasepage.h"
#include "purchase/purchasepage_p.h"

#include <QHBoxLayout>

#include "purchase/components/orderlist.h"
#include "qtmaterial/components/qtmaterialscrollbar.h"
#include "widgets/items/extenditem.h"

#include "products/ProductObjectManager.h"

// TEST
#include "purchase/components/searchfield.h"

PurchasePagePrivate::PurchasePagePrivate(PurchasePage *q)
    : q_ptr(q)
{
}

PurchasePagePrivate::~PurchasePagePrivate() = default;

void PurchasePagePrivate::init()
{
    Q_Q(PurchasePage);

    m_layout            = new QHBoxLayout(q);

    m_leftFrame         = new QFrame(q);
    m_rightFrame        = new QFrame(q);

    m_leftFrameLayout   = new QGridLayout(m_leftFrame);
    m_rightFrameLayout  = new QVBoxLayout(m_rightFrame);

    m_searchField       = new SearchField(q);
    m_searchFieldFrame  = new FrameTitle("Hasil Pencarian", q);
    m_orderScrollArea   = new QScrollArea(q);
    m_orderFrame        = new FrameTitle("Daftar Pesanan");
    m_totalFrame        = new FrameTitle("Total Harga");
    m_priceWidget       = new PriceWidget(q);

    m_resultList        = new ResultList(q);
    m_resultScroll      = new QScrollArea(q);

    m_locale            = QLocale("id_ID");

    m_totalFrame->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    m_resultScroll->setWidget(m_resultList);
    m_resultScroll->setWidgetResizable(true);
    m_resultScroll->setStyleSheet("background-color: transparent");
    m_resultScroll->setVerticalScrollBar(new QtMaterialScrollBar(m_resultScroll));

    m_orderList         = new OrderList(q);

    m_orderScrollArea->setWidget(m_orderList);
    m_orderScrollArea->setWidgetResizable(true);
    m_orderScrollArea->setStyleSheet("background-color: transparent;");
    m_orderScrollArea->setVerticalScrollBar(new QtMaterialScrollBar(m_orderScrollArea));
    m_orderScrollArea->setHorizontalScrollBar(new QtMaterialScrollBar(m_orderScrollArea));

    m_searchFieldFrame->addChildWidget(m_resultScroll);
    m_orderFrame->addChildWidget(m_orderScrollArea);
    m_totalFrame->addChildWidget(m_priceWidget);

    m_orderFrame->setParent(m_leftFrame);
    m_totalFrame->setParent(m_rightFrame);

    QSizePolicy leftFramePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    QSizePolicy rightFramePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    leftFramePolicy.setHorizontalStretch(3);
    rightFramePolicy.setHorizontalStretch(1);

    m_leftFrame->setSizePolicy(leftFramePolicy);
    m_rightFrame->setSizePolicy(rightFramePolicy);

    m_leftFrameLayout->setSpacing(16);
    m_rightFrameLayout->setSpacing(16);

    m_leftFrameLayout->addWidget(m_searchField);
    m_leftFrameLayout->addWidget(m_searchFieldFrame);

    m_rightFrameLayout->addWidget(m_orderFrame);
    m_rightFrameLayout->addWidget(m_totalFrame);

    m_layout->addWidget(m_leftFrame);
    m_layout->addWidget(m_rightFrame);
}

PurchasePage::PurchasePage(ProductObjectManager *manager, QWidget *parent)
    : QWidget(parent)
    , d_ptr(new PurchasePagePrivate(this))
{
    d_func()->init();

    addProductManager(manager);
}

PurchasePage::~PurchasePage() = default;

void PurchasePage::deletedShowProduct(int index)
{
    Q_D(PurchasePage);

    d->m_resultList->deleteProductObjectShow(index);
}

void PurchasePage::addProductManager(ProductObjectManager *manager)
{
    Q_D(PurchasePage);

    d->m_productManager = manager;
}

void PurchasePage::addOrderItem(int index)
{
    Q_D(PurchasePage);

    ProductObject *product = d->m_productManager->getProductObject(index);

    auto *item = new ExtendItem;
    item->setImage(product->image());
    item->setTitle(product->name());
    item->setPrice(product->price());
    item->setStock(product->stock());
    item->setIndex(index);
    product->Attach(item);

    QObject::connect(item, &ExtendItem::changeSubPrice, d->m_priceWidget, &PriceWidget::changeSubTotal);

    // First init
    d->m_priceWidget->changeSubTotal(index, product->price());

    d->m_orderList->addProduct(item);
}

void PurchasePage::removeOrderItem(int index)
{
    Q_D(PurchasePage);

    d->m_priceWidget->deleteItemPrice(index);
    d->m_orderList->removeProduct(index);
}

void PurchasePage::addedShowProduct(int index)
{
    Q_D(PurchasePage);

    ProductObject *product = d->m_productManager->getProductObject(index);

    auto item = new SearchItem(this);
    item->setImage(product->image());
    item->setTitle(product->name());
    item->setSubTitle(QString("Rp " + d->m_locale.toString(product->price())));
    item->setIndex(index);

    product->Attach(item);

    QObject::connect(item, &SearchItem::addedToOrder, this, &PurchasePage::addOrderItem);
    QObject::connect(item, &SearchItem::deleteToOrder, this, &PurchasePage::removeOrderItem);

    d->m_resultList->addProductObjectShow(item);
}