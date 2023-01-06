#ifndef QTHNI_HNIDATABASE_H
#define QTHNI_HNIDATABASE_H

#include <QUuid>
#include <QString>
#include <QVector>
#include <QtSql/QSqlDatabase>

class ProductObject;
class MemberObject;
class HNIDatabase
{
public:
    HNIDatabase();
    explicit HNIDatabase(const QString&);

    static bool tryAddProduct(ProductObject&);
    // static QVector<ProductObject*> getAllProduct();
    static void tryUpdateProduct(const QUuid&, ProductObject&);
    static void tryDeleteProduct(const QUuid&);

    static bool addMember(MemberObject&);
    static void updateMember(const QUuid&, MemberObject&);
    static void deleteMember(const QUuid&);

    static QVector<ProductObject *> getAllProduct();
    static QVector<MemberObject *> getAllMember();

    // static void tryAddTag(const QString &name);

private:
    QSqlDatabase m_db;

};


#endif //QTHNI_HNIDATABASE_H
