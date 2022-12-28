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

    // void addDatabase(HNIDatabase&);
    void syncProductFromDB();

public slots:
    void addingProduct(ProductObject*);
    void editProduct(int);
    void updateProduct(int, ProductObject*);
    void deleteProduct(int);

signals:
    void addedToPurchase(int);
    void deleteShowProduct(int);

protected:
    const QScopedPointer<ProductPagePrivate> d_ptr;

private:
    void addProductManager(ProductObjectManager *manager);

    void addProductToManager(ProductObject*);
    void addProductToItemList(ProductObject*, ProductObject*);
    void addProductToDB(ProductObject*);

    Q_DISABLE_COPY(ProductPage)
    Q_DECLARE_PRIVATE(ProductPage)
};

#endif //QTHNI_PRODUCTPAGE_H
