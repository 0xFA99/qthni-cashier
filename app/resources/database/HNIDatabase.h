#ifndef QTHNI_HNIDATABASE_H
#define QTHNI_HNIDATABASE_H

#include <QString>
#include <QVector>
#include <QtSql/QSqlDatabase>

#include "products/ProductObject.h"

class HNIDatabase
{
public:
    HNIDatabase();
    explicit HNIDatabase(const QString&);

    static bool tryAddProduct(ProductObject*);
    static QVector<ProductObject*> getAllProduct();
    static void tryUpdateProduct(const QString &key, ProductObject*);
    static void tryDeleteProduct(const QString &name);

private:
    QSqlDatabase m_db;

};


#endif //QTHNI_HNIDATABASE_H
