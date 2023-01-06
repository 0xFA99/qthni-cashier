#ifndef QTHNI_PRODUCTPAGE_H
#define QTHNI_PRODUCTPAGE_H

#include <QWidget>

#include "widgets/items/searchitem.h"
#include "products/ProductObject.h"

class ProductObjectManager;
class OperateItem;

class ProductPagePrivate;
class ProductPage : public QWidget
{
    Q_OBJECT

public:
    explicit ProductPage(ProductObjectManager *manager, QWidget *parent = nullptr);
    ~ProductPage();

    void syncProductFromDB();

public slots:
    void addingProduct(ProductObject&);
    void editProduct(QUuid);
    void updateProduct(QUuid, ProductObject&);
    void deleteProduct(QUuid);

signals:
    void addedToPurchase(ProductObject*);
    void deleteShowProduct(QUuid);

protected:
    const QScopedPointer<ProductPagePrivate> d_ptr;

private:
    void addProductManager(ProductObjectManager *manager);

    void addProductToManager(ProductObject&);
    void addProductToItemList(ProductObject*);

    void addProductToDB(ProductObject&);

    Q_DISABLE_COPY(ProductPage)
    Q_DECLARE_PRIVATE(ProductPage)
};

#endif //QTHNI_PRODUCTPAGE_H
