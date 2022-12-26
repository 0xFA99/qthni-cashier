#ifndef QTHNI_PURCHASEPAGE_H
#define QTHNI_PURCHASEPAGE_H

#include <QWidget>

#include "products/ProductObject.h"
#include "widgets/items/searchitem.h"

class ProductObject;
class ProductObjectManager;
class PurchasePagePrivate;
class PurchasePage : public QWidget
{
    Q_OBJECT

public:
    explicit PurchasePage(ProductObjectManager *manager, QWidget *parent = nullptr);
    ~PurchasePage();

public slots:
    void addedShowProduct(SearchItem*);
    void deletedShowProduct(int);

protected:
    const QScopedPointer<PurchasePagePrivate> d_ptr;

private:
    void addProductManager(ProductObjectManager *manager);

    Q_DISABLE_COPY(PurchasePage)
    Q_DECLARE_PRIVATE(PurchasePage)

private slots:
    void addOrderItem(int);
    void removeOrderItem(int);
};

#endif //QTHNI_PURCHASEPAGE_H
