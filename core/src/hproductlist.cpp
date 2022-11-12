#include "hproductlist.h"
#include "hproductlist_p.h"

#include <QPainter>
#include <QPainterPath>
#include <QGridLayout>

#include "hproduct.h"
#include "hproductitem.h"
#include "hproductview.h"

HProductListPrivate::HProductListPrivate(HProductList *q)
    : q_ptr(q)
{
}

HProductListPrivate::~HProductListPrivate() = default;

void HProductListPrivate::init()
{
    Q_Q(HProductList);

    m_layout        = new QGridLayout(q);
    m_title         = new HMaterialLabel("Product List", q);
    m_gridButton    = new HMaterialFlatButton("\uE62A", q);
    m_vertButton    = new HMaterialFlatButton("\uE622", q);
    m_fabButton     = new HMaterialFloatingActionButton(HMaterialTheme::icon("toggle", "star"));
    m_scrollArea    = new QScrollArea(q);
    m_dialog        = new HMaterialDialog;
    m_dialogLayout  = new QVBoxLayout;
    m_productDialog = new HProductEdit(q);
    m_productView   = new HProductView(q);

    m_dialog->setParent(q);
    m_dialog->setWindowLayout(m_dialogLayout);
    m_dialogLayout->addWidget(m_productDialog);

    m_scrollArea->setWidget(m_productView);
    m_scrollArea->setWidgetResizable(true);
    m_scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_scrollArea->setFrameShape(QFrame::NoFrame);

    m_fabButton->setParent(m_scrollArea);
    m_fabButton->setHaloVisible(false);
    m_fabButton->setRippleStyle(HMaterial::NoRipple);

    m_title->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);

    QFont font("iconfont", 12, QFont::Medium);
    m_gridButton->setFont(font);
    m_vertButton->setFont(font);

    m_layout->addWidget(m_title, 0, 0, 1, 1);
    m_layout->addWidget(m_gridButton, 0, 1, 1, 1);
    m_layout->addWidget(m_vertButton, 0, 2, 1, 1);
    m_layout->addWidget(m_scrollArea, 1, 0, 1, 3);

    m_layout->setContentsMargins(16, 10, 16, 10);
}

HProductList::HProductList(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HProductListPrivate(this))
{
    d_func()->init();

    syncProductDB();
    performConnection();
}

HProductList::~HProductList() = default;

void HProductList::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);

    QPainterPath path;
    path.addRoundedRect(rect(), 16, 16);

    QPainter painter(this);
    painter.setClipPath(path);
    painter.setClipping(true);
    painter.setOpacity(1);
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);
    painter.drawRect(rect());

    QRect line(16, 46, rect().width() - 32, 1);
    painter.fillRect(line, QColor("#f1f4f9"));
}

void HProductList::performConnection()
{
    Q_D(HProductList);

    QObject::connect(d->m_fabButton, &QPushButton::clicked, [=]() -> void {
        d->m_productDialog->setMode(HProductEdit::Mode::AddMode);
        d->m_dialog->showDialog();
    });

    QObject::connect(d->m_productDialog, &HProductEdit::hideDialog,
                     d->m_dialog, &HMaterialDialog::hideDialog);

    QObject::connect(d->m_productDialog, &HProductEdit::addSignal,
                     this, &HProductList::addProduct);
}

void HProductList::syncProductDB()
{
    Q_D(HProductList);

    HProduct *newProduct = new HProduct(this);
    newProduct->setImage(QImage(":/images/images/default.png"));
    newProduct->setName(QString("Bilberry"));
    newProduct->setPrice(100000);
    newProduct->setStock(10);

    d->m_productList.push_back(newProduct);

    HProductItem *newItem = new HProductItem(newProduct, d->m_productView);

    QObject::connect(
            newItem, &HProductItem::removeItem,
            d->m_productView, &HProductView::removeItem
    );

    QObject::connect(
            newItem, &HProductItem::editItem,
            this, &HProductList::editProduct
            );

    d->m_productView->addItem(newItem);
}

void HProductList::addProduct(const QImage &image, const QString &name, int price, int stock)
{
    Q_D(HProductList);

    HProduct *newProduct = new HProduct(this);
    newProduct->setImage(image);
    newProduct->setName(name);
    newProduct->setPrice(price);
    newProduct->setStock(stock);

    d->m_productList.push_back(newProduct);

    HProductItem *newItem = new HProductItem(newProduct, d->m_productView);

    QObject::connect(
            newItem, &HProductItem::removeItem,
            this, &HProductList::removeProduct
            );
    QObject::connect(
            newItem, &HProductItem::editItem,
            this, &HProductList::editProduct
            );

    d->m_productView->addItem(newItem);
}

void HProductList::editProduct(HProduct *product)
{
    Q_D(HProductList);

    d->m_productDialog->setMode(HProductEdit::Mode::EditMode);
    d->m_productDialog->setTargetProduct(product);

    d->m_dialog->showDialog();
}

void HProductList::removeProduct(const QString &name)
{
    Q_D(HProductList);

    d->m_productView->removeItem(name);
}