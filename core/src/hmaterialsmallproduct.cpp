#include "hmaterialsmallproduct.h"
#include "hmaterialsmallproduct_p.h"

#include <QGridLayout>
#include <QSizePolicy>

#include "hmaterialtheme.h"

HMaterialSmallProductPrivate::HMaterialSmallProductPrivate(HMaterialSmallProduct *q)
    : q_ptr(q)
{
}

HMaterialSmallProductPrivate::~HMaterialSmallProductPrivate()
{
}

void HMaterialSmallProductPrivate::init()
{
    Q_Q(HMaterialSmallProduct);

    m_layout    = new QGridLayout(q);
    m_image     = new HMaterialImage(QImage(":/images/images/ANDRO.png"), q);
    m_title     = new HMaterialLabel("Unknown", q);
    m_price     = new HMaterialLabel("0", q);
    m_amount    = new HMaterialLabel("x1", q);

    m_image->setFixedSize(QSize(50, 50));
    m_price->setAlignment(Qt::AlignRight);

    m_price->setLabelRole(HMaterial::Secondary);
    m_amount->setLabelRole(HMaterial::Secondary);

    m_layout->addWidget(m_image, 0, 0, 2, 1);
    m_layout->addWidget(m_title, 0, 1, 1, 2);
    m_layout->addWidget(m_amount, 1, 1);
    m_layout->addWidget(m_price, 1, 2);
}

HMaterialSmallProduct::HMaterialSmallProduct(QWidget *parent)
    : HMaterialFrame(HMaterial::Level1, parent)
    , d_ptr(new HMaterialSmallProductPrivate(this))
{
    d_func()->init();

    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
}

HMaterialSmallProduct::HMaterialSmallProduct(const QString &title, QWidget *parent)
    : HMaterialFrame(HMaterial::Level1, parent)
    , d_ptr(new HMaterialSmallProductPrivate(this))
{
    d_func()->init();
    
    setTitle(title);
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
}

HMaterialSmallProduct::~HMaterialSmallProduct()
{
}

void HMaterialSmallProduct::setImage(const QImage &image)
{
    Q_D(HMaterialSmallProduct);

    d->m_image->setImage(image);
    d->m_image->setSize(50);
}

void HMaterialSmallProduct::setTitle(const QString &text)
{
    Q_D(HMaterialSmallProduct);

    d->m_title->setText(text);
}

QString HMaterialSmallProduct::title() const
{
    Q_D(const HMaterialSmallProduct);

    return d->m_title->text();
}

void HMaterialSmallProduct::setPrice(int price)
{
    Q_D(HMaterialSmallProduct);

    d->m_price->setText(QString::number(price));
}

int HMaterialSmallProduct::price() const
{
    Q_D(const HMaterialSmallProduct);

    return d->m_price->text().toInt();
}

void HMaterialSmallProduct::increaseAmount()
{
    Q_D(HMaterialSmallProduct);
    
    QString amount(d->m_amount->text());

    int temp = amount.split("x")[1].toInt();
    QString result("x" + QString::number(temp + 1));

    d->m_amount->setText(result);
}

void HMaterialSmallProduct::decreaseAmount()
{
    Q_D(HMaterialSmallProduct);

    if (d->m_amount->text().toInt() > 1) {
        QString amount = d->m_amount->text();

        int temp = amount.split("x")[1].toInt();
        QString result = QString("x" + QString::number(temp - 1));

        d->m_amount->setText(result);
    }
}

int HMaterialSmallProduct::amount() const
{
    Q_D(const HMaterialSmallProduct);

    return d->m_amount->text().toInt();
}
