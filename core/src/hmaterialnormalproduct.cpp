#include "hmaterialnormalproduct.h"
#include "hmaterialnormalproduct_p.h"

#include <QGridLayout>

HMaterialNormalProductPrivate::HMaterialNormalProductPrivate(HMaterialNormalProduct *q)
    : q_ptr(q)
{
}

HMaterialNormalProductPrivate::~HMaterialNormalProductPrivate()
{
}

void HMaterialNormalProductPrivate::init()
{
    Q_D(HMaterialNormalProduct);

    m_layout = new QGridLayout(q);
    m_image = new HMaterialImage(q);
    m_title = new HMaterialLabel(q);
    m_price = new HMaterialLabel(q);
    m_amount = new HMaterialLabel(q);

}

HMaterialNormalProduct::HMaterialNormalProduct(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HMaterialNormalProductPrivate(this))
{
    d_func()->init();
}

HMaterialNormalProduct::~HMaterialNormalProduct()
{
}

void HMaterialNormalProduct::setImage(const QImage &image)
{
    Q_D(HMaterialNormalProduct);

}

QImage HMaterialNormalProduct::image() const
{
    Q_D(const HMaterialNormalProduct);
}

void HMaterialNormalProduct::setTitle(const QString &text)
{
    Q_D(HMaterialNormalProduct);
}

QString HMaterialNormalProduct::title() const
{
    Q_D(const HMaterialNormalProduct);
}

void HMaterialNormalProduct::setPrice(int price)
{
    Q_D(HMaterialNormalProduct);
}

int HMaterialNormalProduct::price() const
{
    Q_D(const HMaterialNormalProduct);
}

