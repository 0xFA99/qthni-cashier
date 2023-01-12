#include "database/HNIDatabase.h"

#include <QDebug>
#include <QBuffer>
#include <QImage>
#include <QUuid>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

#include "products/ProductObject.h"
#include "members/MemberObject.h"

HNIDatabase::HNIDatabase() = default;

HNIDatabase::HNIDatabase(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open()) {
        qDebug() << "DB - Error - Connection Failed";
    } else {
        qDebug() << "DB - Success - Connection Success";
    }
}

bool HNIDatabase::tryAddProduct(ProductObject& product)
{
    bool success = false;
    QSqlQuery query;

    query.prepare("INSERT INTO products(id, image, name, status, member_price, customer_price, stock, point) "
                  "VALUES (:id, :image, :name, :status, :member_price, :customer_price, :stock, :point); ");

    // Convert QImage to ByteArray
    QImage image = product.image();

    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::WriteOnly);
    image.save(&buffer, "PNG");

    query.bindValue(":image", byteArray);
    query.bindValue(":id", product.uuid());
    query.bindValue(":name", product.name());

    if (product.stock() == 0) {
        query.bindValue(":status", "out_of_stock");
    } else if (product.stock() < 5) {
        query.bindValue(":status", "running_low");
    } else {
        query.bindValue(":status", "in_stock");
    }

    query.bindValue(":member_price", product.memberPrice());
    query.bindValue(":customer_price", product.customerPrice());
    query.bindValue(":stock", product.stock());
    query.bindValue(":point", product.point());

    if (query.exec()) {
        success = true;
    } else {
        qDebug() << "DB - Error - Insert Member: " << query.lastError();
    }

    query.prepare("INSERT INTO suppliers(product_id, quantity) VALUES(:pro_id, :quantity);");
    query.bindValue(":pro_id", product.uuid());
    query.bindValue(":quantity", product.stock());

    if (!query.exec()) {
        qDebug() << "Error: " << query.lastError();
    }

    return success;
}

QVector<ProductObject*> HNIDatabase::getAllProduct()
{
    QVector<ProductObject*> allProduct;
    QSqlQuery query;
    query.setForwardOnly(true); // Optimization
    if (query.exec("SELECT * FROM products")) {
        while (query.next()) {

            auto loadProduct = new ProductObject;

            loadProduct->setUUID(query.value(0).toUuid());

            // Covert ByteArray to QImage
            QByteArray byteArray = query.value(1).toByteArray();
            QImage image;
            image.loadFromData(byteArray);

            loadProduct->setImage(image);
            loadProduct->setName(query.value(2).toString());
            loadProduct->setStatus(query.value(3).toString());
            loadProduct->setMemberPrice(query.value(4).toInt());
            loadProduct->setCustomerPrice(query.value(5).toInt());
            loadProduct->setStock(query.value(6).toInt());
            loadProduct->setPoint(query.value(7).toInt());

            allProduct.push_back(loadProduct);
        }
    }

    return allProduct;
}

QVector<MemberObject *> HNIDatabase::getAllMember()
{
    QVector<MemberObject *> allMember;
    QSqlQuery query;
    query.setForwardOnly(true);
    if (query.exec("SELECT * FROM users")) {
        while (query.next()) {

            auto loadMember = new MemberObject;
            loadMember->setUUID(query.value(0).toUuid());

            QByteArray byteArray = query.value(1).toByteArray();
            QImage image;
            image.loadFromData(byteArray);

            loadMember->setImage(image);
            loadMember->setName(query.value(2).toString());
            loadMember->setID(query.value(3).toString());

            allMember.push_back(loadMember);
        }
    }

    return allMember;
}

void HNIDatabase::tryUpdateProduct(const QUuid& uuid, ProductObject& product)
{
    QSqlQuery query;

    query.prepare("UPDATE products SET "
                  "image = :image, "
                  "name = :name, "
                  "status = :status, "
                  "member_price = :memPrice, "
                  "customer_price = :cusPrice, "
                  "stock = :stock, "
                  "point = :point "
                  "WHERE id = :uuid");

    query.bindValue(":uuid", uuid);

    QImage image = product.image();
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::WriteOnly);
    image.save(&buffer, "PNG");
    query.bindValue(":image", byteArray);

    query.bindValue(":name", product.name());

    if (product.stock() == 0) {
        query.bindValue(":status", "out_of_stock");
    } else if (product.stock() < 5) {
        query.bindValue(":status", "running_low");
    } else {
        query.bindValue(":status", "in_stock");
    }
    query.bindValue(":memPrice", product.memberPrice());
    query.bindValue(":cusPrice", product.customerPrice());
    query.bindValue(":stock", product.stock());
    query.bindValue(":point", product.point());

    if (query.exec()) {
        qDebug() << "DB - Success - Update Product UUID: " << uuid;
    } else {
        qDebug() << "DB - Error - Update Product UUID: " << uuid;
        qDebug() << "     Error : " << query.lastError();
    }
}

void HNIDatabase::tryDeleteProduct(const QUuid& uuid)
{
    QSqlQuery query;
    query.prepare("DELETE FROM products WHERE id = :uuid;");
    query.bindValue(":uuid", uuid);

    if (query.exec()) {
        qDebug() << "DB - Success - Delete Product UUID: " << uuid;
    } else {
        qDebug() << "DB - Error - Delete Product UUID: " << uuid;
        qDebug() << "     Error : " << query.lastError();
    }
}

bool HNIDatabase::addMember(MemberObject &member)
{
    bool success = false;

    QSqlQuery query;
    query.prepare("INSERT INTO users(id, image, name, member_id) VALUES(:id, :image, :name, :memID)");
    query.bindValue(":id", member.uuid());

    QImage image = member.image();
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::WriteOnly);
    image.save(&buffer, "PNG");

    query.bindValue(":image", byteArray);
    query.bindValue(":name", member.name());
    query.bindValue(":memID", member.id());

    if (query.exec()) {
        success = true;
        qDebug() << "DB - Success - Add Member UUID: " << member.uuid();
    } else {
        qDebug() << "DB - Error - Add Member UUID: " << member.uuid();
        qDebug() << "     Error : " << query.lastError();
    }

    return success;
}

void HNIDatabase::updateMember(const QUuid &uuid, MemberObject &member)
{
    QSqlQuery query;
    query.prepare("UPDATE users SET image = :image, name = :name, member_id = :memID WHERE id = :uuid");
    query.bindValue(":uuid", uuid);
    query.bindValue(":image", member.image());
    query.bindValue(":name", member.name());
    query.bindValue(":memID", member.id());

    if (query.exec()) {
        qDebug() << "DB - Success - Update Member UUID: " << uuid;
    } else {
        qDebug() << "DB - Error - Update Member UUID: " << uuid;
        qDebug() << "     Error : " << query.lastError();
    }
}

void HNIDatabase::deleteMember(const QUuid &uuid)
{
    QSqlQuery query;
    query.prepare("DELETE FROM users WHERE id = :uuid");
    query.bindValue(":uuid", uuid);

    if (query.exec()) {
        qDebug() << "DB - Success - Delete Product UUID: " << uuid;
    } else {
        qDebug() << "DB - Error - Delete Product UUID: " << uuid;
        qDebug() << "     Error : " << query.lastError();
    }
}