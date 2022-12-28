#ifndef QTHNI_PRODUCTOBJECTMANAGER_H
#define QTHNI_PRODUCTOBJECTMANAGER_H

#include <QObject>

// class HNIDatabase;
class ProductObject;
class ProductObjectManagerPrivate;
class ProductObjectManager : public QObject
{
    Q_OBJECT

public:
    // explicit ProductObjectManager(HNIDatabase&, QObject *parent = nullptr);
    explicit ProductObjectManager(QObject *parent = nullptr);
    ~ProductObjectManager();

    [[nodiscard]] int lastItemIndex() const;

    ProductObject* getProductObject(int);

    void addProduct(ProductObject*);
    void updateProduct(int, ProductObject*);
    void deleteProduct(int);

protected:
    const QScopedPointer<ProductObjectManagerPrivate> d_ptr;

private:
    // void addDatabase(HNIDatabase&);

    Q_DISABLE_COPY(ProductObjectManager)
    Q_DECLARE_PRIVATE(ProductObjectManager)
};


#endif //QTHNI_PRODUCTOBJECTMANAGER_H
