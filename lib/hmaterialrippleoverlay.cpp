#include <QPainter>

#include "hmaterialrippleoverlay.h"
#include "hmaterialripple.h"

HMaterialRippleOverlay::HMaterialRippleOverlay(QWidget *parent)
    : HMaterialOverlayWidget(parent),
      m_useClip(false)
{
    setAttribute(Qt::WA_TransparentForMouseEvents);
    setAttribute(Qt::WA_NoSystemBackground);
}

HMaterialRippleOverlay::~HMaterialRippleOverlay()
{
}

void HMaterialRippleOverlay::addRipple(HMaterialRipple *ripple)
{
    ripple->setOverlay(this);
    m_ripples.push_back(ripple);
    ripple->start();

    connect(this, SIGNAL(destroyed(QObject*)), ripple, SLOT(stop()));
    connect(this, SIGNAL(destroyed(QObject*)), ripple, SLOT(deleteLater()));
}

void HMaterialRippleOverlay::addRipple(const QPoint &position, qreal radius)
{
    HMaterialRipple *ripple = new HMaterialRipple(position);
    ripple->setRadiusEndValue(radius);
    addRipple(ripple);
}

void HMaterialRippleOverlay::removeRipple(HMaterialRipple *ripple)
{
    if (m_ripples.removeOne(ripple)) {
        delete ripple;
        update();
    }
}

void HMaterialRippleOverlay::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);

    if (m_useClip) {
        painter.setClipPath(m_clipPath);
    }

    QList<HMaterialRipple *>::const_iterator i;
    for (i = m_ripples.begin(); i != m_ripples.end(); ++i) {
        paintRipple(&painter, *i);
    }
}

void HMaterialRippleOverlay::paintRipple(QPainter *painter, HMaterialRipple *ripple)
{
    const qreal radius = ripple->radius();
    const QPointF center = ripple->center();
    painter->setOpacity(ripple->opacity());
    painter->setBrush(ripple->brush());
    painter->drawEllipse(center, radius, radius);
}
