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

void ProductPage::addingProduct(ProductObject *product)
{
    Q_D(ProductPage);

    addProductToManager(product);
    addProductToDB(product);

    d->m_snackBar->addMessage(QString("Berhasil Menambahkan Product"));
}

void ProductPage::editProduct(int index)
{
    Q_D(ProductPage);

    d->m_productDialogWidget->setMode(ProductDialog::Edit);

    ProductObject *tempProduct = d->m_productManager->getProductObject(index);

    d->m_productDialogWidget->setImageField(tempProduct->image());
    d->m_productDialogWidget->setNameField(tempProduct->name());
    d->m_productDialogWidget->setPriceField(QString("Rp " + d->m_locale.toString(tempProduct->price())));
    d->m_productDialogWidget->setStockField(tempProduct->stock());
    d->m_productDialogWidget->setPointField(tempProduct->point());
    d->m_productDialogWidget->setIndex(index);

    d->m_productDialog->showDialog();
}

void ProductPage::updateProduct(int index, ProductObject *product)
{
    Q_D(ProductPage);

    d->m_productManager->updateProduct(index, product);

    d->m_snackBar->addInstantMessage(QString("Berhasil Mengedit Product"));
}

void ProductPage::deleteProduct(int index)
{
    Q_D(ProductPage);

    d->m_productManager->deleteProduct(index);
    d->m_productList->deleteProductItem(index);
    deleteShowProduct(index);

    d->m_snackBar->addInstantMessage(QString("Berhasil Menghapus Product"));
}

void ProductPage::addProductManager(ProductObjectManager *manager)
{
    Q_D(ProductPage);

    d->m_productManager = manager;
}

void ProductPage::addProductToManager(ProductObject *product)
{
    Q_D(ProductPage);

    auto newProductObject = new ProductObject;
    newProductObject->editProduct(product);

    d->m_productManager->addProduct(newProductObject);

    // Add to item list
    addProductToItemList(newProductObject, product);
}

void ProductPage::addProductToItemList(ProductObject *subject, ProductObject *product)
{
    Q_D(ProductPage);

    auto newItemProduct = new OperateItem;
    newItemProduct->setImage(product->image());
    newItemProduct->setTitle(product->name());
    newItemProduct->setSubTitle(QString("Rp " + d->m_locale.toString(product->price())));
    newItemProduct->setIndex(d->m_productManager->lastItemIndex() - 1);

    QObject::connect(newItemProduct, &OperateItem::s_editButton, this, &ProductPage::editProduct);
    QObject::connect(newItemProduct, &OperateItem::s_deleteButton, this, &ProductPage::deleteProduct);

    d->m_productList->addProductItem(newItemProduct);

    subject->Attach(newItemProduct);

    addedToPurchase(d->m_productManager->lastItemIndex() - 1);
}

void ProductPage::addProductToDB(ProductObject *product)
{
    Q_D(ProductPage);

    if (HNIDatabase::tryAddProduct(product)) {
        qDebug() << "Menambahkan " << product->name() << " ke Database";
    } else {
        qDebug() << "Gagal Menambahkan " << product->name() << " ke Database";
    }
}

void ProductPage::syncProductFromDB()
{
    QVector<ProductObject*> getAllProduct = HNIDatabase::getAllProduct();
    for (auto i : getAllProduct) {
        ProductObject loadProduct;
        loadProduct.setImage(i->image());
        loadProduct.setName(i->name());
        loadProduct.setPrice(i->price());
        loadProduct.setStock(i->stock());
        loadProduct.setPoint(i->point());

        delete i;

        addProductToManager(&loadProduct);
    }
}
