#ifndef HMATERIALRIPPLE_H
#define HMATERIALRIPPLE_H

#include <QParallelAnimationGroup>
#include <QEasingCurve>
#include <QPropertyAnimation>
#include <QPoint>
#include <QBrush>

class HMaterialRippleOverlay;

class HMaterialRipple : public QParallelAnimationGroup
{
    Q_OBJECT

    Q_PROPERTY(qreal radius WRITE setRadius READ radius)
    Q_PROPERTY(qreal opacity WRITE setOpacity READ opacity)

public:
    explicit HMaterialRipple(const QPoint &center, QObject *parent = 0);
    HMaterialRipple(const QPoint &center, HMaterialRippleOverlay *overlay, QObject *parent = 0);
    ~HMaterialRipple();

    inline void setOverlay(HMaterialRippleOverlay *overlay);

    void setRadius(qreal radius);
    inline qreal radius() const;

    void setOpacity(qreal opacity);
    inline qreal opacity() const;

    void setColor(const QColor &color);
    inline QColor color() const;

    void setBrush(const QBrush &brush);
    inline QBrush brush() const;

    inline QPoint center() const;

    inline QPropertyAnimation *radiusAnimation() const;
    inline QPropertyAnimation *opacityAnimation() const;

    inline void setOpacityStartValue(qreal value);
    inline void setOpacityEndValue(qreal value);
    inline void setRadiusStartValue(qreal value);
    inline void setRadiusEndValue(qreal value);
    inline void setDuration(int msecs);

protected slots:
    void destroy();

private:
    Q_DISABLE_COPY(HMaterialRipple)

    QPropertyAnimation *animate(const QByteArray &property,
                                const QEasingCurve &easing = QEasingCurve::OutQuad,
                                int duration = 800);

    void init();

    HMaterialRippleOverlay  *m_overlay;
    QPropertyAnimation *const m_radiusAnimation;
    QPropertyAnimation *const m_opacityAnimation;
    qreal                     m_radius;
    qreal                     m_opacity;
    QPoint                    m_center;
    QBrush                    m_brush;
};

inline void HMaterialRipple::setOverlay(HMaterialRippleOverlay *overlay)
{
    m_overlay = overlay;
}

inline qreal HMaterialRipple::radius() const
{
    return m_radius;
}

inline qreal HMaterialRipple::opacity() const
{
    return m_opacity;
}

inline QColor HMaterialRipple::color() const
{
    return m_brush.color();
}

inline QBrush HMaterialRipple::brush() const
{
    return m_brush;
}

inline QPoint HMaterialRipple::center() const
{
    return m_center;
}

inline QPropertyAnimation *HMaterialRipple::radiusAnimation() const
{
    return m_radiusAnimation;
}

inline QPropertyAnimation *HMaterialRipple::opacityAnimation() const
{
    return m_opacityAnimation;
}

inline void HMaterialRipple::setOpacityStartValue(qreal value)
{
    m_opacityAnimation->setStartValue(value);
}

inline void HMaterialRipple::setOpacityEndValue(qreal value)
{
    m_opacityAnimation->setEndValue(value);
}

inline void HMaterialRipple::setRadiusStartValue(qreal value)
{
    m_radiusAnimation->setStartValue(value);
}

inline void HMaterialRipple::setRadiusEndValue(qreal value)
{
    m_radiusAnimation->setEndValue(value);
}

inline void HMaterialRipple::setDuration(int msecs)
{
    m_radiusAnimation->setDuration(msecs);
    m_opacityAnimation->setDuration(msecs);
}

#endif
