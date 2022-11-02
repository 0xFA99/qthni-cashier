#include "hproductnormalview.h"
#include "hproductnormalview_p.h"

#include <QVBoxLayout>
#include <QPainter>
#include <QFont>

HProductNormalViewPrivate::HProductNormalViewPrivate(HProductNormalView *q)
    : q_ptr(q)
{
}

HProductNormalViewPrivate::~HProductNormalViewPrivate()
{
}

void HProductNormalViewPrivate::init()
{
    Q_Q(HProductNormalView);

    m_layout        = new QVBoxLayout(q);
    m_image         = new HMaterialImage(QImage(":/images/images/vas.png"), q);
    m_title         = new HMaterialLabel("Concrete Ceramic", q);
    m_price         = new HMaterialLabel("Rp 1.000.000", q);
    m_button        = new HMaterialFlatButton("BUY NOW", q);

    m_title->setAlignment(Qt::AlignCenter);
    m_price->setAlignment(Qt::AlignCenter);
    m_price->setTextColor(QColor(38, 115, 221));
    m_button->setMinimumHeight(50);

    m_layout->setSpacing(10);
    m_layout->setContentsMargins(10, 10, 10, 30);
    m_layout->addWidget(m_image);
    m_layout->addWidget(m_title);
    m_layout->addWidget(m_price);
    m_layout->addWidget(m_button);
}

HProductNormalView::HProductNormalView(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HProductNormalViewPrivate(this))
{
    d_func()->init();
}

HProductNormalView::~HProductNormalView()
{
}

void HProductNormalView::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
   
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);

    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.setOpacity(1);
    painter.setBrush(brush);
    painter.drawRect(rect());
}
