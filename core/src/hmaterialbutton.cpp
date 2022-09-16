#include "hmaterialbutton.h"
#include "hthemecontrol.h"
#include "hmaterialtheme.h"

HMaterialButton::HMaterialButton(QWidget *parent)
    : HMaterialFlatButton(parent)
{
    setHaloVisible(false);
    setOverlayStyle(HMaterial::TintedOverlay);

    HThemeControl *themeControl = HThemeControl::getThemeControl();
    themeControl->addControlWidget(this);
    if (themeControl->m_theme == ThemeMode::Dark) {
        setDarkTheme();
    } else {
        setLightTheme();
    }
}

HMaterialButton::HMaterialButton(const QString &text, QWidget *parent)
    : HMaterialFlatButton(text, parent)
{
    setHaloVisible(false);
    setOverlayStyle(HMaterial::TintedOverlay);

    HThemeControl *themeControl = HThemeControl::getThemeControl();
    themeControl->addControlWidget(this);
    if (themeControl->m_theme == ThemeMode::Dark) {
        setDarkTheme();
    } else {
        setLightTheme();
    }
}

HMaterialButton::HMaterialButton(QIcon icon, const QString &text, QWidget *parent)
    : HMaterialFlatButton(text, parent)
{
    setIcon(icon);
    setHaloVisible(false);
    setOverlayStyle(HMaterial::TintedOverlay);

    HThemeControl *themeControl = HThemeControl::getThemeControl();
    themeControl->addControlWidget(this);
    if (themeControl->m_theme == ThemeMode::Dark) {
        setDarkTheme();
    } else {
        setLightTheme();
    }
}

HMaterialButton::~HMaterialButton()
{
}

void HMaterialButton::setDarkTheme()
{
    setForegroundColor(QColor(255, 255, 255));
}

void HMaterialButton::setLightTheme()
{
    setForegroundColor(QColor(46, 51, 56));
}

