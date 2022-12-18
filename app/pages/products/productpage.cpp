#include "products/productpage.h"
#include "products/productpage_p.h"

#include <QHBoxLayout>

#include "products/product.h"
#include "widgets/items/operateitem.h"

ProductPagePrivate::ProductPagePrivate(ProductPage *q)
    : q_ptr(q)
{
}

ProductPagePrivate::~ProductPagePrivate() = default;

void ProductPagePrivate::init()
{
    Q_Q(ProductPage);

    m_layout                = new QHBoxLayout(q);
    m_productManager        = new ProductManager(q);
    m_productListTitle      = new FrameTitle(q);
    m_productList           = new ProductList(q);
    m_productScrollArea     = new QScrollArea(q);
    m_productDialog         = new QtMaterialDialog;
    m_productDialogWidget   = new ProductDialog(q);
    m_snackBar              = new QtMaterialSnackbar;
    m_fabButton             = new QtMaterialFloatingActionButton(QtMaterialTheme::icon("content", "add"), q);

    m_snackBar->setParent(q);

    m_fabButton->setHaloVisible(false);
    m_fabButton->setRippleStyle(Material::NoRipple);

    // START
    auto *dialogLayout = new QVBoxLayout;

    m_productDialog->setParent(q);
    m_productDialog->setWindowLayout(dialogLayout);

    dialogLayout->addWidget(m_productDialogWidget);

    QObject::connect(m_fabButton, &QPushButton::clicked, [=]() {
        m_productDialogWidget->setMode(ProductDialog::Mode::Add);
        m_productDialog->showDialog();
    });

    QObject::connect(m_productDialogWidget, &ProductDialog::closedProductDialog,
                     m_productDialog, &QtMaterialDialog::hideDialog);

    QObject::connect(m_productDialogWidget, &ProductDialog::addedProduct,
                     q, &ProductPage::addingProduct);

    QObject::connect(m_productDialogWidget, &ProductDialog::editedProduct,
                     q, &ProductPage::updateProduct);
    // END

    QFont font("Roboto", 12, QFont::Medium);

    m_productScrollArea->setWidget(m_productList);
    m_productScrollArea->setWidgetResizable(true);
    m_productScrollArea->setStyleSheet("background-color: transparent");
    m_productScrollArea->setVerticalScrollBar(new QtMaterialScrollBar(m_productScrollArea));
    m_productScrollArea->setHorizontalScrollBar(new QtMaterialScrollBar(m_productScrollArea));

    m_productListTitle->setFont(font);
    m_productListTitle->setTitleColor(QRgb(0x1f1f1f));
    m_productListTitle->setTitle("Daftar Produk");
    m_productListTitle->addChildWidget(m_productScrollArea);

    m_layout->addWidget(m_productListTitle);

}

ProductPage::ProductPage(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new ProductPagePrivate(this))
{
    d_func()->init();
}

ProductPage::~ProductPage() = default;

void ProductPage::addingProduct(Product *product)
{
    Q_D(ProductPage);

    auto newProduct = new Product;
    newProduct->setImage(product->image());
    newProduct->setName(product->name());
    newProduct->setPrice(product->price());
    newProduct->setStock(product->stock());
    newProduct->setPoint(product->point());

    d->m_productManager->addProduct(newProduct);

    auto newItemProduct = new OperateItem(d->m_productManager->lastItemIndex() - 1);
    newItemProduct->setImage(product->image());
    newItemProduct->setTitle(product->name());
    newItemProduct->setSubTitle(QString::number(product->price()));

    QObject::connect(newItemProduct, &OperateItem::editItem,
                     this, &ProductPage::editProduct);

    QObject::connect(newItemProduct, &OperateItem::deleteItem,
                     this, &ProductPage::deleteProduct);

    d->m_productList->addProductItem(newItemProduct);

    d->m_snackBar->addMessage(QString("Berhasil Menambahkan Product"));
}

void ProductPage::editProduct(int index)
{
    Q_D(ProductPage);

    d->m_productDialogWidget->setMode(ProductDialog::Edit);

    Product *tempProduct = d->m_productManager->getProduct(index);

    d->m_productDialogWidget->setImageField(tempProduct->image());
    d->m_productDialogWidget->setNameField(tempProduct->name());
    d->m_productDialogWidget->setPriceField(tempProduct->price());
    d->m_productDialogWidget->setStockField(tempProduct->stock());
    d->m_productDialogWidget->setPointField(tempProduct->point());
    d->m_productDialogWidget->setIndex(index);

    d->m_productDialog->showDialog();
}

void ProductPage::updateProduct(int index, Product *product)
{
    Q_D(ProductPage);

    d->m_productManager->updateProduct(index, product);
    d->m_productList->updateProductItem(index, product);

    d->m_snackBar->addMessage(QString("Berhasil Mengedit Product"));
}

void ProductPage::deleteProduct(int index)
{
    Q_D(ProductPage);

    d->m_productList->deleteProductItem(index);
    d->m_productManager->deleteProduct(index);

    d->m_snackBar->addInstantMessage(QString("Berhasil Menghapus Product"));
}