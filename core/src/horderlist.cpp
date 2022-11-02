#include "horderlist.h"
#include "horderlist_p.h"

#include <QPainter>
#include <QPainterPath>
#include <QVBoxLayout>

HOrderListPrivate::HOrderListPrivate(HOrderList *q)
    : q_ptr(q)
{
}

HOrderListPrivate::~HOrderListPrivate()
{
}

void HOrderListPrivate::init()
{
    Q_Q(HOrderList);

    m_layout            = new QVBoxLayout(q);
    m_orderWorkspace    = new QWidget(q);
    m_orderLayout       = new QVBoxLayout(m_orderWorkspace);
    m_title             = new HMaterialLabel("Order List", q);

    m_layout->addWidget(m_title);
    m_layout->addWidget(m_orderWorkspace);

    m_layout->setContentsMargins(16, 16, 16, 16);
    m_layout->addStretch(1);
}

HOrderList::HOrderList(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HOrderListPrivate(this))
{
    d_func()->init();
}

HOrderList::~HOrderList()
{
}

void HOrderList::paintBackground(QPainter *painter)
{
    Q_D(HOrderList);

    QPainterPath path;
    path.addRoundedRect(rect(), 16, 16);
    painter->setClipPath(path);
    painter->setClipping(true);

    QBrush brush;
    brush.setColor(Qt::white);
    brush.setStyle(Qt::SolidPattern);

    painter->setOpacity(1);
    painter->setBrush(brush);
    painter->setPen(Qt::NoPen);
    painter->drawRect(rect());
}

void HOrderList::paintForeground(QPainter *painter)
{
    Q_D(HOrderList);

    painter->setPen(QColor(0, 0, 0, 115));
    painter->setFont(QFont("Roboto", 12, QFont::Medium));

    const int z = (24 / 1.33);
    const int x = (rect().width() - size().width()) / 2;
    int y = ((rect().height() - size().height()) / 2) + z;

    QRect textGeometry(x, y, size().width(), size().height());
    painter->drawText(textGeometry, Qt::AlignCenter, "No Item Added");

    painter->setFont(QFont("iconfont", 24, QFont::Medium));
    y = ((rect().height() - size().height()) / 2) - z;

    textGeometry = QRect(x, y, size().width(), size().height());
    painter->drawText(textGeometry, Qt::AlignCenter, "\uE652");

    QRect line(16, 46, rect().width() - 32, 1);
    painter->fillRect(line, QColor("#f1f4f9"));
}

void HOrderList::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    Q_D(HOrderList);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    paintBackground(&painter);
    paintForeground(&painter);

}
