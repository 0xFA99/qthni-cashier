#include <QHBoxLayout>
#include "hmaterialtabs.h"
#include "hmaterialtabs_p.h"
#include "hmaterialtabs_internal.h"

#include "hmaterialstyle.h"

HMaterialTabsPrivate::HMaterialTabsPrivate(HMaterialTabs *q)
    : q_ptr(q)
{
}

HMaterialTabsPrivate::~HMaterialTabsPrivate()
{
}

void HMaterialTabsPrivate::HMaterialTabsPrivate::init()
{
    Q_Q(HMaterialTabs);

    inkBar          = new HMaterialTabsInkBar(q);
    tabLayout       = new QHBoxLayout;
    rippleStyle     = HMaterial::CenteredRipple;
    tab             = -1;
    showHalo        = true;
    useThemeColors  = true;

    q->setLayout(tabLayout);
    q->setStyle(&HMaterialStyle::instance());

    tabLayout->setSpacing(0);
    tabLayout->setMargin(0);
}

HMaterialTabs::HMaterialTabs(QWidget *parent)
    : QWidget(parent),
      d_ptr(new HMaterialTabsPrivate(this))
{
    d_func()->init();
}

HMaterialTabs::~HMaterialTabs()
{
}

void HMaterialTabs::setUseThemeColors(bool value)
{
    Q_D(HMaterialTabs);

    d->useThemeColors = value;
}

bool HMaterialTabs::useThemeColors() const
{
    Q_D(const HMaterialTabs);

    return d->useThemeColors;
}

void HMaterialTabs::setHaloVisible(bool value)
{
    Q_D(HMaterialTabs);

    d->showHalo = value;
    updateTabs();
}

bool HMaterialTabs::isHaloVisible() const
{
    Q_D(const HMaterialTabs);

    return d->showHalo;
}

void HMaterialTabs::setRippleStyle(HMaterial::RippleStyle style)
{
    Q_D(HMaterialTabs);

    d->rippleStyle = style;
    updateTabs();
}

HMaterial::RippleStyle HMaterialTabs::rippleStyle() const
{
    Q_D(const HMaterialTabs);

    return d->rippleStyle;
}

void HMaterialTabs::setInkColor(const QColor &color)
{
    Q_D(HMaterialTabs);

    d->inkColor = color;

    MATERIAL_DISABLE_THEME_COLORS
    d->inkBar->update();
    update();
}

QColor HMaterialTabs::inkColor() const
{
    Q_D(const HMaterialTabs);

    if (d->useThemeColors || !d->inkColor.isValid()) {
        return HMaterialStyle::instance().themeColor("accent1");
    } else {
        return d->inkColor;
    }
}

void HMaterialTabs::setBackgroundColor(const QColor &color)
{
    Q_D(HMaterialTabs);

    d->backgroundColor = color;

    MATERIAL_DISABLE_THEME_COLORS
    updateTabs();
    update();
}

QColor HMaterialTabs::backgroundColor() const
{
    Q_D(const HMaterialTabs);

    if (d->useThemeColors || !d->backgroundColor.isValid()) {
        return HMaterialStyle::instance().themeColor("primary1");
    } else {
        return d->backgroundColor;
    }
}

void HMaterialTabs::setTextColor(const QColor &color)
{
    Q_D(HMaterialTabs);

    d->textColor = color;

    MATERIAL_DISABLE_THEME_COLORS
    updateTabs();
    update();
}

QColor HMaterialTabs::textColor() const
{
    Q_D(const HMaterialTabs);

    if (d->useThemeColors || !d->textColor.isValid()) {
        return HMaterialStyle::instance().themeColor("canvas");
    } else {
        return d->textColor;
    }
}

void HMaterialTabs::setCurrentTab(HMaterialTab *tab)
{
    Q_D(HMaterialTabs);

    setCurrentTab(d->tabLayout->indexOf(tab));
}

void HMaterialTabs::setCurrentTab(int index)
{
    Q_D(HMaterialTabs);

    setTabActive(d->tab, false);
    d->tab = index;
    setTabActive(index, true);
    d->inkBar->animate();

    emit currentChanged(index);
}

void HMaterialTabs::addTab(const QString &text, const QIcon &icon)
{
    Q_D(HMaterialTabs);

    HMaterialTab *tab = new HMaterialTab(this);
    tab->setText(text);
    tab->setHaloVisible(isHaloVisible());
    tab->setRippleStyle(rippleStyle());

    if (!icon.isNull()) {
        tab->setIcon(icon);
        tab->setIconSize(QSize(22, 22));
    }

    d->tabLayout->addWidget(tab);

    if (-1 == d->tab) {
        d->tab = 0;
        d->inkBar->refreshGeometry();
        d->inkBar->raise();
        tab->setActive(true);
    }
}

int HMaterialTabs::currentIndex() const
{
    Q_D(const HMaterialTabs);

    return d->tab;
}

void HMaterialTabs::setTabActive(int index, bool active)
{
    Q_D(HMaterialTabs);

    HMaterialTab *tab;

    if (index > -1) {
        tab = static_cast<HMaterialTab *>(d->tabLayout->itemAt(index)->widget());
        if (tab) {
            tab->setActive(active);
        }
    }
}

void HMaterialTabs::updateTabs()
{
    Q_D(HMaterialTabs);

    HMaterialTab *tab;
    for (int i = 0; i < d->tabLayout->count(); i++) {
        QLayoutItem *item = d->tabLayout->itemAt(i);
        if ((tab = static_cast<HMaterialTab *>(item->widget()))) {
            tab->setRippleStyle(d->rippleStyle);
            tab->setHaloVisible(d->showHalo);
            tab->setBackgroundColor(backgroundColor());
            tab->setForegroundColor(textColor());
        }
    }
}
