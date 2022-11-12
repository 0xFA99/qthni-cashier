#include "hconstructorpage.h"

#include <QPainter>
#include <QPainterPath>

HConstructorPage::HConstructorPage(QWidget *parent)
    : QWidget(parent)
{
}

HConstructorPage::~HConstructorPage()
{
}

void HConstructorPage::paintForeground(QPainter *painter)
{
    painter->setPen(QColor(0, 0, 0, 115));
    painter->setFont(QFont("Roboto", 12, QFont::Medium));

    int z = int(36.0 / 1.33);
    const int x = (rect().width() - size().width()) / 2;
    int y = ((rect().height() - size().height()) / 2) + z;

    QRect textGeometry(x, y, size().width(), size().height());
    painter->drawText(textGeometry, Qt::AlignCenter, "The Page\nUnder Constructor");

    painter->setFont(QFont("iconfont", 24, QFont::Medium));
    y = ((rect().height() - size().height()) / 2) - z;

    textGeometry = QRect(x, y, size().width(), size().height());
    painter->drawText(textGeometry, Qt::AlignCenter, "\uE65E");
}

void HConstructorPage::paintBackground(QPainter *painter)
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

void HConstructorPage::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    paintBackground(&painter);
    paintForeground(&painter);
}
