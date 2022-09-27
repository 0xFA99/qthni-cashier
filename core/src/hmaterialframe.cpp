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
        QColor(17, 20, 24),
        QColor(25, 31, 36),
        QColor(35, 42, 49),
        QColor(56, 67, 79)
    };
    m_lightColors       = {
        QColor(255, 255, 255),
        QColor(249, 249, 250),
        QColor(239, 240, 242),
        QColor(219, 222, 225)
    };
    m_colorLevel        = 0;
    m_followTheme       = true;
    m_frameStyle        = HMaterial::Level1;
}

HMaterialFrame::HMaterialFrame(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HMaterialFramePrivate(this))
{
    d_func()->init();

    setFrameStyle(HMaterial::Level1);
}

HMaterialFrame::HMaterialFrame(HMaterial::FrameStyle style, QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HMaterialFramePrivate(this))
{
    d_func()->init();

    setFrameStyle(style);
}

HMaterialFrame::~HMaterialFrame()
{
}

void HMaterialFrame::setDarkTheme()
{
    Q_D(HMaterialFrame);

    if (d->m_followTheme) {
        switch (d->m_frameStyle) {
            case HMaterial::Level1:
                d->m_backgroundColor = d->m_darkColors[0];
                break;
            case HMaterial::Level2:
                d->m_backgroundColor = d->m_darkColors[1];
                break;
            case HMaterial::Level3:
                d->m_backgroundColor = d->m_darkColors[2];
                break;
            case HMaterial::Level4:
                d->m_backgroundColor = d->m_darkColors[3];
                break;
        }
    }

    update();
}

void HMaterialFrame::setLightTheme()
{
    Q_D(HMaterialFrame);

    if (d->m_followTheme) {
        switch (d->m_frameStyle) {
            case HMaterial::Level1:
                d->m_backgroundColor = d->m_lightColors[0];
                break;
            case HMaterial::Level2:
                d->m_backgroundColor = d->m_lightColors[1];
                break;
            case HMaterial::Level3:
                d->m_backgroundColor = d->m_lightColors[2];
                break;
            case HMaterial::Level4:
                d->m_backgroundColor = d->m_lightColors[3];
                break;
        }
    }

    update();
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

void HMaterialFrame::setFrameStyle(HMaterial::FrameStyle style)
{
    Q_D(HMaterialFrame);

    d->m_frameStyle = style;

    HThemeControl *themeControl = HThemeControl::getThemeControl();
    (themeControl->m_theme == ThemeMode::Dark)
        ? setDarkTheme()
        : setLightTheme();
}

HMaterial::FrameStyle HMaterialFrame::frameStyle() const
{
    Q_D(const HMaterialFrame);

    return d->m_frameStyle;
}
