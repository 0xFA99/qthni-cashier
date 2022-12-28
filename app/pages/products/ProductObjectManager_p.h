#ifndef QTHNI_PRODUCTOBJECTMANAGER_P_H
#define QTHNI_PRODUCTOBJECTMANAGER_P_H

#include <QVector>

// #include "database/HNIDatabase.h"

class ProductObject;
class ProductObjectManager;
class ProductObjectManagerPrivate
{
    Q_DISABLE_COPY(ProductObjectManagerPrivate)
    Q_DECLARE_PUBLIC(ProductObjectManager)

public:
    explicit ProductObjectManagerPrivate(ProductObjectManager *q);
    ~ProductObjectManagerPrivate();

    void init();

    ProductObjectManager *const   q_ptr;
    QVector<ProductObject *>      m_productList;
    // HNIDatabase                   m_db;
};

#endif //QTHNI_PRODUCTOBJECTMANAGER_P_H
