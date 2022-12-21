#include "products/ProductObject.h"
#include "products/ProductObject_p.h"

ProductObjectPrivate::ProductObjectPrivate(ProductObject *q)
    : q_ptr(q)
{
}

ProductObjectPrivate::~ProductObjectPrivate() = default;

void ProductObjectPrivate::init()
{
    Q_Q(ProductObject);

    m_image         = QImage(":/images/images/profiles/defaultimage.png");
    m_name          = QString("No Name");
    m_price         = 0;
    m_point         = 0;
    m_stock         = 0;
    m_locale        = QLocale("id_ID");
    m_observerList  = QVector<IObserver *>();
}

ProductObject::ProductObject(QObject *parent)
    : QObject(parent)
    , d_ptr(new ProductObjectPrivate(this))
{
    d_func()->init();
}

ProductObject::~ProductObject() = default;

void ProductObject::setImage(const QImage &image)
{
    Q_D(ProductObject);

    d->m_image = image;
}

QImage ProductObject::image() const
{
    Q_D(const ProductObject);

    return d->m_image;
}

void ProductObject::setName(const QString &name)
{
    Q_D(ProductObject);

    d->m_name = name;
}

QString ProductObject::name() const
{
    Q_D(const ProductObject);

    return d->m_name;
}

void ProductObject::setPrice(const int price)
{
    Q_D(ProductObject);

    d->m_price = price;
}

int ProductObject::price() const
{
    Q_D(const ProductObject);

    return d->m_price;
}

void ProductObject::setPoint(const int point)
{
    Q_D(ProductObject);

    d->m_point = point;
}

int ProductObject::point() const
{
    Q_D(const ProductObject);

    return d->m_point;
}

void ProductObject::setStock(const int stock)
{
    Q_D(ProductObject);

    d->m_stock = stock;
}

int ProductObject::stock() const
{
    Q_D(const ProductObject);

    return d->m_stock;
}

void
ProductObject::Attach(IObserver *observer)
{
    Q_D(ProductObject);

    d->m_observerList.push_back(observer);
}

void
ProductObject::Detach(IObserver *observer)
{
    Q_D(ProductObject);

    d->m_observerList.removeOne(observer);
}

void
ProductObject::Update()
{
    Q_D(ProductObject);

    int price_format;
    QVector<IObserver *>::iterator iterator = d->m_observerList.begin();
    while (iterator != d->m_observerList.end()) {
        price_format = price();
        (*iterator)->Update(image(), name(), QString("Rp " + d->m_locale.toString(price_format)));
        ++iterator;
    }
}

void
ProductObject::editProduct(ProductObject *product)
{
    setImage(product->image());
    setName(product->name());
    setPrice(product->price());
    setStock(product->stock());
    setPoint(product->point());
}