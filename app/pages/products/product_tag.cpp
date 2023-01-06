#include "products/product_tag.h"
#include "products/product_tag_p.h"

ProductTagPrivate::ProductTagPrivate(ProductTag *q)
    : q_ptr(q)
{
}

ProductTagPrivate::~ProductTagPrivate() = default;

void ProductTagPrivate::init()
{
    Q_Q(ProductTag);

    m_tagList   = QVector<QString>();
}

ProductTag::ProductTag(QObject *parent)
    : QObject(parent)
    , d_ptr(new ProductTagPrivate(this))
{
    d_func()->init();
}
/*
ProductTag::ProductTag(HNIDatabase& db, QObject *parent)
    : QObject(parent)
    , d_ptr(new ProductTagPrivate(this))
{
    d_func()->init();

    setDatabase(db);
}
*/
ProductTag::~ProductTag() = default;

void ProductTag::addTag(const QString &text)
{
    Q_D(ProductTag);

    d->m_tagList.push_back(text);

    // Add into database
    // HNIDatabase::tryAddTag(text);
}