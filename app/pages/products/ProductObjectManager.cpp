#include "products/ProductObjectManager.h"
#include "products/ProductObjectManager_p.h"

#include "products/ProductObject.h"

#include <QImage>

ProductObjectManagerPrivate::ProductObjectManagerPrivate(ProductObjectManager *q)
    : q_ptr(q)
{
}

ProductObjectManagerPrivate::~ProductObjectManagerPrivate() = default;

void ProductObjectManagerPrivate::init()
{
    Q_Q(ProductObjectManager);

    m_productList = QVector<ProductObject *>();
}

ProductObjectManager::ProductObjectManager(QObject *parent)
    : QObject(parent)
    , d_ptr(new ProductObjectManagerPrivate(this))
{
    d_func()->init();
}

ProductObjectManager::~ProductObjectManager() = default;

int
ProductObjectManager::lastItemIndex() const
{
    Q_D(const ProductObjectManager);

    return d->m_productList.size();
}

void
ProductObjectManager::addProduct(ProductObject *product)
{
    Q_D(ProductObjectManager);

    product->setParent(this);
    d->m_productList.push_back(product);
}

ProductObject*
ProductObjectManager::getProductObject(int index)
{
    Q_D(ProductObjectManager);

    return d->m_productList.at(index);
}

void
ProductObjectManager::updateProduct(int index, ProductObject *product)
{
    Q_D(ProductObjectManager);

    ProductObject* updateProduct = d->m_productList.at(index);

    updateProduct->editProduct(product);
    updateProduct->Update();
}

void
ProductObjectManager::deleteProduct(int index)
{
    Q_D(ProductObjectManager);

    ProductObject* deleteProduct = d->m_productList.at(index);

    d->m_productList.removeAt(index);
    delete deleteProduct;
}