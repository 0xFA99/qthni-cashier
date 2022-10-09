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
    Q_Q(HMaterialNormalProduct);

    m_layout            = new QGridLayout(q);

    m_image             = new HMaterialImage(QImage(":/images/images/ANDRO.png", q);
    m_title             = new HMaterialLabel("Untitle", q);
    m_price             = new HMaterialCurrency(0, q);
    m_amount            = new HMaterialLabel("0", q);
    m_total             = new HMaterialLabel("1", q);

    m_chooseButton      = new HMaterialButton("Pilih", q);
    m_increaseButton    = new HMaterialButton("+", q);
    m_decreaseButton    = new HMaterialButton("-", q);

    m_layout->addWidget(m_image);
    m_layout->addWidget(m_title);
    m_layout->addWidget(m_price);
    m_layout->addWidget(m_amount);

    m_layout->addWidget(m_decreaseButton);
    m_layout->addWidget(m_total);
    m_layout->addWidget(m_increaseButton);
}

HMaterialNormalProduct::HMaterialNormalProduct(QWidget *parent)
{

}

HMaterialNormalProduct::~HMaterialNormalProduct()
{

}

void HMaterialNormalProduct::setImage(const QImage &image)
{

}

QImage HMaterialNormalProduct::image() const
{

}

void HMaterialNormalProduct::setTitle(const QString &text)
{

}

QString HMaterialNormalProduct::title() const
{

}

void HMaterialNormalProduct::setPrice(int price)
{

}

int HMaterialNormalProduct::price() const
{

}

void HMaterialNormalProduct::setAmount(int amount)
{
    Q_D(HMaterialNormalProduct);

    d->m_amount->
}

int HMaterialNormalProduct::amount() const
{
    Q_D(const HMaterialNormalProduct);

    return d->m_amount->text().toInt();
}
