#include "hmaterialsperator.h"
#include "hmaterialsperator_p.h"

#include <QPainter>

#include "hthemecontrol.h"

HMaterialSperatorPrivate::HMaterialSperatorPrivate(HMaterialSperator *q)
    : q_ptr(q)
{
}

HMaterialSperatorPrivate::~HMaterialSperatorPrivate()
{
}

void HMaterialSperatorPrivate::init()
{
    m_color = QColor(Qt::black);
    m_style = Qt::SolidLine;
    m_width = 2;
}

HMaterialSperator::HMaterialSperator(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HMaterialSperatorPrivate(this))
{
    d_func()->init();
    
    setMinimumHeight(5);

    HThemeControl *themeControl = HThemeControl::getThemeControl();
    themeControl->addControlWidget(this);
    update();
}

HMaterialSperator::~HMaterialSperator()
{
}

void HMaterialSperator::setDarkTheme()
{
    Q_D(HMaterialSperator);

    d->m_color = QColor("176, 190,  197");
    update();
}

void HMaterialSperator::setLightTheme()
{
    Q_D(HMaterialSperator);

    d->m_color = QColor("69, 90, 100");
    update();
}

void HMaterialSperator::setSperatorWidth(int value)
{
    Q_D(HMaterialSperator);

    d->m_width = value;
    update();
}

int HMaterialSperator::speratorWidth() const
{
    Q_D(const HMaterialSperator);

    return d->m_width;
}

void HMaterialSperator::setSperatorColor(const QColor &color)
{
    Q_D(HMaterialSperator);

    d->m_color = color;
    update();
}

QColor HMaterialSperator::speratorColor() const
{
    Q_D(const HMaterialSperator);

    return d->m_color;
}

void HMaterialSperator::setSperatorStyle(Qt::PenStyle style)
{
    Q_D(HMaterialSperator);

    d->m_style = style;
    update();
}

Qt::PenStyle HMaterialSperator::speratorStyle() const
{
    Q_D(const HMaterialSperator);

    return d->m_style;
}

void HMaterialSperator::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    Q_D(HMaterialSperator);

    QPainter painter(this);

    QPen pen(d->m_color, d->m_width, d->m_style);
    painter.setPen(pen);

    painter.drawLine(0, height() / 2, width(), height() / 2);
}
