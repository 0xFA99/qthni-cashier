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
    void addedShowProduct(ProductObject*);
    void deletedShowProduct(QUuid);

protected:
    const QScopedPointer<PurchasePagePrivate> d_ptr;

private:
    void addProductManager(ProductObjectManager *manager);

    Q_DISABLE_COPY(PurchasePage)
    Q_DECLARE_PRIVATE(PurchasePage)

private slots:
    void addOrderItem(QUuid);
    void removeOrderItem(QUuid);
};

#endif //QTHNI_PURCHASEPAGE_H
