#include "horderprice.h"
#include "horderprice_p.h"

#include <QPainter>
#include <QPainterPath>
#include <QGridLayout>

HOrderPricePrivate::HOrderPricePrivate(HOrderPrice *q)
    : q_ptr(q)
{
}

HOrderPricePrivate::~HOrderPricePrivate()
{
}

void HOrderPricePrivate::init()
{
    Q_Q(HOrderPrice);

    m_layout    = new QGridLayout(q);
    m_subTotal  = new HMaterialCurrency(0, q);
    m_discount  = new HMaterialCurrency(0, q);
    m_total     = new HMaterialCurrency(0, q);
    m_button    = new HMaterialFlatButton("Check Out", q);

    m_button->setBackgroundColor(QColor(225, 231, 255));
    m_button->setForegroundColor(QColor(101, 126, 248));
    m_button->setHaloVisible(false);
    m_button->setBaseOpacity(1);
    m_button->setCornerRadius(m_button->sizeHint().height() / 2);
    m_button->setOverlayStyle(HMaterial::TintedOverlay);
    m_button->setBackgroundMode(Qt::OpaqueMode);

    m_subTotal->setFontSize(14);
    m_discount->setFontSize(14);

    m_subTotal->setTextColor(QColor(0, 0, 0, 166));
    m_discount->setTextColor(QColor(0, 0, 0, 166));

    HMaterialLabel *title = new HMaterialLabel("Purchase Total Price", q);

    HMaterialLabel *subTotal = new HMaterialLabel("Sub Total", q);
    subTotal->setTextColor(QColor(0, 0, 0, 166));
    subTotal->setFontSize(14);

    HMaterialLabel *discount = new HMaterialLabel("Discount", q);
    discount->setTextColor(QColor(0, 0, 0, 166));
    discount->setFontSize(14);

    HMaterialLabel *total = new HMaterialLabel("Total", q);

    m_layout->addWidget(title, 0, 0, 1, 2);
    m_layout->addWidget(subTotal, 1, 0, 1, 1);
    m_layout->addWidget(m_subTotal, 1, 1, 1, 1);
    m_layout->addWidget(discount, 2, 0, 1, 1); 
    m_layout->addWidget(m_discount, 2, 1, 1, 1);
    m_layout->addWidget(total, 3, 0, 1, 1);
    m_layout->addWidget(m_total, 3, 1, 1, 1);
    m_layout->setRowStretch(4, 1);
    m_layout->addWidget(m_button, 5, 0, 1, 2);
    
    m_layout->setContentsMargins(16, 16, 16, 16);
    m_layout->setSpacing(32);
}

HOrderPrice::HOrderPrice(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HOrderPricePrivate(this))
{
    d_func()->init();
}

HOrderPrice::~HOrderPrice()
{
}

void HOrderPrice::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);

    QPainterPath path;
    path.addRoundedRect(rect(), 16, 16);
    painter.setClipPath(path);
    painter.setClipping(true);

    painter.setOpacity(1);
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);
    painter.drawRect(rect());

    QRect line(16, 46, rect().width() - 32, 1);
    QRect line2(16, 148, rect().width() - 16, 148);

    painter.fillRect(line, QColor("#f1f4f9"));
    painter.setPen(QPen(QColor(0, 0, 0, 115), 2, Qt::DashLine));
    painter.drawLine(line2.x(), line2.y(), line2.width(), line2.height());
}
