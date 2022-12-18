#include "products/productmanager.h"
#include "products/productmanager_p.h"

#include "products/product.h"

#include <QImage>

ProductManagerPrivate::ProductManagerPrivate(ProductManager *q)
    : q_ptr(q)
{
}

ProductManagerPrivate::~ProductManagerPrivate() = default;

void ProductManagerPrivate::init()
{
    Q_Q(ProductManager);

    m_productList = QVector<Product *>();
}

ProductManager::ProductManager(QObject *parent)
    : QObject(parent)
    , d_ptr(new ProductManagerPrivate(this))
{
    d_func()->init();
}

ProductManager::~ProductManager() = default;

void ProductManager::addProduct(Product *product)
{
    Q_D(ProductManager);

    product->setParent(this);
    d->m_productList.push_back(product);
}

void ProductManager::updateProduct(int index, Product *product)
{
    Q_D(ProductManager);

    Product *updatedProduct;
    updatedProduct = d->m_productList.at(index);

    updatedProduct->setImage(product->image());
    updatedProduct->setName(product->name());
    updatedProduct->setPrice(product->price());
    updatedProduct->setStock(product->stock());
    updatedProduct->setPoint(product->point());
}

void ProductManager::deleteProduct(int index)
{
    Q_D(ProductManager);

    Product *deleteProduct;
    deleteProduct = d->m_productList.at(index);

    d->m_productList.removeAt(index);
    delete deleteProduct;
}

QImage ProductManager::getProductImage(int index)
{
    Q_D(ProductManager);

    return d->m_productList.at(index)->image();
}

QString ProductManager::getProductName(int index) const
{
    Q_D(const ProductManager);

    return d->m_productList.at(index)->name();
}

int ProductManager::getProductPrice(int index) const
{
    Q_D(const ProductManager);

    return d->m_productList.at(index)->price();
}

int ProductManager::getProductStock(int index) const
{
    Q_D(const ProductManager);

    return d->m_productList.at(index)->stock();
}

int ProductManager::getProductPoint(int index) const
{
    Q_D(const ProductManager);

    return d->m_productList.at(index)->point();
}

int ProductManager::lastItemIndex() const
{
    Q_D(const ProductManager);

    return d->m_productList.size();
}

Product *ProductManager::getProduct(int index)
{
    Q_D(ProductManager);

    return d->m_productList.at(index);
}