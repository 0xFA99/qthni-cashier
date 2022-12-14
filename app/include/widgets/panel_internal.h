#ifndef QTHNI_PANEL_INTERNAL_H
#define QTHNI_PANEL_INTERNAL_H

#include "qtmaterial/components/qtmaterialflatbutton.h"
#include "qtmaterial/lib/qtmaterialoverlaywidget.h"

class QPropertyAnimation;
class Panel;

class PanelInkBar : public QtMaterialOverlayWidget
{
    Q_OBJECT

    Q_PROPERTY(qreal tweenValue WRITE setTweenValue READ tweenValue)

public:
    explicit PanelInkBar(Panel *parent);
    ~PanelInkBar();

    inline void setTweenValue(qreal value);
    [[nodiscard]] inline qreal tweenValue() const;

    void refreshGeometry();
    void animate();

protected:
    bool eventFilter(QObject *obj, QEvent *event)  Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    Q_DISABLE_COPY(PanelInkBar)

    Panel *const                m_tabs;
    QPropertyAnimation *const   m_animation;
    QRect                       m_geometry;
    QRect                       m_previousGeometry;
    qreal                       m_tween;
};

inline void PanelInkBar::setTweenValue(qreal value)
{
    m_tween = value;
    refreshGeometry();
}

inline qreal PanelInkBar::tweenValue() const
{
    return m_tween;
}

class PanelTab : public QtMaterialFlatButton
{
    Q_OBJECT

public:
    explicit PanelTab(Panel *parent);
    ~PanelTab();

    inline void setActive(bool state);
    [[nodiscard]] inline bool isActive() const;

    [[nodiscard]] QSize sizeHint() const Q_DECL_OVERRIDE;

protected slots:
    void activateTab();

protected:
    void paintForeground(QPainter *painter) Q_DECL_OVERRIDE;

private:
    Q_DISABLE_COPY(PanelTab)

    Panel *const    m_tabs;
    bool            m_active;
};

inline void PanelTab::setActive(bool state)
{
    m_active = state;
    update();
}

inline bool PanelTab::isActive() const
{
    return m_active;
}

#endif // QTHNI_PANEL_INTERNAL_H
