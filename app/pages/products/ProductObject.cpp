#include "products/ProductObject.h"
#include "products/ProductObject_p.h"

#include <QUuid>

ProductObjectPrivate::ProductObjectPrivate(ProductObject *q)
    : q_ptr(q)
{
}

ProductObjectPrivate::~ProductObjectPrivate() = default;

void ProductObjectPrivate::init()
{
    Q_Q(ProductObject);

    m_uuid              = nullptr;
    m_tag               = nullptr;
    m_image             = QImage(":/images/images/profiles/defaultimage.png");
    m_name              = QString("No Name");
    m_member_price      = 0;
    m_customer_price    = 0;
    m_point             = 0;
    m_stock             = 0;
    m_locale            = QLocale("id_ID");
    m_observerList      = QVector<IObserver *>();
}

ProductObject::ProductObject(QObject *parent)
    : QObject(parent)
    , d_ptr(new ProductObjectPrivate(this))
{
    d_func()->init();
}

ProductObject::~ProductObject() = default;

void ProductObject::setUUID(QUuid uuid)
{
    Q_D(ProductObject);

    d->m_uuid = uuid;
}

QUuid ProductObject::uuid() const
{
    Q_D(const ProductObject);

    return d->m_uuid;
}

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

void
ProductObject::setTagUUID(const QUuid &uuid)
{
    Q_D(ProductObject);

    d->m_tag = uuid;
}

QUuid
ProductObject::tagUUID() const
{
    Q_D(const ProductObject);

    return d->m_tag;
}

void
ProductObject::setStatus(const QString &status)
{
    Q_D(ProductObject);

    d->m_status = status;
}

QString
ProductObject::status() const
{
    Q_D(const ProductObject);

    return d->m_status;
}

void
ProductObject::setMemberPrice(int price)
{
    Q_D(ProductObject);

    d->m_member_price = price;
}

int
ProductObject::memberPrice() const
{
    Q_D(const ProductObject);

    return d->m_member_price;
}

void
ProductObject::setCustomerPrice(int price)
{
    Q_D(ProductObject);

    d->m_customer_price = price;
}

int
ProductObject::customerPrice() const
{
    Q_D(const ProductObject);

    return d->m_customer_price;
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

    QVector<IObserver *>::iterator iterator = d->m_observerList.begin();
    while (iterator != d->m_observerList.end()) {
        (*iterator)->Update(image(), name(), "");
        (*iterator)->ExtraUpdate(tagUUID(), memberPrice(), customerPrice(), point(), stock());
        ++iterator;
    }
}

void
ProductObject::editProduct(ProductObject& product)
{
    setImage(product.image());
    setName(product.name());
    // setTagUUID(product.tagUUID());
    setMemberPrice(product.memberPrice());
    setCustomerPrice(product.customerPrice());
    setStock(product.stock());
    setPoint(product.point());
}