#include "hanalysicpage.h"
#include "hanalysicpage_p.h"

#include <QPainter>
#include <QHBoxLayout>

HAnalysicPagePrivate::HAnalysicPagePrivate(HAnalysicPage *q)
    : q_ptr(q)
{
}

HAnalysicPagePrivate::~HAnalysicPagePrivate()
{
}

void HAnalysicPagePrivate::init()
{
    Q_Q(HAnalysicPage);

    m_layout    = new QHBoxLayout(q);
    m_emptyPage = new HConstructorPage(q);

    m_layout->addWidget(m_emptyPage);
    m_layout->setContentsMargins(20, 16, 20, 16);
}

HAnalysicPage::HAnalysicPage(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HAnalysicPagePrivate(this))
{
    d_func()->init();
}

HAnalysicPage::~HAnalysicPage()
{
}

void HAnalysicPage::paintEvent(QPaintEvent *event)
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
