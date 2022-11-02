#include "hproductresult.h"
#include "hproductresult_p.h"

#include <QPainter>
#include <QPainterPath>

HProductResultPrivate::HProductResultPrivate(HProductResult *q)
    : q_ptr(q)
{
}

HProductResultPrivate::~HProductResultPrivate()
{
}

void HProductResultPrivate::init()
{
    Q_Q(HProductResult);
}

HProductResult::HProductResult(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HProductResultPrivate(this))
{
    d_func()->init();
}

HProductResult::~HProductResult()
{
}

void HProductResult::paintBackground(QPainter *painter)
{
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

void HProductResult::paintForeground(QPainter *painter)
{
    painter->setPen(QColor(0, 0, 0, 115));
    painter->setFont(QFont("Roboto", 12, QFont::Medium));

    const int z = (24 / 1.33);
    const int x = (rect().width() - size().width()) / 2;
    int y = ((rect().height() - size().height()) / 2) + z;

    QRect textGeometry(x, y, size().width(), size().height());
    painter->drawText(textGeometry, Qt::AlignCenter, "No Result");

    painter->setFont(QFont("iconfont", 24, QFont::Medium));
    y = ((rect().height() - size().height()) / 2) - z;

    textGeometry = QRect(x, y, size().width(), size().height());
    painter->drawText(textGeometry, Qt::AlignCenter, "\uE654");
}

void HProductResult::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);

    paintBackground(&painter);
    paintForeground(&painter);
}

