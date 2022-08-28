#ifndef HMATERIALRIPPLEOVERLAY_H
#define HMATERIALRIPPLEOVERLAY_H

#include <QPainterPath>
#include "hmaterialoverlaywidget.h"

class HMaterialRipple;

class HMaterialRippleOverlay : public HMaterialOverlayWidget
{
    Q_OBJECT

public:
    explicit HMaterialRippleOverlay(QWidget *parent = nullptr);
    ~HMaterialRippleOverlay();

    void addRipple(HMaterialRipple *ripple);
    void addRipple(const QPoint &position, qreal radius = 300);

    void removeRipple(HMaterialRipple *ripple);

    inline void setClipping(bool enable);
    inline bool hasClipping() const;

    inline void setClipPath(const QPainterPath &path);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

    inline QList<HMaterialRipple *> ripples() const;

private:
    Q_DISABLE_COPY(HMaterialRippleOverlay)

    void paintRipple(QPainter *painter, HMaterialRipple *ripple);

    QList<HMaterialRipple *> m_ripples;
    QPainterPath             m_clipPath;
    bool                    m_useClip;
};

inline void HMaterialRippleOverlay::setClipping(bool enable)
{
    m_useClip = enable;
    update();
}

inline bool HMaterialRippleOverlay::hasClipping() const
{
    return m_useClip;
}

inline void HMaterialRippleOverlay::setClipPath(const QPainterPath &path)
{
    m_clipPath = path;
    update();
}

inline QList<HMaterialRipple *> HMaterialRippleOverlay::ripples() const
{
    return m_ripples;
}

#endif
