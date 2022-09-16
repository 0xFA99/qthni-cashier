#include "hthemecontrol.h"
#include "hmaterialtheme.h"

HThemeControl *HThemeControl::m_themeControl = nullptr;

HThemeControl::HThemeControl(QIcon icon, QWidget *parent)
    : HMaterialFlatButton(parent)
    , m_widgetList(QVector<HInterfaceWidget *>())
    , m_theme(ThemeMode::Light)
{
    setIcon(icon);
    setBackgroundMode(Qt::OpaqueMode);
    setHaloVisible(false);
    setText("Change Mode");
    setOverlayStyle(HMaterial::TintedOverlay);

    connect(this, &QPushButton::clicked, [=]() { changeTheme(); });
    setForegroundColor(QColor(46, 51, 56));
    setBackgroundColor(QColor(255, 255, 255));
}

HThemeControl *HThemeControl::getThemeControl()
{
    if (m_themeControl == nullptr)
        m_themeControl = new HThemeControl(QIcon(":/icons/icons/sun.svg"));

    return m_themeControl;
}

void HThemeControl::addControlWidget(HInterfaceWidget *widget)
{
    m_widgetList.append(widget);
}

void HThemeControl::changeTheme()
{
    changeColor();

    if (m_widgetList.isEmpty())
        return;

    QVector<HInterfaceWidget *>::iterator itr;

    if (m_theme == ThemeMode::Dark) {
        for (itr = m_widgetList.begin(); itr != m_widgetList.end(); ++itr) {
            (*itr)->setDarkTheme();
        }
    } else {
        for (itr = m_widgetList.begin(); itr != m_widgetList.end(); ++itr) {
            (*itr)->setLightTheme();
        }
    }
}

void HThemeControl::changeColor()
{
    if (m_theme == ThemeMode::Dark) {
        setForegroundColor(QColor(46, 51, 56));
        setBackgroundColor(QColor(255, 255, 255));
        setIcon(QIcon(":/icons/icons/sun.svg"));

        m_theme = ThemeMode::Light;
    } else {
        setForegroundColor(QColor(255, 255, 255));
        setBackgroundColor(QColor(66, 70, 77));
        setIcon(QIcon(":/icons/icons/moon.svg"));

        m_theme = ThemeMode::Dark;
    }
}
