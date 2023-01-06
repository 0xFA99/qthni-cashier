#ifndef QTHNI_PRODUCT_TAG_H
#define QTHNI_PRODUCT_TAG_H

#include <QObject>

#include "database/HNIDatabase.h"

class ProductTagPrivate;
class ProductTag : public QObject
{
    Q_OBJECT

public:
    explicit ProductTag(QObject *parent = nullptr);
    // explicit ProductTag(HNIDatabase&, QObject *parent = nullptr);
    ~ProductTag();

    // void setDatabase(HNIDatabase &db);

    void addTag(const QString &text);

protected:
    const QScopedPointer<ProductTagPrivate> d_ptr;

private:
    Q_DISABLE_COPY(ProductTag)
    Q_DECLARE_PRIVATE(ProductTag)
};


#endif //QTHNI_PRODUCT_TAG_H
