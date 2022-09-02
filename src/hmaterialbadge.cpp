#include <QPainter>

#include "hmaterialbadge.h"
#include "hmaterialbadge_p.h"

#include "hmaterialstyle.h"

HMaterialBadgePrivate::HMaterialBadgePrivate(HMaterialBadge *q)
    : q_ptr(q)
{
}

HMaterialBadgePrivate::~HMaterialBadgePrivate()
{
}

void HMaterialBadgePrivate::init()
{
    Q_Q(HMaterialBadge);

    x               = 0;
    y               = 0;
    padding         = 10;
    useThemeColors  = true;

    q->setAttribute(Qt::WA_TransparentForMouseEvents);

    QFont font(q->font());
    font.setPointSizeF(10);
    font.setStyleName("Bold");
    q->setFont(font);

    q->setText("+1");
}

HMaterialBadge::HMaterialBadge(QWidget *parent)
    : HMaterialOverlayWidget(parent),
      d_ptr(new HMaterialBadgePrivate(this))
{
    d_func()->init();
}

HMaterialBadge::HMaterialBadge(const QIcon icon, QWidget *parent)
    : HMaterialOverlayWidget(parent),
      d_ptr(new HMaterialBadgePrivate(this))
{
    d_func()->init();

    setIcon(icon);
}

HMaterialBadge::HMaterialBadge(const QString &text, QWidget *parent)
    : HMaterialOverlayWidget(parent),
      d_ptr(new HMaterialBadgePrivate(this))
{
    d_func()->init();

    setText(text);
}

HMaterialBadge::~HMaterialBadge()
{
}

void HMaterialBadge::setUseThemeColors(bool value)
{
    Q_D(HMaterialBadge);

    if (d->useThemeColors == value)
        return;

    d->useThemeColors = value;
    update();
}

bool HMaterialBadge::useThemeColors() const
{
    Q_D(const HMaterialBadge);

    return d->useThemeColors;
}

void HMaterialBadge::setTextColor(const QColor &color)
{
    Q_D(HMaterialBadge);

    d->textColor = color;

    MATERIAL_DISABLE_THEME_COLORS
    update();
}

QColor HMaterialBadge::textColor() const
{
    Q_D(const HMaterialBadge);

    if (d->useThemeColors || !d->textColor.isValid()) {
        return HMaterialStyle::instance().themeColor("canvas");
    } else {
        return d->textColor;
    }
}


void HMaterialBadge::setBackgroundColor(const QColor &color)
{
    Q_D(HMaterialBadge);

    d->backgroundColor = color;

    MATERIAL_DISABLE_THEME_COLORS
    update();
}

QColor HMaterialBadge::backgroundColor() const
{
    Q_D(const HMaterialBadge);

    if (d->useThemeColors || !d->textColor.isValid()) {
        return HMaterialStyle::instance().themeColor("accent1");
    } else {
        return d->backgroundColor;
    }
}

void HMaterialBadge::setRelativePosition(const QPointF &pos)
{
    setRelativePosition(pos.x(), pos.y());
}

void HMaterialBadge::setRelativePosition(qreal x, qreal y)
{
    Q_D(HMaterialBadge);

    d->x = x;
    d->y = y;
    update();
}

QPointF HMaterialBadge::relativePosition() const
{
    Q_D(const HMaterialBadge);

    return QPointF(d->x, d->y);
}

void HMaterialBadge::setRelativeXPosition(qreal x)
{
    Q_D(HMaterialBadge);

    d->x = x;
    update();
}

qreal HMaterialBadge::relativeXPosition() const 
{
    Q_D(const HMaterialBadge);

    return d->x;
}

void HMaterialBadge::setRelativeYPosition(qreal y)
{
    Q_D(HMaterialBadge);

    d->y = y;
    update();
}

qreal HMaterialBadge::relativeYPosition() const
{
    Q_D(const HMaterialBadge);

    return d->y;
}

QSize HMaterialBadge::sizeHint() const
{
    const int s = getDiameter();
    return QSize(s + 4, s + 4);
}

void HMaterialBadge::setIcon(const QIcon &icon)
{
    Q_D(HMaterialBadge);

    d->icon = icon;
    update();
}

QIcon HMaterialBadge::icon() const
{
    Q_D(const HMaterialBadge);

    return d->icon;
}

void HMaterialBadge::setText(const QString &text)
{
    Q_D(HMaterialBadge);

    d->text = text;

    if (!d->icon.isNull())
        d->icon = QIcon();

    d->size = fontMetrics().size(Qt::TextShowMnemonic, text);

    update();
}

QString HMaterialBadge::text() const
{
    Q_D(const HMaterialBadge);

    return d->text;
}

void HMaterialBadge::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    Q_D(HMaterialBadge);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.translate(d->x, d->y);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(isEnabled()  ? backgroundColor()
                                : HMaterialStyle::instance().themeColor("disable"));
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);

    const int s = getDiameter();

    QRectF r(0, 0, s, s);
    r.translate(QPointF((width() - s), (height() - s)) / 2);

    if (d->icon.isNull()) {
        painter.drawEllipse(r);
        painter.setPen(textColor());
        painter.setBrush(Qt::NoBrush);
        painter.drawText(r.translated(0, -0.5), Qt::AlignCenter, d->text);
    } else {
        painter.drawEllipse(r);
        QRectF q(0, 0, 16, 16);
        q.moveCenter(r.center());
        QPixmap pixmap = icon().pixmap(16, 16);
        QPainter icon(&pixmap);
        icon.setCompositionMode(QPainter::CompositionMode_SourceIn);
        icon.fillRect(pixmap.rect(), textColor());
        painter.drawPixmap(q.toRect(), pixmap);
    }
}

int HMaterialBadge::getDiameter() const
{
    Q_D(const HMaterialBadge);

    if (d->icon.isNull()) {
        return qMax(d->size.width(), d->size.height()) + d->padding;
    } else {
        return 24;
    }
}
