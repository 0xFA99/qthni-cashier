#include "hmateriallabel.h"
#include "hthemecontrol.h"

HMaterialLabel::HMaterialLabel(LabelStyle style, QWidget *parent)
    : QLabel(parent)
    , m_style(style)
{
    setAttribute(Qt::WA_TranslucentBackground);
    setForegroundRole(QPalette::WindowText);
    setFont(QFont("ProductSans"));

    HThemeControl *themeControl = HThemeControl::getThemeControl();
    themeControl->addControlWidget(this);

    if (themeControl->m_theme == ThemeMode::Dark) {
        setDarkTheme();
    } else {
        setLightTheme();
    }

    setStyle(m_style);
}

HMaterialLabel::HMaterialLabel(const QString &text, LabelStyle style, QWidget *parent)
    : QLabel(text, parent)
    , m_style(style)
{
    setAttribute(Qt::WA_TranslucentBackground);
    setForegroundRole(QPalette::WindowText);
    setFont(QFont("ProductSans"));

    HThemeControl *themeControl = HThemeControl::getThemeControl();
    themeControl->addControlWidget(this);

    if (themeControl->m_theme == ThemeMode::Dark) {
        setDarkTheme();
    } else {
        setLightTheme();
    }

    setStyle(m_style);
}

HMaterialLabel::~HMaterialLabel()
{
}

void HMaterialLabel::setStyle(LabelStyle style)
{
    m_style = style;

    QFont font = this->font();

    switch (m_style) {
        case Heading:
            font.setPointSize(27);
            font.setWeight(QFont::Bold);
            break;
        case Subheading:
            font.setPointSize(18);
            font.setWeight(QFont::Medium);
            break;
        case Body:
            font.setPointSize(10);
            font.setWeight(QFont::Normal);
            break;
        case Caption:
            font.setPointSize(8);
            font.setWeight(QFont::Light);
            break;
    }

    this->setFont(font);
}

void HMaterialLabel::setDarkTheme()
{
    QPalette palette = this->palette();

    if (m_color == LabelColor::Color1) {
        palette.setColor(foregroundRole(), QColor(255, 255, 255));
    } else {
        palette.setColor(foregroundRole(), QColor(150, 152, 157));
    }

    setPalette(palette);
}

void HMaterialLabel::setLightTheme()
{
    QPalette palette = this->palette();

    if (m_color == LabelColor::Color1) {
        palette.setColor(foregroundRole(), QColor(6, 6, 7));
    } else {
        palette.setColor(foregroundRole(), QColor(94, 103, 114));
    }

    setPalette(palette);
}
