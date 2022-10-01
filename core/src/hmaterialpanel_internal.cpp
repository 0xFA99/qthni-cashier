#include "hmaterialpanel_internal.h"
#include "hmaterialpanel.h"

#include <QPainter>
#include <QPainterPath>

HMaterialPanelItem::HMaterialPanelItem(HMaterialPanel *parent)
    : HMaterialButton(parent)
    , m_panel(parent)
    , m_active(false)
{
    QObject::connect(this, SIGNAL(clicked(bool)), this, SLOT(activeItem()));
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
    
    if (!icon().isNull())
        painter->translate(0, 12);

    QSize textSize(fontMetrics().size(Qt::TextSingleLine, text()));
    QSize base(size() - textSize);

    QRect textGeometry(QPoint(base.width(), base.height()) / 2, textSize);

    painter->drawText(textGeometry, Qt::AlignCenter, text());
    
    if (!icon().isNull()) {
        const QSize &size = iconSize();
        QRect iconRect(QPoint((width() - size.width()) / 2, 0), size);

        QPixmap pixmap = icon().pixmap(iconSize());
        QPainter icon(&pixmap);
        icon.setCompositionMode(QPainter::CompositionMode_SourceIn);
        icon.fillRect(pixmap.rect(), painter->pen().color());
        painter->drawPixmap(iconRect, pixmap);
    }

    if (m_active) {
        if (!icon().isNull())
            painter->translate(0, -12);

        QBrush overlay;
        overlay.setStyle(Qt::SolidPattern);
        overlay.setColor(foregroundColor());

        QPainterPath path;
        path.addRoundedRect(rect(), 8, 8);

        painter->setRenderHint(QPainter::Antialiasing);
        painter->setClipPath(path);
        painter->setClipping(true);
        painter->setOpacity(0.15);
        painter->fillRect(rect(), overlay);
    }
}

