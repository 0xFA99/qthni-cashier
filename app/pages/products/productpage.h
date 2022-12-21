#ifndef QTHNI_PRODUCTPAGE_H
#define QTHNI_PRODUCTPAGE_H

#include <QWidget>

class ProductObject;
class OperateItem;
class ProductPagePrivate;
class ProductPage : public QWidget
{
    Q_OBJECT

public:
    explicit ProductPage(QWidget *parent = nullptr);
    ~ProductPage();

public slots:
    void addingProduct(ProductObject*);
    void editProduct(int);
    void updateProduct(int, ProductObject*);
    void deleteProduct(int);

signals:
    void addedToPurchase(ProductObject *);
    void updatedToPurchase(int, ProductObject *);

protected:
    const QScopedPointer<ProductPagePrivate> d_ptr;

private:
    Q_DISABLE_COPY(ProductPage)
    Q_DECLARE_PRIVATE(ProductPage)
};

#endif //QTHNI_PRODUCTPAGE_H
