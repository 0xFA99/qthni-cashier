#include <QPainter>
#include <QPainterPath>
#include <QDebug>
#include "hmaterialframe.h"
#include "hframebuttonsetting.h"

HMaterialFrame::HMaterialFrame(ThemeColors theme, LevelColors level, QWidget *parent)
    : QWidget(parent)
    , m_theme(theme)
    , m_level(level)
{
    m_roundCorner = 8;

    m_darkColors  = { QColor("#202225"), QColor("#292b2f"), QColor("#2f3136"), QColor("#36393f") };
    m_lightColors = { QColor("#e3e5e8"), QColor("#ebedef"), QColor("#f2f3f5"), QColor("#ffffff") };

    if (m_theme == ThemeColors::Dark) {
        setDarkMode();
    } else {
        setLightMode();
    }

    update();

    HFrameButtonSetting *frameSetting = HFrameButtonSetting::getFrameSetting();
    frameSetting->addFrameWidget(this);
}

HMaterialFrame::~HMaterialFrame()
{
}

void HMaterialFrame::setCorner(qreal corner)
{
    m_roundCorner = corner;
    update();
}

void HMaterialFrame::changeMode()
{
    m_theme = (m_theme == ThemeColors::Dark)
            ?  m_theme = ThemeColors::Light : m_theme = ThemeColors::Dark;

    if (m_theme == ThemeColors::Dark) {
        m_backgroundColor = m_darkColors[m_level];
    } else {
        m_backgroundColor = m_lightColors[m_level];
    }

    update();
}

void HMaterialFrame::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    const qreal cr = m_roundCorner;

    QPainterPath path;
    path.addRoundedRect(rect(), cr, cr);

    painter.setClipPath(path);
    painter.setClipping(true);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(m_backgroundColor);

    painter.setOpacity(1);
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);
    painter.drawRect(rect());
}
