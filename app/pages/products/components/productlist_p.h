#ifndef QTHNI_PRODUCTLIST_P_H
#define QTHNI_PRODUCTLIST_P_H

#include <QLocale>

class QVBoxLayout;

class ProductList;
class ProductListPrivate
{
    Q_DISABLE_COPY(ProductListPrivate)
    Q_DECLARE_PUBLIC(ProductList)

public:
    explicit ProductListPrivate(ProductList *q);
    ~ProductListPrivate();

    void init();

    ProductList *const      q_ptr;
    QVBoxLayout             *m_layout;
};

#endif //QTHNI_PRODUCTLIST_P_H
