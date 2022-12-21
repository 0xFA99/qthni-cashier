#ifndef QTHNI_PRODUCTLIST_H
#define QTHNI_PRODUCTLIST_H

#include <QWidget>

class OperateItem;

class ProductListPrivate;
class ProductList : public QWidget
{
    Q_OBJECT

public:
    explicit ProductList(QWidget *parent = nullptr);
    ~ProductList();

    void addProductItem(OperateItem *item);
    void deleteProductItem(int index);

protected:
    const QScopedPointer<ProductListPrivate> d_ptr;

private:
    Q_DISABLE_COPY(ProductList)
    Q_DECLARE_PRIVATE(ProductList)
};

#endif //QTHNI_PRODUCTLIST_H
