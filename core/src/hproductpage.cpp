#include "hproductpage.h"
#include "hproductpage_p.h"

#include <QPainter>
#include <QHBoxLayout>

HProductPagePrivate::HProductPagePrivate(HProductPage *q)
    : q_ptr(q)
{
}

HProductPagePrivate::~HProductPagePrivate()
{
}

void HProductPagePrivate::init()
{
    Q_Q(HProductPage);

    m_layout        = new QHBoxLayout(q);
    m_constructor   = new HConstructorPage(q);

    m_layout->addWidget(m_constructor);
    m_layout->setContentsMargins(20, 16, 20, 16);
}

HProductPage::HProductPage(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HProductPagePrivate(this))
{
    d_func()->init();
}

HProductPage::~HProductPage()
{
}

void HProductPage::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor("#f5f6fb"));

    QPainter painter(this);
    painter.setOpacity(1);
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);
    painter.drawRect(rect());
}
