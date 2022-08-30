#ifndef HMATERIALTABS_INTERNAL_H
#define HMATERIALTABS_INTERNAL_H

#include "hmaterialflatbutton.h"

#include "hmaterialoverlaywidget.h"

class QPropertyAnimation;
class HMaterialTabs;

class HMaterialTabsInkBar : public HMaterialOverlayWidget
{
    Q_OBJECT

    Q_PROPERTY(qreal tweenValue WRITE setTweenValue READ tweenValue)

public:
    HMaterialTabsInkBar(HMaterialTabs *parent = nullptr);
    ~HMaterialTabsInkBar();

    inline void setTweenValue(qreal value);
    inline qreal tweenValue() const;

    void refreshGeometry();
    void animate();

protected:
    bool eventFilter(QObject *obj, QEvent *event) Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    Q_DISABLE_COPY(HMAterialTabsInkBar)

    HMaterialTabs       *const  m_tabs;
    QPropertyAnimation  *const  m_animation;
    QRect                       m_geometry;
    QRect                       m_previousGeometry;
    qreal                       m_tween;
};

inline void HMaterialTabsInkBar::setTweenValue(qreal value)
{
    m_tween = value;
    refreshGeometry();
}

inline qreal HMaterialTabsInkBar::tweenValue() const
{
    return m_tween;
}

class HMaterialTab : public HMaterialFlatButton
{
    Q_OBJECT

public:
    explicit HMaterialTab(HMaterialTabs *parent = nullptr);
    ~HMaterialTab();

    inline void setActive(bool state);
    inline bool isActive() const;

    QSize sizeHint() const Q_DECL_OVERRIDE;

protected:
    void paintForeground(QPainter *painter) Q_DECL_OVERRIDE;

protected slots:
    void activeTab();

private:
    Q_DISABLE_COPY(HMaterialTab)

    HMaterialTabs   *const  m_tabs;
    bool                    m_active;
};

inline void HMaterialTab::setActive(bool state)
{
    m_active = state;
    update();   
}

inline bool HMaterialTab::isActive() const
{
    return m_active;
}

#endif
