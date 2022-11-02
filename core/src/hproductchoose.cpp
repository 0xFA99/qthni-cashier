#include "hproductchoose.h"
#include "hproductchoose_p.h"

#include <QPainter>
#include <QPainterPath>

HProductChoosePrivate::HProductChoosePrivate(HProductChoose *q)
    : q_ptr(q)
{
}

HProductChoosePrivate::~HProductChoosePrivate()
{
}

void HProductChoosePrivate::init()
{
    Q_Q(HProductChoose);
}

HProductChoose::HProductChoose(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HProductChoosePrivate(this))
{
    d_func()->init();
}

HProductChoose::~HProductChoose()
{
}

void HProductChoose::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainterPath path;
    path.addRoundedRect(rect(), 16, 16);

    QBrush brush;
    brush.setColor(Qt::white);
    brush.setStyle(Qt::SolidPattern);

    QPainter painter(this);
    painter.setClipPath(path);
    painter.setClipping(true);
    painter.setOpacity(1);
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);
    painter.drawRect(rect());
}
