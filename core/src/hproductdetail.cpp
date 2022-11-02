#include "hproductdetail.h"
#include "hproductdetail_p.h"

#include <QGridLayout>
#include <QPainter>

HProductDetailPrivate::HProductDetailPrivate(HProductDetail *q)
    : q_ptr(q)
{
}

HProductDetailPrivate::~HProductDetailPrivate()
{
}

void HProductDetailPrivate::init()
{
    Q_Q(HProductDetail);

    m_layout    = new QVBoxLayout(q);
    m_image     = new HMaterialImage(QImage(":/images/images/ANDRO.png"), q);
    m_title     = new HMaterialTextField(q);
    m_customerPrice = new HMaterialTextField(q);
    m_memberPrice   = new HMaterialTextField(q);
    m_closeButton   = new HMaterialFlatButton("BUY NOW", q);

    m_image->setSize(100);

    m_title->setText("Gentoo Linux");
    m_title->setLabel("Product Name");
    m_customerPrice->setLabel("Costumer Price");
    m_memberPrice->setLabel("Member Price");

    m_title->setTextColor(QColor(70, 70, 70));
    m_customerPrice->setTextColor(QColor(70, 70, 70));
    m_memberPrice->setTextColor(QColor(70, 70, 70));

    m_title->setDisabled(true);
    m_customerPrice->setDisabled(true);
    m_memberPrice->setDisabled(true);

    m_customerPrice->setCurrencyFormat(true);
    m_memberPrice->setCurrencyFormat(true);

    m_closeButton->setHaloVisible(false);
    m_closeButton->setOverlayStyle(HMaterial::TintedOverlay);
    m_closeButton->setFontSize(12);

    m_layout->addWidget(m_image);
    m_layout->addWidget(m_title);
    m_layout->addWidget(m_customerPrice);
    m_layout->addWidget(m_memberPrice);
    m_layout->addWidget(m_closeButton);

    QObject::connect(m_closeButton, &QPushButton::clicked, [this]() {
        m_title->setDisabled(false);
        m_customerPrice->setDisabled(false);
        m_memberPrice->setDisabled(false);
    });
}

HProductDetail::HProductDetail(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HProductDetailPrivate(this))
{
    d_func()->init();

    setFixedWidth(250);
    QSizePolicy policy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    setSizePolicy(policy);

}

HProductDetail::~HProductDetail()
{
}

void HProductDetail::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    Q_D(HProductDetail);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);

    QPainter painter(this);
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);
    painter.drawRect(rect());
}
