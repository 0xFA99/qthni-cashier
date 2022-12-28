#include "analysic/analysicpage.h"
#include "analysic/analysicpage_p.h"

#include "widgets/items/minimalitem.h"
#include "products/ProductObject.h"

#include <QHBoxLayout>
#include <QFrame>

#include "qtmaterial/components/qtmaterialscrollbar.h"

AnalysicPagePrivate::AnalysicPagePrivate(AnalysicPage *q)
    : q_ptr(q)
{
}

AnalysicPagePrivate::~AnalysicPagePrivate() = default;

void AnalysicPagePrivate::init()
{
    Q_Q(AnalysicPage);

    m_layout        = new QHBoxLayout(q);

    m_chartFrame    = new FrameTitle("Grafik Penjualan");
    m_chartWidget   = new ChartWidget(q);

    m_stockFrame    = new FrameTitle("Sisa Stock");
    m_stockScroll   = new QScrollArea(q);
    m_remainingStockWidget  = new RemainingStock(q);

    m_lastPurchaseFrame = new FrameTitle("Penjualan Terakhir");
    m_lastPurchaseScroll    = new QScrollArea(q);
    m_lastPurchaseWidget    = new LastPurchase(q);

    m_stockScroll->setWidget(m_remainingStockWidget);
    m_stockScroll->setWidgetResizable(true);
    m_stockScroll->setStyleSheet("background-color: transparent");
    m_stockScroll->setVerticalScrollBar(new QtMaterialScrollBar(m_stockFrame));
    m_stockScroll->setHorizontalScrollBar(new QtMaterialScrollBar(m_stockFrame));

    m_lastPurchaseScroll->setWidget(m_lastPurchaseWidget);
    m_lastPurchaseScroll->setWidgetResizable(true);
    m_lastPurchaseScroll->setStyleSheet("background-color: transparent");
    m_lastPurchaseScroll->setVerticalScrollBar(new QtMaterialScrollBar(m_lastPurchaseFrame));
    m_lastPurchaseScroll->setHorizontalScrollBar(new QtMaterialScrollBar(m_lastPurchaseFrame));


    m_chartFrame->addChildWidget(m_chartWidget);
    m_stockFrame->addChildWidget(m_stockScroll);
    m_lastPurchaseFrame->addChildWidget(m_lastPurchaseScroll);

    QFrame *leftFrame = new QFrame(q);
    QFrame *rightFrame = new QFrame(q);

    m_chartFrame->setParent(leftFrame);

    m_stockFrame->setParent(rightFrame);
    m_lastPurchaseFrame->setParent(rightFrame);

    QSizePolicy leftFramePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    QSizePolicy rightFramePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    leftFramePolicy.setHorizontalStretch(2);
    rightFramePolicy.setHorizontalStretch(1);

    leftFrame->setSizePolicy(leftFramePolicy);
    rightFrame->setSizePolicy(rightFramePolicy);

    QGridLayout *leftFrameLayout = new QGridLayout(leftFrame);
    QVBoxLayout *rightFrameLayout = new QVBoxLayout(rightFrame);

    leftFrameLayout->setSpacing(16);
    rightFrameLayout->setSpacing(16);

    leftFrameLayout->addWidget(m_chartFrame);

    rightFrameLayout->addWidget(m_stockFrame);
    rightFrameLayout->addWidget(m_lastPurchaseFrame);

    m_layout->addWidget(leftFrame);
    m_layout->addWidget(rightFrame);
}

AnalysicPage::AnalysicPage(ProductObjectManager *manager, QWidget *parent)
    : QWidget(parent)
    , d_ptr(new AnalysicPagePrivate(this))
{
    d_func()->init();

    addProductManager(manager);
}

AnalysicPage::~AnalysicPage() = default;

void AnalysicPage::addProductManager(ProductObjectManager *manager)
{
    Q_D(AnalysicPage);

    d->m_productManager = manager;
}

void AnalysicPage::addRemaindStockItem(int index)
{
    Q_D(AnalysicPage);

    ProductObject *product = d->m_productManager->getProductObject(index);

    auto *item = new MinimalItem;
    item->setImage(product->image());
    item->setTitle(product->name());
    item->setSubTitle(QString::number(product->stock()));
    product->Attach(item);

    d->m_remainingStockWidget->addRemaindItem(item);
}

void AnalysicPage::deleteRemainStockItem(int index)
{
    Q_D(AnalysicPage);

    d->m_remainingStockWidget->deleteRemaindItem(index);
}