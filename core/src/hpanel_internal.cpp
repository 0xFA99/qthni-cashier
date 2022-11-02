#include "hpanel.h"
#include "hpanel_internal.h"

#include <QPainter>

#include "hmaterialtheme.h"

HPanelItem::HPanelItem(const QString &text, HPanel *parent)
    : HMaterialFlatButton(text, parent)
    , m_panel(parent)
    , m_active(false)
{
    setFont(QFont("iconfont", 18, QFont::Medium));
    setForegroundColor(QColor(0, 0, 0, 115));
    setHaloVisible(false);
    setOverlayStyle(HMaterial::GrayOverlay);
    setRippleStyle(HMaterial::NoRipple);
    setBaseOpacity(1);
    setCornerRadius(sizeHint().height() / 2);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    
    QObject::connect(this, SIGNAL(clicked(bool)), this, SLOT(activeItem()));
}

HPanelItem::~HPanelItem()
{
}

void HPanelItem::activeItem()
{
    m_panel->setCurrentItem(this);
}

void HPanelItem::paintForeground(QPainter *painter)
{
    /*
    if (!m_active) {
        painter->setPen(foregroundColor());
        setOverlayColor(foregroundColor());
    } else {
        painter->setPen(QColor(38, 115, 221));
        setOverlayColor(QColor(38, 115, 221));
    }

    // Text
    int x = (this->rect().width() - size().width()) / 2;
    int y = ((this->rect().height() - size().height()) / 2) + (iconSize().height() / 1.33);

    QRect textGeometry(x, y, size().width(), size().height());

    painter->drawText(textGeometry, Qt::AlignCenter, text());

    // Icon
    QPixmap pixmap = icon().pixmap(iconSize());
    QPainter icon(&pixmap);
    icon.setCompositionMode(QPainter::CompositionMode_SourceIn);
    icon.fillRect(pixmap.rect(), painter->pen().color());

    const QSize &size = iconSize();
    x = (this->rect().width() - pixmap.width()) / 2;
    y = ((this->rect().height() - pixmap.height()) / 2) - (iconSize().height() / 1.33);

    QRect iconGeometry(x, y, pixmap.width(), pixmap.height());

    painter->drawPixmap(iconGeometry, pixmap);
    */
    // 000
    if (m_active) {
        painter->setPen(QColor(101, 126, 248)); 
    } else {
        painter->setPen(foregroundColor());
    }

    painter->drawText(rect(), Qt::AlignCenter, text());
}
