#ifndef QTHNI_PRODUCTMANAGER_P_H
#define QTHNI_PRODUCTMANAGER_P_H

#include <QVector>

class Product;
class ProductManager;
class ProductManagerPrivate
{
    Q_DISABLE_COPY(ProductManagerPrivate)
    Q_DECLARE_PUBLIC(ProductManager)

public:
    explicit ProductManagerPrivate(ProductManager *q);
    ~ProductManagerPrivate();

    void init();

    ProductManager *const   q_ptr;
    QVector<Product *>      m_productList;
};

#endif //QTHNI_PRODUCTMANAGER_P_H
