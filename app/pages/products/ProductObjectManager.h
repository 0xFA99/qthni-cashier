#ifndef QTHNI_PRODUCTOBJECTMANAGER_H
#define QTHNI_PRODUCTOBJECTMANAGER_H

#include <QObject>

class ProductObject;
class ProductObjectManagerPrivate;
class ProductObjectManager : public QObject
{
    Q_OBJECT

public:
    explicit ProductObjectManager(QObject *parent = nullptr);
    ~ProductObjectManager();

    ProductObject* getProductObject(const QUuid&);

    void addProduct(ProductObject*);
    void updateProduct(QUuid, ProductObject&);
    void deleteProduct(QUuid);

protected:
    const QScopedPointer<ProductObjectManagerPrivate> d_ptr;

private:
    Q_DISABLE_COPY(ProductObjectManager)
    Q_DECLARE_PRIVATE(ProductObjectManager)
};


#endif //QTHNI_PRODUCTOBJECTMANAGER_H
