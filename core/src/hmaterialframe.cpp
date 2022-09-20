#include <QPainter>
#include <QPainterPath>

#include "hmaterialframe.h"
#include "hthemecontrol.h"

HMaterialFrame::HMaterialFrame(QWidget *parent)
    : QWidget(parent)
{
    m_level = LevelColor::Level1;
    m_roundCorner = 8;

    m_darkColors    = { QColor(32, 34, 37), QColor(41, 43, 47), QColor(47, 49, 54), QColor(54, 57, 63) };
    m_lightColors   = { QColor(227, 229, 232), QColor(235, 237, 239), QColor(242, 243, 245), QColor(255, 255, 255) };

    HThemeControl *themeControl = HThemeControl::getThemeControl();
    themeControl->addControlWidget(this);

    if (themeControl->m_theme == ThemeMode::Dark) {
        setDarkTheme();
    } else {
        setLightTheme();
    }
}

HMaterialFrame::HMaterialFrame(LevelColor level, QWidget *parent)
    : QWidget(parent)
    , m_level(level)
{
    m_roundCorner = 8;

    m_darkColors    = { QColor(32, 34, 37), QColor(41, 43, 47), QColor(47, 49, 54), QColor(54, 57, 63) };
    m_lightColors   = { QColor(255, 255, 255), QColor(242, 243, 245), QColor(235, 237, 239), QColor(227, 229, 232) };

    HThemeControl *themeControl = HThemeControl::getThemeControl();
    themeControl->addControlWidget(this);

    if (themeControl->m_theme == ThemeMode::Dark) {
        setDarkTheme();
    } else {
        setLightTheme();
    }
}

HMaterialFrame::~HMaterialFrame()
{
}

void HMaterialFrame::setDarkTheme()
{
    m_backgroundColor = m_darkColors[m_level];

    update();
}

void HMaterialFrame::setLightTheme()
{
    m_backgroundColor = m_lightColors[m_level];

    update();
}

void HMaterialFrame::setLevelColor(LevelColor level)
{
    m_level = level;

    HThemeControl *themeControl = HThemeControl::getThemeControl();
    if (themeControl->m_theme == ThemeMode::Dark) {
        setDarkTheme();
    } else {
        setLightTheme();
    }
}

void HMaterialFrame::setCornerRadius(qreal radius)
{
    m_roundCorner = radius;

    update();
}

void HMaterialFrame::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    const qreal cr = m_roundCorner;

    if (cr > 0 ) {
        QPainterPath path;
        path.addRoundedRect(rect(), cr, cr);

        painter.setClipPath(path);
        painter.setClipping(true);
    }

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(m_backgroundColor);

    painter.setOpacity(1);
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);
    painter.drawRect(rect());
}
