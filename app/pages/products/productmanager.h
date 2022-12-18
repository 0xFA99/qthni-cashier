#ifndef QTHNI_PRODUCTMANAGER_H
#define QTHNI_PRODUCTMANAGER_H

#include <QObject>

class Product;
class ProductManagerPrivate;
class ProductManager : public QObject
{
    Q_OBJECT

public:
    explicit ProductManager(QObject *parent = nullptr);
    ~ProductManager();

    void addProduct(Product *);
    void deleteProduct(int index);

    Product *getProduct(int index);

    [[nodiscard]] QImage getProductImage(int index);
    [[nodiscard]] QString getProductName(int index) const;
    [[nodiscard]] int getProductPrice(int index) const;
    [[nodiscard]] int getProductStock(int index) const;
    [[nodiscard]] int getProductPoint(int index) const;

    [[nodiscard]] int lastItemIndex() const;

public slots:
    void updateProduct(int, Product *);

protected:
    const QScopedPointer<ProductManagerPrivate> d_ptr;

private:
    Q_DISABLE_COPY(ProductManager)
    Q_DECLARE_PRIVATE(ProductManager)
};


#endif //QTHNI_PRODUCTMANAGER_H
