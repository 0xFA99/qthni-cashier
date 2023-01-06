#include "products/productpage.h"
#include "products/productpage_p.h"

#include <QHBoxLayout>
#include <QDebug>

#include "products/ProductObjectManager.h"
#include "widgets/items/OperateItem.h"

ProductPagePrivate::ProductPagePrivate(ProductPage *q)
    : q_ptr(q)
{
}

ProductPagePrivate::~ProductPagePrivate() = default;

void ProductPagePrivate::init()
{
    Q_Q(ProductPage);

    m_layout                = new QHBoxLayout(q);
    m_productListTitle      = new FrameTitle(q);
    m_productList           = new ProductList(q);
    m_productScrollArea     = new QScrollArea(q);
    m_productDialog         = new QtMaterialDialog;
    m_productDialogWidget   = new ProductDialog(q);
    m_snackBar              = new QtMaterialSnackbar;
    m_fabButton             = new QtMaterialFloatingActionButton(QtMaterialTheme::icon("content", "add"), q);
    m_locale                = QLocale("id_ID");

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

ProductPage::ProductPage(ProductObjectManager *manager, QWidget *parent)
    : QWidget(parent)
    , d_ptr(new ProductPagePrivate(this))
{
    d_func()->init();

    addProductManager(manager);
}

ProductPage::~ProductPage() = default;

void
ProductPage::addingProduct(ProductObject& product)
{
    Q_D(ProductPage);

    addProductToManager(product);
    addProductToDB(product);

    d->m_snackBar->addMessage(QString("Berhasil Menambahkan Product"));
}

void ProductPage::editProduct(QUuid uuid)
{
    Q_D(ProductPage);

    d->m_productDialogWidget->setMode(ProductDialog::Edit);
    d->m_productDialogWidget->setProductFromUUID(uuid);

    d->m_productDialog->showDialog();
}

void ProductPage::updateProduct(QUuid uuid, ProductObject& product)
{
    Q_D(ProductPage);

    d->m_productManager->updateProduct(uuid, product);
    qDebug() << "App - Success - Update Product UUID: " << uuid;

    d->m_snackBar->addInstantMessage(QString("Berhasil Mengedit Product"));
}

void ProductPage::deleteProduct(QUuid uuid)
{
    Q_D(ProductPage);

    d->m_productManager->deleteProduct(uuid);
    d->m_productList->deleteProductItem(uuid);

    // Show Product in Purchase Page
    deleteShowProduct(uuid);
    qDebug() << "App - Success - Delete Product UUID: " << uuid;

    d->m_snackBar->addInstantMessage(QString("Berhasil Menghapus Product"));
}

void ProductPage::addProductManager(ProductObjectManager *manager)
{
    Q_D(ProductPage);

    d->m_productManager = manager;
    d->m_productDialogWidget->addProductManager(manager);
}

void ProductPage::addProductToManager(ProductObject& product)
{
    Q_D(ProductPage);

    auto newProductObject = new ProductObject;
    newProductObject->editProduct(product);
    newProductObject->setUUID(product.uuid());

    qDebug() << "App - Success - Receive UUID: " << newProductObject->uuid();

    // Add To Product Manager - Product Page
    d->m_productManager->addProduct(newProductObject);

    // Add to item list - Product Page
    addProductToItemList(newProductObject);

    // Add to purchase page - show item - Purchase Page
    addedToPurchase(newProductObject);
}

void ProductPage::addProductToItemList(ProductObject *product)
{
    Q_D(ProductPage);

    auto newItemProduct = new OperateItem;
    newItemProduct->setUUID(product->uuid());
    newItemProduct->setImage(product->image());
    newItemProduct->setTitle(product->name());
    newItemProduct->setSubTitle("Rp " + d->m_locale.toString(product->customerPrice()));

    QObject::connect(newItemProduct, &OperateItem::s_editButton, this, &ProductPage::editProduct);
    QObject::connect(newItemProduct, &OperateItem::s_deleteButton, this, &ProductPage::deleteProduct);

    product->Attach(newItemProduct);

    d->m_productList->addProductItem(newItemProduct);
}

void ProductPage::addProductToDB(ProductObject& product)
{
    Q_D(ProductPage);

    if (HNIDatabase::tryAddProduct(product)) {
        qDebug() << "DB - Success - Insert Product " << product.name() << " To DB";
    } else {
        qDebug() << "DB - Error - Insert Product " << product.name() << " To DB";
    }
}

void ProductPage::syncProductFromDB()
{
    QVector<ProductObject*> getAllProduct = HNIDatabase::getAllProduct();
    for (auto i : getAllProduct) {
        ProductObject loadProduct;
        loadProduct.setUUID(i->uuid());
        loadProduct.setImage(i->image());
        loadProduct.setName(i->name());
        loadProduct.setStatus(i->status());
        loadProduct.setMemberPrice(i->memberPrice());
        loadProduct.setCustomerPrice(i->customerPrice());
        loadProduct.setStock(i->stock());
        loadProduct.setPoint(i->point());

        delete i;

        addProductToManager(loadProduct);
    }
}