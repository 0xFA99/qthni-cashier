#include "hproductitem.h"
#include "hproductitem_p.h"

#include <QGridLayout>

HProductItemPrivate::HProductItemPrivate(HProductItem *q)
    : q_ptr(q)
{
}

HProductItemPrivate::~HProductItemPrivate()
{
}

void HProductItemPrivate::init()
{
    Q_Q(HProductItem);

    m_layout        = new QGridLayout(q);
    m_image         = new HMaterialAvatar(QImage(":/images/images/default.png"), q);
    m_name          = new HMaterialLabel("Untitled", q);
    m_price         = new HMaterialCurrency(0, q);
    m_stock         = new HMaterialBadge("0", m_image);
    m_editButton    = new HMaterialFlatButton("\uE626", q);
    m_removeButton  = new HMaterialFlatButton("\uE61F", q);

    m_image->setSize(48);
    m_image->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);

    m_stock->setRelativePosition(12, 12);

    m_name->setAlignment(Qt::AlignBottom);

    m_price->setTextColor(QColor("#657ef8"));
    m_price->setAlignment(Qt::AlignTop);
    m_price->setFontSize(12);

    QFont font("iconfont", 15, QFont::Medium);

    m_editButton->setFont(font);
    m_editButton->setForegroundColor(QColor("#8592a3"));
    m_editButton->setFixedWidth(m_editButton->sizeHint().height());
    m_editButton->setHaloVisible(false);
    m_editButton->setRippleStyle(HMaterial::NoRipple);

    m_removeButton->setFont(font);
    m_removeButton->setForegroundColor(QColor("#ff6273"));
    m_removeButton->setFixedWidth(m_removeButton->sizeHint().height());
    m_removeButton->setHaloVisible(false);
    m_removeButton->setRippleStyle(HMaterial::NoRipple);

    QObject::connect(
            m_editButton, &QPushButton::clicked,
            q, &HProductItem::editSlot
            );
    QObject::connect(
            m_removeButton, &QPushButton::clicked,
            q, &HProductItem::removeSlot
            );

    m_layout->addWidget(m_image, 0, 0, 2, 1);
    m_layout->addWidget(m_name, 0, 1, 1, 1);
    m_layout->addWidget(m_price, 1, 1, 1, 1);
    m_layout->addWidget(m_editButton, 0, 2, 2, 1);
    m_layout->addWidget(m_removeButton, 0, 3, 2, 1);
    m_layout->setContentsMargins(0, 0, 0, 0);
}

HProductItem::HProductItem(HProduct *product, QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HProductItemPrivate(this))
{
    d_func()->init();

    setProductObject(product);
}

HProductItem::~HProductItem() = default;

void HProductItem::setProductObject(HProduct *product)
{
    Q_D(HProductItem);

    d->m_product = product;

    d->m_image->setImage(product->image());
    d->m_name->setText(product->name());
    d->m_price->setMoney(product->price());
    d->m_stock->setText(QString::number(product->stock()));

    QObject::connect(d->m_product, &HProduct::updateSignal, this, &HProductItem::updateProduct);
}

void HProductItem::removeSlot()
{
    Q_D(HProductItem);

    emit removeItem(d->m_product->name());
}

void HProductItem::editSlot()
{
    Q_D(HProductItem);

    emit editItem(d->m_product);
}

QString HProductItem::name() const
{
    Q_D(const HProductItem);

    return d->m_name->text();
}

void HProductItem::updateProduct(HProduct *product)
{
    Q_D(HProductItem);

    d->m_image->setImage(product->image());
    d->m_name->setText(product->name());
    d->m_price->setMoney(product->price());
    d->m_stock->setText(QString::number(product->stock()));
}