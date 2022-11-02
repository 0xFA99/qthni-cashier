#include "hmemberpage.h"
#include "hmemberpage_p.h"

#include <QPainter>
#include <QGridLayout>

HMemberPagePrivate::HMemberPagePrivate(HMemberPage *q)
    : q_ptr(q)
{
}

HMemberPagePrivate::~HMemberPagePrivate()
{
}

void HMemberPagePrivate::init()
{
    Q_Q(HMemberPage);

    m_layout        = new QGridLayout(q);
    m_memberList    = new HMemberList(q);

    m_layout->addWidget(m_memberList);

    m_layout->setContentsMargins(20, 16, 20, 16);
}

HMemberPage::HMemberPage(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HMemberPagePrivate(this))
{
    d_func()->init();
}

HMemberPage::~HMemberPage()
{
}

void HMemberPage::paintEvent(QPaintEvent *event)
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
