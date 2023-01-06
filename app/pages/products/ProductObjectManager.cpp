#include "products/ProductObjectManager.h"
#include "products/ProductObjectManager_p.h"

#include "products/ProductObject.h"

#include <QImage>
#include <QDebug>

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

void
ProductObjectManager::addProduct(ProductObject *product)
{
    Q_D(ProductObjectManager);

    product->setParent(this);
    d->m_productList.push_back(product);
}

ProductObject*
ProductObjectManager::getProductObject(const QUuid& uuid)
{
    Q_D(ProductObjectManager);

    ProductObject *product;
    for (ProductObject *pro : d->m_productList) {
        if (pro->uuid() == uuid) {
            product = pro;
        }
    }

    return product;
}

void
ProductObjectManager::updateProduct(QUuid uuid, ProductObject& product)
{
    Q_D(ProductObjectManager);

    for (ProductObject *pro : d->m_productList) {
        if (pro->uuid() == uuid) {
            pro->editProduct(product);
            pro->Update();

            HNIDatabase::tryUpdateProduct(uuid, product);

            break;
        }
    }
}

void
ProductObjectManager::deleteProduct(QUuid uuid)
{
    Q_D(ProductObjectManager);

    for (ProductObject *pro : d->m_productList) {
        if (pro->uuid() == uuid) {
            d->m_productList.removeOne(pro);
            pro->deleteLater();

            HNIDatabase::tryDeleteProduct(uuid);

            break;
        }
    }
}
