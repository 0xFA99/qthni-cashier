#include "hoptionpage.h"
#include "hoptionpage_p.h"

#include <QPainter>
#include <QHBoxLayout>

HOptionPagePrivate::HOptionPagePrivate(HOptionPage *q)
    : q_ptr(q)
{
}

HOptionPagePrivate::~HOptionPagePrivate()
{
}

void HOptionPagePrivate::init()
{
    Q_Q(HOptionPage);

    m_layout        = new QHBoxLayout(q);
    m_constructor   = new HConstructorPage(q);

    m_layout->addWidget(m_constructor);
    m_layout->setContentsMargins(20, 16, 20, 16);
}

HOptionPage::HOptionPage(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HOptionPagePrivate(this))
{
    d_func()->init();
}

HOptionPage::~HOptionPage()
{
}

void HOptionPage::paintEvent(QPaintEvent *event)
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
