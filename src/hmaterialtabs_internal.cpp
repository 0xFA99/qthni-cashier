#include <QPainter>
#include <QPropertyAnimation>
#include <QLayoutItem>
#include <QLayout>
#include <QEvent>
#include <QDebug>

#include "hmaterialtabs_internal.h"
#include "hmaterialtabs.h"

HMaterialTabsInkBar::HMaterialTabsInkBar(HMaterialTabs *parent)
    : HMaterialOverlayWidget(parent),
      m_tabs(parent),
      m_animation(new QPropertyAnimation(parent)),
      m_tween(0)
{
    Q_ASSERT(parent);

    m_animation->setPropertyName("tweenValue");
    m_animation->setEasingCurve(QEasingCurve::OutCirc);
    m_animation->setTargetObject(this);
    m_animation->setDuration(700);

    m_tabs->installEventFilter(this);

    setAttribute(Qt::WA_TransparentForMouseEvents);
    setAttribute(Qt::WA_NoSystemBackground);
}

HMaterialTabsInkBar::~HMaterialTabsInkBar()
{
}

void HMaterialTabsInkBar::refreshGeometry()
{
    QLayoutItem *item = m_tabs->layout()->itemAt(m_tabs->currentIndex());

    if (item) {
        const QRect rect(item->geometry());
        const qreal size = 1 - m_tween;

        if (QAbstractAnimation::Running != m_animation->state()) {
            m_geometry = QRect(rect.left(), rect.bottom() - 1, rect.width(), 2);
        } else {
            const qreal left = m_previousGeometry.left() * size + rect.left() * m_tween;
            const qreal width = m_previousGeometry.width() * size + rect.width() * m_tween;
            m_geometry = QRect(left, rect.bottom() - 1, width, 2);
        }

        m_tabs->update();
    }
}

void HMaterialTabsInkBar::animate()
{
    raise();

    m_previousGeometry = m_geometry;

    m_animation->stop();
    m_animation->setStartValue(0);
    m_animation->setEndValue(1);
    m_animation->start();
}

bool HMaterialTabsInkBar::eventFilter(QObject *obj, QEvent *event)
{
    switch (event->type()) {
        case QEvent::Move:
        case QEvent::Resize: {
            refreshGeometry();
            break;
        }
        default:
            break;
    }
    
    return HMaterialOverlayWidget::eventFilter(obj, event);
}

void HMaterialTabsInkBar::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);

    painter.setOpacity(1);
    painter.fillRect(m_geometry, m_tabs->inkColor());
}

HMaterialTab::HMaterialTab(HMaterialTabs *parent)
    : HMaterialFlatButton(parent),
      m_tabs(parent),
      m_active(false)
{
    Q_ASSERT(parent);

    setMinimumHeight(50);

    QFont f(font());
    f.setStyleName("Normal");
    setFont(f);

    setCornerRadius(0);
    setRole(HMaterial::Primary);
    setBackgroundMode(Qt::OpaqueMode);
    setBaseOpacity(0.25);

    QObject::connect(this, SIGNAL(clicked(bool)), this, SLOT(activeTab()));
}

HMaterialTab::~HMaterialTab()
{
}

QSize HMaterialTab::sizeHint() const
{
    if (icon().isNull()) {
        return HMaterialFlatButton::sizeHint();
    } else {
        return QSize(40, iconSize().height() + 46);
    }
}

void HMaterialTab::activeTab()
{
    m_tabs->setCurrentTab(this);
}

void HMaterialTab::paintForeground(QPainter *painter)
{
    painter->setPen(foregroundColor());

    if (!icon().isNull()) {
        painter->translate(0, 12);
    }

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

    if (!m_active) {
        if (!icon().isNull())
            painter->translate(0, -12);

        QBrush overlay;
        overlay.setStyle(Qt::SolidPattern);
        overlay.setColor(backgroundColor());
        painter->setOpacity(0.36);
        painter->fillRect(rect(), overlay);
    }
}

