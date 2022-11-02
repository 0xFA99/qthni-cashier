#include "hpurchasepage.h"
#include "hpurchasepage_p.h"

#include <QFrame>
#include <QPainter>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>

HPurchasePagePrivate::HPurchasePagePrivate(HPurchasePage *q)
    : q_ptr(q)
{
}

HPurchasePagePrivate::~HPurchasePagePrivate()
{
}

void HPurchasePagePrivate::init()
{
    Q_Q(HPurchasePage);

    m_layout        = new QHBoxLayout(q);
    m_orderList     = new HOrderList(q);
    m_orderPrice    = new HOrderPrice(q);
    m_searchField   = new HMaterialSearch(q);
    m_productSearch = new HProductResult(q);

    m_orderPrice->setMaximumHeight(300);

    QSizePolicy leftPolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    QSizePolicy rightPolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    leftPolicy.setHorizontalStretch(3);
    rightPolicy.setHorizontalStretch(1);

    QFrame *leftFrame = new QFrame(q);
    leftFrame->setSizePolicy(leftPolicy);
    QGridLayout *leftLayout = new QGridLayout(leftFrame);
    leftLayout->addWidget(m_searchField);
    leftLayout->addWidget(m_productSearch);
    leftLayout->setSpacing(16);

    QFrame *rightFrame = new QFrame(q);
    rightFrame->setSizePolicy(rightPolicy);
    QVBoxLayout *rightLayout = new QVBoxLayout(rightFrame);
    rightLayout->addWidget(m_orderList);
    rightLayout->addWidget(m_orderPrice);
    rightLayout->setSpacing(16);

    m_layout->addWidget(leftFrame);
    m_layout->addWidget(rightFrame);
}

HPurchasePage::HPurchasePage(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HPurchasePagePrivate(this))
{
    d_func()->init();
}

HPurchasePage::~HPurchasePage()
{
}

void HPurchasePage::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor("#f5f6fb"));

    painter.setOpacity(1);
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);
    painter.drawRect(rect());
}
