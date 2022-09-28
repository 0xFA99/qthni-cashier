#include "hmaterialbutton.h"
#include "hmaterialbutton_p.h"

#include "hthemecontrol.h"

HMaterialButtonPrivate::HMaterialButtonPrivate(HMaterialButton *q)
    : q_ptr(q)
{
}

HMaterialButtonPrivate::~HMaterialButtonPrivate()
{
}

void HMaterialButtonPrivate::init()
{
    Q_Q(HMaterialButton);

    m_lightColor  = QColor(255, 255, 255);
    m_darkColor   = QColor(34, 34, 34);

    m_followTheme = true;
}

HMaterialButton::HMaterialButton(QWidget *parent)
    : HMaterialFlatButton(parent)
    , d_ptr(new HMaterialButtonPrivate(this))
{
    d_func()->init();

    setCornerRadius(8);
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
    , d_ptr(new HMaterialButtonPrivate(this))
{
    d_func()->init();

    setCornerRadius(8);
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
    , d_ptr(new HMaterialButtonPrivate(this))
{
    d_func()->init();

    setCornerRadius(8);
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
    Q_D(HMaterialButton);

    if (d->m_followTheme)
        setForegroundColor(d->m_lightColor);
}

void HMaterialButton::setLightTheme()
{
    Q_D(HMaterialButton);

    if (d->m_followTheme)
        setForegroundColor(d->m_darkColor);
}

void HMaterialButton::setFollowTheme(bool value)
{
    Q_D(HMaterialButton);

    d->m_followTheme = value;
    if (d->m_followTheme) {
        HThemeControl *themeControl = HThemeControl::getThemeControl();
        (themeControl->m_theme == ThemeMode::Dark) ? setDarkTheme() : setLightTheme();
    }

}

bool HMaterialButton::isFollowTheme() const
{
    Q_D(const HMaterialButton);

    return d->m_followTheme;
}

void HMaterialButton::setColor(const QColor &color)
{
    Q_D(HMaterialButton);

    d->m_followTheme = false;
    setForegroundColor(color);
}
