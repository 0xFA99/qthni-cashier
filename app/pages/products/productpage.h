#ifndef QTHNI_PRODUCTPAGE_H
#define QTHNI_PRODUCTPAGE_H

#include <QWidget>

class Product;
class OperateItem;
class ProductPagePrivate;
class ProductPage : public QWidget
{
    Q_OBJECT

public:
    explicit ProductPage(QWidget *parent = nullptr);
    ~ProductPage();

public slots:
    void addingProduct(Product *);
    void editProduct(int);
    void updateProduct(int, Product *);
    void deleteProduct(int);

signals:
    void addedToPurchase(Product *);
    void updatedToPurchase(int, Product *);

protected:
    const QScopedPointer<ProductPagePrivate> d_ptr;

private:
    Q_DISABLE_COPY(ProductPage)
    Q_DECLARE_PRIVATE(ProductPage)
};

#endif //QTHNI_PRODUCTPAGE_H
