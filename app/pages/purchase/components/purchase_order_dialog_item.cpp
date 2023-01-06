#include "purchase/components/purchase_order_dialog_item.h"

#include <QHBoxLayout>
#include <QImage>

PurchaseOrderDialogItem::PurchaseOrderDialogItem(QWidget *parent)
    : QWidget(parent)
{
    m_layout     = new QHBoxLayout(this);
    m_avatar    = new QtMaterialAvatar(QImage(":/images/images/profiles/defaultimage.png"), this);
    m_name      = new QLabel(this);
    m_price     = new QLabel(this);
    m_discount  = new QLabel(this);
    m_quantity  = new QLabel(this);
    m_total     = new QLabel(this);
    m_locale    = QLocale("id_ID");

    m_avatar->setSize(42);
    m_avatar->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    m_layout->addWidget(m_avatar);

    QFont font("Roboto", 12, QFont::Normal);
    m_name->setFont(font);
    m_price->setFont(font);
    m_discount->setFont(font);
    m_quantity->setFont(font);
    m_total->setFont(font);

    m_total->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    m_price->setAlignment(Qt::AlignCenter);
    m_discount->setAlignment(Qt::AlignCenter);
    m_quantity->setAlignment(Qt::AlignCenter);

    m_layout->addWidget(m_name);
    m_layout->addWidget(m_price);
    m_layout->addWidget(m_discount);
    m_layout->addWidget(m_quantity);
    m_layout->addWidget(m_total);
}

PurchaseOrderDialogItem::~PurchaseOrderDialogItem() = default;

void PurchaseOrderDialogItem::paintEvent(QPaintEvent *painter)
{

}

void PurchaseOrderDialogItem::setImage(const QImage &image)
{
    m_avatar->setImage(image);
}

void PurchaseOrderDialogItem::setName(const QString &name)
{
    m_name->setText(name);
}

void PurchaseOrderDialogItem::setPrice(int price)
{
   m_price->setText("Rp " + m_locale.toString(price));
}

void PurchaseOrderDialogItem::setDiscount(int discount)
{
    // m_discount->setText("Rp 0");
    m_discount->setText("Rp " + m_locale.toString(discount));
}

void PurchaseOrderDialogItem::setQuantity(int quantity)
{
    m_quantity->setText(QString::number(quantity));

    // Update Total
    int getPrice = m_price->text().split(" ")[1].replace('.', "").toInt();
    int total = getPrice * quantity;

    m_total->setText("Rp " + m_locale.toString(total));
}

void PurchaseOrderDialogItem::updateQuantity(int quantity)
{
    setQuantity(quantity);
}

void PurchaseOrderDialogItem::setUUID(const QUuid &uuid)
{
    m_uuid = uuid;
}

QUuid
PurchaseOrderDialogItem::uuid() const
{
    return m_uuid;
}