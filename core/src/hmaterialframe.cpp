#include "hmaterialframe.h"
#include "hmaterialframe_p.h"

#include <QPainter>
#include <QPainterPath>

#include "hthemecontrol.h"

HMaterialFramePrivate::HMaterialFramePrivate(HMaterialFrame *q)
    : q_ptr(q)
{
}

HMaterialFramePrivate::~HMaterialFramePrivate()
{
}

void HMaterialFramePrivate::init()
{
    Q_Q(HMaterialFrame);

    m_backgroundColor   = QColor(Qt::white);
    m_roundCorner       = 8;
    m_darkColors        = {
        QColor(32, 24, 27), QColor(41, 43, 47), QColor(47, 49, 54), QColor(54, 57, 63)
    };
    m_lightColors       = {
        QColor(227, 229, 232), QColor(235, 237, 239), QColor(242, 243, 245), QColor(255, 255, 255)
    };
    m_colorLevel        = 0;
    m_followTheme       = true;
}

HMaterialFrame::HMaterialFrame(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HMaterialFramePrivate(this))
{
    d_func()->init();

    setLevelColor(0);
}

HMaterialFrame::HMaterialFrame(int level, QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HMaterialFramePrivate(this))
{
    d_func()->init();

    setLevelColor(level);
}

HMaterialFrame::~HMaterialFrame()
{
}

void HMaterialFrame::setDarkTheme()
{
    Q_D(HMaterialFrame);

    if (d->m_followTheme) {
        d->m_backgroundColor = d->m_darkColors[d->m_colorLevel];
        update();
    }
}

void HMaterialFrame::setLightTheme()
{
    Q_D(HMaterialFrame);

    if (d->m_followTheme) {
        d->m_backgroundColor = d->m_lightColors[d->m_colorLevel];
        update();
    }
}

void HMaterialFrame::setLevelColor(int level)
{
    Q_D(HMaterialFrame);

    d->m_colorLevel = level;

    HThemeControl *themeControl = HThemeControl::getThemeControl();
    themeControl->addControlWidget(this);

    if (themeControl->m_theme == ThemeMode::Dark) {
        setDarkTheme();
    } else {
        setLightTheme();
    }
}

int HMaterialFrame::getLevelColor() const
{
    Q_D(const HMaterialFrame);

    return d->m_colorLevel;
}

void HMaterialFrame::setCornerRadius(qreal radius)
{
    Q_D(HMaterialFrame);

    d->m_roundCorner = radius;
    update();
}

qreal HMaterialFrame::getCornerRadius() const
{
    Q_D(const HMaterialFrame);

    return d->m_roundCorner;
}

void HMaterialFrame::paintBackground(QPainter *painter)
{
    Q_D(HMaterialFrame);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(d->m_backgroundColor);

    painter->setOpacity(1);
    painter->setBrush(brush);
    painter->setPen(Qt::NoPen);
    painter->drawRect(rect());
}

QColor HMaterialFrame::getBackground() const
{
    Q_D(const HMaterialFrame);

    return d->m_backgroundColor;
}

void HMaterialFrame::setFollowTheme(bool value)
{
    Q_D(HMaterialFrame);

    d->m_followTheme = value;
    if (d->m_followTheme) {
        HThemeControl *themeControl = HThemeControl::getThemeControl();
        (themeControl->m_theme == ThemeMode::Dark) ? setDarkTheme() : setLightTheme();
    }
}

bool HMaterialFrame::isFollowTheme() const
{
    Q_D(const HMaterialFrame);

    return d->m_followTheme;
}

void HMaterialFrame::setBackgroundColor(const QColor &color)
{
    Q_D(HMaterialFrame);

    d->m_backgroundColor = color;
    d->m_followTheme = false;
    update();
}

QColor HMaterialFrame::backgroundColor() const
{
    Q_D(const HMaterialFrame);

    return d->m_backgroundColor;
}

void HMaterialFrame::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    Q_D(HMaterialFrame);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    const qreal cr = d->m_roundCorner;

    if (cr > 0) {
        QPainterPath path;
        path.addRoundedRect(rect(), cr, cr);

        painter.setClipPath(path);
        painter.setClipping(true);
    }

    paintBackground(&painter);
}
