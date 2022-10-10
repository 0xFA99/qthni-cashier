#include "hmaterialnormalproduct.h"
#include "hmaterialnormalproduct_p.h"

#include <QGridLayout>

#include "hmaterialtheme.h"

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

    m_layout = new QGridLayout(q);

    m_image = new HMaterialImage(QImage(":/images/images/ANDRO.png"), q);
    m_title = new HMaterialLabel("Untitle", q);
    m_price = new HMaterialCurrency(0, q);
    m_amount = new HMaterialLabel("1", q);
    m_total = new HMaterialLabel("1", q);
    m_priceLabel = new HMaterialLabel("Harga");
    m_leftLabel  = new HMaterialLabel("Sisa");

    m_chooseButton = new HMaterialFlatButton("Pilih", q);
    m_increaseButton = new HMaterialButton("+", q);
    m_decreaseButton = new HMaterialButton("-", q);

    m_image->setSize(100);
    m_image->setMinimumHeight(100);

    m_title->setAlignment(Qt::AlignCenter);
    m_amount->setAlignment(Qt::AlignRight);
    m_leftLabel->setAlignment(Qt::AlignRight);
    m_price->setAlignment(Qt::AlignLeft);
    m_total->setAlignment(Qt::AlignCenter);

    m_chooseButton->setUseThemeColors(true);
    m_chooseButton->setHaloVisible(false);
    m_chooseButton->setRole(HMaterial::Primary);
    m_chooseButton->setBackgroundMode(Qt::OpaqueMode);

    m_increaseButton->hide();
    m_total->hide();
    m_decreaseButton->hide();

    m_layout->addWidget(m_image, 0, 0, 1, 4);
    m_layout->addWidget(m_title, 1, 0, 1, 4);
    m_layout->addWidget(m_priceLabel, 2, 0, 1, 2);
    m_layout->addWidget(m_price, 3, 0, 1, 2);
    m_layout->addWidget(m_leftLabel, 2, 2, 1, 2);
    m_layout->addWidget(m_amount, 3, 2, 1, 2);
    m_layout->addWidget(m_chooseButton, 4, 0, 1, 4);
}

HMaterialNormalProduct::HMaterialNormalProduct(QWidget *parent)
    : HMaterialFrame(parent)
    , d_ptr(new HMaterialNormalProductPrivate(this))
    , mode(false)
{
    Q_D(HMaterialNormalProduct);
    d_func()->init();

    QObject::connect(d->m_chooseButton, &QPushButton::clicked, [this]() {
        swapMode();
            });
}

HMaterialNormalProduct::~HMaterialNormalProduct()
{
}

void HMaterialNormalProduct::setImage(const QImage &image)
{
    Q_D(HMaterialNormalProduct);

    d->m_image->setImage(image);
}

QImage HMaterialNormalProduct::image() const
{
    Q_D(const HMaterialNormalProduct);
}

void HMaterialNormalProduct::setTitle(const QString &text)
{
    Q_D(HMaterialNormalProduct);

    return d->m_title->setText(text);
}

QString HMaterialNormalProduct::title() const
{
    Q_D(const HMaterialNormalProduct);

    return d->m_title->text();
}

void HMaterialNormalProduct::setPrice(int price)
{
    Q_D(HMaterialNormalProduct);

    d->m_price->setMoney(price);
}

int HMaterialNormalProduct::price() const
{
    Q_D(const HMaterialNormalProduct);

    return d->m_price->money();
}

void HMaterialNormalProduct::swapMode()
{
    Q_D(HMaterialNormalProduct);
    
    if (mode == false) {
        d->m_layout->removeWidget(d->m_chooseButton);

        d->m_layout->addWidget(d->m_chooseButton, 4, 0);
        d->m_layout->addWidget(d->m_decreaseButton, 4, 1);
        d->m_layout->addWidget(d->m_total, 4, 2);
        d->m_layout->addWidget(d->m_increaseButton, 4, 3);

        d->m_decreaseButton->show();
        d->m_total->show();
        d->m_increaseButton->show();

        d->m_chooseButton->setText("X");
        d->m_chooseButton->setRole(HMaterial::Secondary);

        mode = true;
    } else {
        d->m_layout->removeWidget(d->m_chooseButton);

        d->m_decreaseButton->hide();
        d->m_total->hide();
        d->m_increaseButton->hide();

        d->m_layout->removeWidget(d->m_decreaseButton);
        d->m_layout->removeWidget(d->m_total);
        d->m_layout->removeWidget(d->m_increaseButton);

        d->m_layout->addWidget(d->m_chooseButton, 4, 0, 1, 4);

        d->m_chooseButton->setText("Pilih");
        d->m_chooseButton->setRole(HMaterial::Primary);

        mode = false;
    }
}
