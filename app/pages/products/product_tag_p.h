#ifndef QTHNI_PRODUCT_TAG_P_H
#define QTHNI_PRODUCT_TAG_P_H

#include <QObject>
#include <QVector>

class QSqlDatabase;
class ProductTag;
class ProductTagPrivate
{
    Q_DISABLE_COPY(ProductTagPrivate)
    Q_DECLARE_PUBLIC(ProductTag)

public:
    explicit ProductTagPrivate(ProductTag *parent);
    ~ProductTagPrivate();

    void init();

    ProductTag *const       q_ptr;
    QVector<QString>        m_tagList;
    QSqlDatabase            m_database;
};

#endif //QTHNI_PRODUCT_TAG_P_H
