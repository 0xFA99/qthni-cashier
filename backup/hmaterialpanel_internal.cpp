#include "hmaterialpanel_internal.h"
#include "hmaterialpanel.h"

#include <QPainter>
#include <QPainterPath>

#include <QDebug>

HMaterialPanelItem::HMaterialPanelItem(HMaterialPanel *parent)
    : HMaterialDefaultButton(parent)
    , m_panel(parent)
    , m_active(false)
{
    QObject::connect(this, SIGNAL(clicked(bool)), this, SLOT(activeItem()));

    setIconOnly();
}

HMaterialPanelItem::~HMaterialPanelItem()
{
}

void HMaterialPanelItem::activeItem()
{
    m_panel->setCurrentItem(this);
}

void HMaterialPanelItem::paintForeground(QPainter *painter)
{
    painter->setPen(foregroundColor());

    QRect square = QRect(0, 0, width(), height());
    square.moveCenter(rect().center());

    QRect iconGeometry(0, 0, iconSize().width(), iconSize().height());
    iconGeometry.moveCenter(square.center());

    QPixmap pixmap = icon().pixmap(iconSize());
    QPainter icon(&pixmap);
    icon.setCompositionMode(QPainter::CompositionMode_SourceIn);
    QColor tempColor = painter->pen().color();

    if (m_active) {
        tempColor.setAlpha(222);
        icon.fillRect(pixmap.rect(), tempColor);
    } else {
        tempColor.setAlpha(99);
        icon.fillRect(pixmap.rect(), painter->pen().color());
    }

    painter->drawPixmap(iconGeometry, pixmap);
}
