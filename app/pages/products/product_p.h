#ifndef QTHNI_PRODUCT_P_H
#define QTHNI_PRODUCT_P_H

#include <QImage>

class Product;
class ProductPrivate
{
    Q_DISABLE_COPY(ProductPrivate)
    Q_DECLARE_PUBLIC(Product)

public:
    explicit ProductPrivate(Product *q);
    ~ProductPrivate();

    void init();

    Product *const  q_ptr;
    QImage          m_image;
    QString         m_name;
    int             m_price;
    int             m_point;
    int             m_stock;
};

#endif //QTHNI_PRODUCT_P_H
