#include "widgets/panel.h"
#include "widgets/panel_p.h"
#include "widgets/panel_internal.h"

#include "qtmaterial/lib/qtmaterialstyle.h"

#include <QHBoxLayout>
#include <QPainter>

/*!
 *  \PanelPrivate
 *  \internal
 */

PanelPrivate::PanelPrivate(Panel *q)
    : q_ptr(q)
{
}

PanelPrivate::~PanelPrivate() = default;

void PanelPrivate::PanelPrivate::init()
{
    Q_Q(Panel);

    inkBar         = new PanelInkBar(q);
    tabLayout      = new QVBoxLayout;
    rippleStyle    = Material::CenteredRipple;
    tab            = -1;
    showHalo       = true;
    useThemeColors = true;

    q->setLayout(tabLayout);
    q->setStyle(&QtMaterialStyle::instance());

    tabLayout->setSpacing(0);
    tabLayout->setMargin(16);
}

/*!
 *  \Panel
 */

Panel::Panel(QWidget *parent)
    : QWidget(parent),
      d_ptr(new PanelPrivate(this))
{
    d_func()->init();
}

Panel::~Panel() = default;

void Panel::setUseThemeColors(bool value)
{
    Q_D(Panel);

    d->useThemeColors = value;
}

bool Panel::useThemeColors() const
{
    Q_D(const Panel);

    return d->useThemeColors;
}

void Panel::setHaloVisible(bool value)
{
    Q_D(Panel);

    d->showHalo = value;
    updateTabs();
}

bool Panel::isHaloVisible() const
{
    Q_D(const Panel);

    return d->showHalo;
}

void Panel::setRippleStyle(Material::RippleStyle style)
{
    Q_D(Panel);

    d->rippleStyle = style;
    updateTabs();
}

Material::RippleStyle Panel::rippleStyle() const
{
    Q_D(const Panel);

    return d->rippleStyle;
}

void Panel::setInkColor(const QColor &color)
{
    Q_D(Panel);

    d->inkColor = color;

    MATERIAL_DISABLE_THEME_COLORS
    d->inkBar->update();
    update();
}

QColor Panel::inkColor() const
{
    Q_D(const Panel);

    if (d->useThemeColors || !d->inkColor.isValid()) {
        return QtMaterialStyle::instance().themeColor("accent1");
    } else {
        return d->inkColor;
    }
}

void Panel::setBackgroundColor(const QColor &color)
{
    Q_D(Panel);

    d->backgroundColor = color;

    MATERIAL_DISABLE_THEME_COLORS
    updateTabs();
    update();
}

QColor Panel::backgroundColor() const
{
    Q_D(const Panel);

    if (d->useThemeColors || !d->backgroundColor.isValid()) {
        return QtMaterialStyle::instance().themeColor("primary1");
    } else {
        return d->backgroundColor;
    }
}

void Panel::setTextColor(const QColor &color)
{
    Q_D(Panel);

    d->textColor = color;

    MATERIAL_DISABLE_THEME_COLORS
    updateTabs();
    update();
}

QColor Panel::textColor() const
{
    Q_D(const Panel);

    if (d->useThemeColors || !d->textColor.isValid()) {
        return QtMaterialStyle::instance().themeColor("canvas");
    } else {
        return d->textColor;
    }
}

void Panel::setCurrentTab(PanelTab *tab)
{
    Q_D(Panel);

    setCurrentTab(d->tabLayout->indexOf(tab));
}

void Panel::setCurrentTab(int index)
{
    Q_D(Panel);

    setTabActive(d->tab, false);
    d->tab = index;
    setTabActive(index, true);
    d->inkBar->animate();

    emit currentChanged(index);
}

void Panel::addTab(const QString &text, const QIcon &icon)
{
    Q_D(Panel);

    auto *tab = new PanelTab(this);
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

void Panel::addStretch()
{
    Q_D(Panel);

    d->tabLayout->addStretch(1);
}

int Panel::currentIndex() const
{
    Q_D(const Panel);

    return d->tab;
}

void Panel::setTabActive(int index, bool active)
{
    Q_D(Panel);

    PanelTab *tab;

    if (index > -1) {
        tab = dynamic_cast<PanelTab *>(d->tabLayout->itemAt(index)->widget());
        if (tab) {
            tab->setActive(active);
        }
    }
}

void Panel::updateTabs()
{
    Q_D(Panel);

    PanelTab *tab;
    for (int i = 0; i < d->tabLayout->count(); ++i) {
        QLayoutItem *item = d->tabLayout->itemAt(i);
        if ((tab = dynamic_cast<PanelTab *>(item->widget()))) {
            tab->setRippleStyle(d->rippleStyle);
            tab->setHaloVisible(d->showHalo);
            tab->setBackgroundColor(backgroundColor());
            tab->setForegroundColor(textColor());
        }
    }
}

void Panel::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);

    QPainter painter(this);
    painter.setBrush(brush);
    painter.setOpacity(1);
    painter.setPen(Qt::NoPen);
    painter.drawRect(rect());
}
