#include "hmateriallabel.h"
#include "hmateriallabel_p.h"

#include "hthemecontrol.h"

HMaterialLabelPrivate::HMaterialLabelPrivate(HMaterialLabel *q)
    : q_ptr(q)
{
}

HMaterialLabelPrivate::~HMaterialLabelPrivate()
{
}

void HMaterialLabelPrivate::init()
{
    m_labelStyle    = HMaterial::Body;
    m_role          = HMaterial::Primary;
    m_darkColor     = { QColor(34, 34, 34), QColor(69, 90, 100) };
    m_lightColor    = { QColor(255, 255, 255), QColor(176, 190, 197) };
    m_followTheme   = true;
}

HMaterialLabel::HMaterialLabel(QWidget *parent)
    : QLabel(parent)
    , d_ptr(new HMaterialLabelPrivate(this))
{
    d_func()->init();

    setAttribute(Qt::WA_TranslucentBackground);
    setForegroundRole(QPalette::WindowText);
    setFont(QFont("ProductSans", 12));

    setFollowTheme(true);
}

HMaterialLabel::HMaterialLabel(const QString &text, QWidget *parent)
    : QLabel(text, parent)
    , d_ptr(new HMaterialLabelPrivate(this))
{
    d_func()->init();

    setAttribute(Qt::WA_TranslucentBackground);
    setForegroundRole(QPalette::WindowText);
    setFont(QFont("ProductSans", 12));

    setFollowTheme(true);
}

HMaterialLabel::~HMaterialLabel()
{
}

void HMaterialLabel::setDarkTheme()
{
    Q_D(HMaterialLabel);

    QPalette palette = this->palette();

    if (d->m_followTheme) {
        if (d->m_role == HMaterial::Primary) {
            d->m_textColor = d->m_lightColor[0];
        } else if (d->m_role == HMaterial::Secondary) {
            d->m_textColor = d->m_lightColor[1];
        } else {
            d->m_textColor = QColor(211, 47, 47);
        }
    }

    palette.setColor(foregroundRole(), d->m_textColor);
    setPalette(palette);
}

void HMaterialLabel::setLightTheme()
{
    Q_D(HMaterialLabel);

    QPalette palette = this->palette();

    if (d->m_followTheme) {
        if (d->m_role == HMaterial::Primary) {
            d->m_textColor = d->m_darkColor[0];
        } else if (d->m_role == HMaterial::Secondary) {
            d->m_textColor = d->m_darkColor[1];
        } else {
            d->m_textColor = QColor(211, 47, 47);
        }
    }

    palette.setColor(foregroundRole(), d->m_textColor);
    setPalette(palette);
}

void HMaterialLabel::setFollowTheme(bool value)
{
    Q_D(HMaterialLabel);

    d->m_followTheme = value;

    HThemeControl *themeControl = HThemeControl::getThemeControl();
    (themeControl->m_theme == ThemeMode::Dark)
        ? setDarkTheme() : setLightTheme();
}

bool HMaterialLabel::isFollowTheme() const
{
    Q_D(const HMaterialLabel);

    return d->m_followTheme;
}

void HMaterialLabel::setLabelStyle(HMaterial::LabelStyle style)
{
    Q_D(HMaterialLabel);

    d->m_labelStyle = style;
    
    QFont font = this->font();

    switch (d->m_labelStyle) {
        case HMaterial::Heading:
            font.setPointSize(18);
            break;
        case HMaterial::Body:
            font.setPointSize(12);
            break;
    }

    this->setFont(font);
}

HMaterial::LabelStyle HMaterialLabel::labelStyle() const
{
    Q_D(const HMaterialLabel);

    return d->m_labelStyle;
}

void HMaterialLabel::setLabelRole(HMaterial::Role role)
{
    Q_D(HMaterialLabel);

    d->m_role = role;

    HThemeControl *themeControl = HThemeControl::getThemeControl();
    (themeControl->m_theme == ThemeMode::Dark)
        ? setDarkTheme() : setLightTheme();
}

HMaterial::Role HMaterialLabel::labelRole() const
{
    Q_D(const HMaterialLabel);

    return d->m_role;
}

void HMaterialLabel::setTextColor(const QColor &color)
{
    Q_D(HMaterialLabel);

    d->m_followTheme = false;
    d->m_textColor = color;

    QPalette palette = this->palette();
    palette.setColor(foregroundRole(), d->m_textColor);
    setPalette(palette);
}

QColor HMaterialLabel::textColor() const
{
    Q_D(const HMaterialLabel);

    return d->m_textColor;
}
