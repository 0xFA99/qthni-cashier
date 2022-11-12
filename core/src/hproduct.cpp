#include "hproduct.h"
#include "hproduct_p.h"

HProductPrivate::HProductPrivate(HProduct *q)
    : q_ptr(q)
{
}

HProductPrivate::~HProductPrivate()
{
}

void HProductPrivate::init()
{
    Q_Q(HProduct);

    m_image = QImage(":/images/images/default.png");
    m_name  = QString("Untitled");
    m_price = 0;
    m_stock = 0;
}

HProduct::HProduct(QObject *parent)
    : QObject(parent)
    , d_ptr(new HProductPrivate(this))
{
    d_func()->init();
}

HProduct::~HProduct()
{
}

void HProduct::setImage(const QImage &image)
{
    Q_D(HProduct);

    d->m_image = image;
}

QImage HProduct::image() const
{
    Q_D(const HProduct);

    return d->m_image;
}

void HProduct::setName(const QString &name)
{
    Q_D(HProduct);

    d->m_name = name;
}

QString HProduct::name() const
{
    Q_D(const HProduct);

    return d->m_name;
}

void HProduct::setPrice(int price)
{
    Q_D(HProduct);

    d->m_price = price;
}

int HProduct::price() const
{
    Q_D(const HProduct);

    return d->m_price;
}

void HProduct::setStock(int value)
{
    Q_D(HProduct);

    d->m_stock = value;
}

int HProduct::stock() const
{
    Q_D(const HProduct);

    return d->m_stock;
}

void HProduct::updateSlot()
{
    Q_D(HProduct);

    emit updateSignal(this);
}