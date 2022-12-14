#include "products/product.h"
#include "products/product_p.h"

ProductPrivate::ProductPrivate(Product *q)
    : q_ptr(q)
{
}

ProductPrivate::~ProductPrivate() = default;

void ProductPrivate::init()
{
    Q_Q(Product);

    m_image = QImage();
    m_name  = QString("No Name");
    m_price = 0;
    m_point = 0;
    m_stock = 0;
}

Product::Product(QObject *parent)
    : QObject(parent)
    , d_ptr(new ProductPrivate(this))
{
    d_func()->init();
}

Product::~Product() = default;

void Product::setName(const QString &name)
{
    Q_D(Product);

    d->m_name = name;
}

QString Product::name() const
{
    Q_D(const Product);

    return d->m_name;
}

void Product::setPrice(const int price)
{
    Q_D(Product);

    d->m_price = price;
}

int Product::price() const
{
    Q_D(const Product);

    return d->m_price;
}

void Product::setPoint(const int point)
{
    Q_D(Product);

    d->m_point = point;
}

int Product::point() const
{
    Q_D(const Product);

    return d->m_point;
}

void Product::setStock(const int stock)
{
    Q_D(Product);

    d->m_stock = stock;
}

int Product::stock() const
{
    Q_D(const Product);

    return d->m_stock;
}