#include "hnotificationpage.h"
#include "hnotificationpage_p.h"

#include <QPainter>
#include <QHBoxLayout>

HNotificationPagePrivate::HNotificationPagePrivate(HNotificationPage *q)
    : q_ptr(q)
{
}

HNotificationPagePrivate::~HNotificationPagePrivate()
{
}

void HNotificationPagePrivate::init()
{
    Q_Q(HNotificationPage);

    m_layout        = new QHBoxLayout(q);
    m_constructor   = new HConstructorPage(q);

    m_layout->addWidget(m_constructor);
    m_layout->setContentsMargins(20, 16, 20, 16);
}

HNotificationPage::HNotificationPage(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HNotificationPagePrivate(this))
{
    d_func()->init();
}

HNotificationPage::~HNotificationPage()
{
}

void HNotificationPage::paintEvent(QPaintEvent *event)
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
