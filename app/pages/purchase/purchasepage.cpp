#include "purchase/purchasepage.h"
#include "purchase/purchasepage_p.h"

#include <QHBoxLayout>

#include "purchase/components/orderlist.h"
#include "qtmaterial/components/qtmaterialscrollbar.h"
#include "widgets/items/extenditem.h"
#include "widgets/items/finalwidget.h"
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
    m_memberFrame       = new FrameTitle("Member");
    m_priceWidget       = new PriceWidget(q);

    m_resultList        = new ResultList(q);
    m_resultScroll      = new QScrollArea(q);

    m_purchaseOrderDialog   = new QtMaterialDialog;
    m_purchaseOrder         = new PurchaseOrderDialog(q);

    m_chooseMemberDialog    = new QtMaterialDialog;
    m_chooseMemberWidget    = new ChooseMemberWidget(q);
    m_memberNameWidget      = new MemberNameWidget(q);

    m_locale            = QLocale("id_ID");

    auto chooseMemLayout = new QVBoxLayout;
    m_chooseMemberDialog->setParent(q);
    m_chooseMemberDialog->setWindowLayout(chooseMemLayout);

    chooseMemLayout->addWidget(m_chooseMemberWidget);

    auto dialogLayout = new QVBoxLayout;
    dialogLayout->setContentsMargins(0, 0, 0, 0);
    m_purchaseOrderDialog->setParent(q);
    m_purchaseOrderDialog->setWindowLayout(dialogLayout);

    dialogLayout->addWidget(m_purchaseOrder);

    QObject::connect(m_priceWidget, &PriceWidget::s_submitButton, m_purchaseOrderDialog, &QtMaterialDialog::showDialog);
    QObject::connect(m_purchaseOrder, &PurchaseOrderDialog::hideDialog, m_purchaseOrderDialog, &QtMaterialDialog::hideDialog);

    QObject::connect(m_priceWidget, &PriceWidget::updateSubTotal, m_purchaseOrder, &PurchaseOrderDialog::updateSubTotal);

    m_totalFrame->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    m_resultScroll->setWidget(m_resultList);
    m_resultScroll->setWidgetResizable(true);
    m_resultScroll->setStyleSheet("background-color: transparent");
    m_resultScroll->setVerticalScrollBar(new QtMaterialScrollBar(m_resultScroll));

    m_orderList         = new OrderList(q);

    // QObject::connect(m_orderList, &OrderList::deleteItem, m_purchaseOrder, &PurchaseOrderDialog::deleteItem);

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

    m_memberFrame->setParent(m_rightFrame);
    m_memberFrame->addChildWidget(m_memberNameWidget);

    QObject::connect(m_memberNameWidget, &MemberNameWidget::memberChoosen, m_priceWidget, &PriceWidget::memberChoosen);
    QObject::connect(m_memberNameWidget, &MemberNameWidget::changeMember, m_chooseMemberDialog, &QtMaterialDialog::showDialog);
    QObject::connect(m_chooseMemberWidget, &ChooseMemberWidget::hideChooseMember, [=](const QString &name) {
        m_chooseMemberDialog->hideDialog();
        m_memberNameWidget->changeMemberName(name);
    });

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
    m_rightFrameLayout->addWidget(m_memberFrame);
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

void PurchasePage::deletedShowProduct(QUuid uuid)
{
    Q_D(PurchasePage);

    d->m_resultList->deleteProductObjectShow(uuid);
}

void PurchasePage::addProductManager(ProductObjectManager *manager)
{
    Q_D(PurchasePage);

    d->m_productManager = manager;
}

void PurchasePage::addOrderItem(QUuid uuid)
{
    Q_D(PurchasePage);

    ProductObject *product = d->m_productManager->getProductObject(uuid);

    auto *item = new ExtendItem(*product);
    item->setImage(product->image());
    item->setTitle(product->name());
    item->setMemberPrice(product->memberPrice());
    item->setCustomerPrice(product->customerPrice());
    item->setStock(product->stock());
    item->setUUID(product->uuid());

    // product->Attach(item);

    QObject::connect(item, &ExtendItem::changeSubPrice, d->m_priceWidget, &PriceWidget::changeSubTotal);
    QObject::connect(item, &ExtendItem::changeMemPrice, d->m_priceWidget, &PriceWidget::changeMemTotal);

    // First init
    d->m_priceWidget->changeSubTotal(product->uuid(), product->customerPrice());
    d->m_priceWidget->changeMemTotal(product->uuid(), product->memberPrice());

    d->m_orderList->addProduct(item);

    // OrderPrice Dialog
    /*
    auto orderDialogItem = new PurchaseOrderDialogItem;
    orderDialogItem->setImage(product->image());
    orderDialogItem->setName(product->name());
    orderDialogItem->setPrice(product->customerPrice());
    orderDialogItem->setDiscount(product->memberPrice());
    orderDialogItem->setUUID(product->uuid());
    orderDialogItem->setQuantity(1);
    */

    auto finalItemWidget = new FinalWidget(*product);
    finalItemWidget->setImage(product->image());
    finalItemWidget->setTitle(product->name());
    finalItemWidget->setSubTitle("Rp " + d->m_locale.toString(product->customerPrice()));
    finalItemWidget->changeAmount(1);
    finalItemWidget->changeTotal("", product->customerPrice());
    finalItemWidget->setUUID(product->uuid());

    // product->Attach(finalItemWidget);

    QObject::connect(item, &ExtendItem::updateAmount, finalItemWidget, &FinalWidget::changeAmount);
    QObject::connect(item, &ExtendItem::changeSubPrice, finalItemWidget, &FinalWidget::changeTotal);

    d->m_purchaseOrder->addItem(finalItemWidget);
}

void PurchasePage::removeOrderItem(QUuid uuid)
{
    Q_D(PurchasePage);

    d->m_priceWidget->deleteItemPrice(uuid);
    d->m_orderList->removeProduct(uuid);
    d->m_purchaseOrder->deleteItem(uuid);
}

void PurchasePage::addedShowProduct(ProductObject* product)
{
    Q_D(PurchasePage);

    auto item = new SearchItem(*product);
    item->setImage(product->image());
    item->setTitle(product->name());
    item->setSubTitle("Rp " +  d->m_locale.toString(product->customerPrice()));
    item->setUUID(product->uuid());

    //product->Attach(item);

    QObject::connect(item, &SearchItem::addedToOrder, this, &PurchasePage::addOrderItem);
    QObject::connect(item, &SearchItem::deleteToOrder, this, &PurchasePage::removeOrderItem);

    d->m_resultList->addProductObjectShow(item);
}