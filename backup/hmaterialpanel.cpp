
#include "hmaterialpanel.h"
#include "hmaterialpanel_p.h"
#include "hmaterialpanel_internal.h"

#include <QVBoxLayout>
#include <QSizePolicy>

#include "hmaterialstyle.h"
#include "hmaterialtheme.h"
#include "hthemecontrol.h"

HMaterialPanelPrivate::HMaterialPanelPrivate(HMaterialPanel *q)
    : q_ptr(q)
{
}

HMaterialPanelPrivate::~HMaterialPanelPrivate()
{
}

void HMaterialPanelPrivate::HMaterialPanelPrivate::init()
{
    Q_Q(HMaterialPanel);

    m_panelLayout   = new QVBoxLayout;
    m_item          = -1;

    q->setLayout(m_panelLayout);
}

HMaterialPanel::HMaterialPanel(QWidget *parent)
    : HMaterialFrame(HMaterial::Level1, parent)
    , d_ptr(new HMaterialPanelPrivate(this))
{
    d_func()->init();

    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
}

HMaterialPanel::~HMaterialPanel()
{
}

void HMaterialPanel::setCurrentItem(HMaterialPanelItem *item)
{
    Q_D(HMaterialPanel);

    setCurrentItem(d->m_panelLayout->indexOf(item));
}

void HMaterialPanel::setCurrentItem(int index)
{
    Q_D(HMaterialPanel);

    setItemActive(d->m_item, false);
    d->m_item = index;
    setItemActive(index, true);
    
    emit currentChanged(index);
}

void HMaterialPanel::addStretch(int value)
{
    Q_D(HMaterialPanel);

    d->m_panelLayout->addStretch(value);
}

void HMaterialPanel::addThemeControl()
{
    Q_D(HMaterialPanel);

    HThemeControl *themeControl = HThemeControl::getThemeControl();
    themeControl->setIconSize(QSize(18, 18));
    themeControl->setIconPlacement(HMaterial::CenterIcon);

    d->m_panelLayout->addWidget(themeControl);
}

void HMaterialPanel::addItem(const QIcon &icon)
{
    Q_D(HMaterialPanel);

    HMaterialPanelItem *item = new HMaterialPanelItem(this);

    item->setIcon(icon);
    item->setIconSize(QSize(18, 18));
    item->setIconPlacement(HMaterial::CenterIcon);

    d->m_panelLayout->addWidget(item);
    
    if (d->m_item == -1) {
        d->m_item = 0;
        item->setActive(true);
    }
}

int HMaterialPanel::currentIndex() const
{
    Q_D(const HMaterialPanel);

    return d->m_item;
}

void HMaterialPanel::setItemActive(int index, bool active)
{
    Q_D(HMaterialPanel);

    HMaterialPanelItem *item;

    if (index > -1) {
        item = static_cast<HMaterialPanelItem *>(d->m_panelLayout->itemAt(index)->widget());
        if (item) {
            item->setActive(active);
        }
    }
}

void HMaterialPanel::updateItems()
{
    Q_D(HMaterialPanel);

    HPanelItem *tab;
    for (int i = 0; i < d->m_panelLayout->count(); i++) {
        QLayoutItem *item = d->m_panelLayout->itemAt(i);
        if ((tab = static_cast<HPanelItem *>(item->widget()))) {
            tab->setBackgroundColor(backgroundColor());
            tab->setForegroundColor(textColor());
        }
    }
}

void HMaterialPanel::setBackgroundColor(const QColor &color)
{
    Q_D(HMaterialPanel);

    d->m_backgroundColor = color;

    updateItems();
    update();
}

QColor HMaterialPanel::backgroundColor() const
{
    Q_D(const HMaterialPanel);

    return d->m_backgroundColor;
}

void HMaterialPanel::setTextColor(const QColor &color)
{
    Q_D(HMaterialPanel);

    d->m_textColor = color;

    updateItems();
    update();
}

QColor HMaterialPanel::textColor() const
{
    Q_D(const HMaterialPanel);

    return d->m_textColor;
}
