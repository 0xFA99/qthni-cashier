#include "hmaterialsmallproduct.h"
#include "hmaterialsmallproduct_p.h"

#include <QGridLayout>
#include <QSizePolicy>
#include <QLabel>

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

    m_layout = new QGridLayout(q);
    m_image = new QLabel(q);
    m_title = new HMaterialLabel("Unknown", q);
    m_price = new HMaterialLabel("0", q);
    m_amount = new HMaterialLabel("x1", q);

    m_price->setAlignment(Qt::AlignRight);

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

HMaterialSmallProduct::HMaterialSmallProduct(const QString &image, const QString &title, int price, QWidget *parent)
    : HMaterialFrame(HMaterial::Level1, parent)
    , d_ptr(new HMaterialSmallProductPrivate(this))
{
    d_func()->init();
    
    setImage(image);
    setTitle(title);
    setPrice(price);

    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
}

HMaterialSmallProduct::~HMaterialSmallProduct()
{
}

void HMaterialSmallProduct::setImage(const QString &path)
{
    Q_D(HMaterialSmallProduct);

    d->m_image->setPixmap(QPixmap(path).scaled(100, 100, Qt::KeepAspectRatio));
}

QPixmap HMaterialSmallProduct::image() const
{
    Q_D(const HMaterialSmallProduct);

    return d->m_image->pixmap();
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
