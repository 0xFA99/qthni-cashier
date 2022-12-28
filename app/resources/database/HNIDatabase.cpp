#include "database/HNIDatabase.h"

#include <QDebug>
#include <QBuffer>
#include <QImage>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

HNIDatabase::HNIDatabase() = default;

HNIDatabase::HNIDatabase(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open()) {
        qDebug() << "Error: connection with database failed";
    } else {
        qDebug() << "Database: connection OK!";
    }
}

bool HNIDatabase::tryAddProduct(ProductObject *product)
{
    bool success = false;
    QSqlQuery query;

    query.prepare("INSERT INTO Product(image, name, price, stock, point) VALUES(:image, :name, :price, :stock, :point)");

    // Convert QImage to ByteArray
    QImage image = product->image();

    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::WriteOnly);
    image.save(&buffer, "PNG");

    query.bindValue(":image", byteArray);
    query.bindValue(":name", product->name());
    query.bindValue(":price", product->price());
    query.bindValue(":stock", product->stock());
    query.bindValue(":point", product->point());

    if (query.exec()) {
        success = true;
    } else {
        qDebug() << "Add Product error:" << query.lastError();
    }

    return success;
}

QVector<ProductObject*> HNIDatabase::getAllProduct()
{
    QVector<ProductObject*> allProduct;
    QSqlQuery query;
    query.setForwardOnly(true); // Optimization
    if (query.exec("SELECT * FROM Product")) {
        while (query.next()) {

            auto loadProduct = new ProductObject;

            // Covert ByteArray to QImage
            QByteArray byteArray = query.value(0).toByteArray();
            QImage image;
            image.loadFromData(byteArray);

            loadProduct->setImage(image);
            loadProduct->setName(query.value(1).toString());
            loadProduct->setPrice(query.value(2).toInt());
            loadProduct->setStock(query.value(3).toInt());
            loadProduct->setPoint(query.value(4).toInt());

            allProduct.push_back(loadProduct);
        }
    }

    return allProduct;
}

void HNIDatabase::tryUpdateProduct(const QString &key, ProductObject *product)
{
    QSqlQuery query;

    query.prepare("UPDATE Product SET "
               "image = :image, "
               "name = :name, "
               "price = :price, "
               "stock = :stock, "
               "point = :point "
               "WHERE name = :key");

    QImage image = product->image();

    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::WriteOnly);
    image.save(&buffer, "PNG");

    query.bindValue(":key", key);
    query.bindValue(":image", byteArray);
    query.bindValue(":name", product->name());
    query.bindValue(":price", product->price());
    query.bindValue(":stock", product->stock());
    query.bindValue(":point", product->point());

    if (!query.exec())
        qDebug() << "Failed Update Product: " << query.lastError();
}

void HNIDatabase::tryDeleteProduct(const QString &name)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Product WHERE name = :name;");

    query.bindValue(":name", name);

    if (!query.exec())
        qDebug() << "Failed Delete Product: " << query.lastError();
}