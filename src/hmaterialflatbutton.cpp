#include <QPainter>
#include <QMouseEvent>
#include <QResizeEvent>
#include <QBitmap>
#include <QPainterPath>
#include <QIcon>

#include "hmaterialflatbutton_internal.h"
#include "hmaterialflatbutton.h"
#include "hmaterialflatbutton_p.h"

#include "hmaterialrippleoverlay.h"
#include "hmaterialripple.h"
#include "hmaterialstyle.h"

#define COLOR_INTERPOLATE(CH) (1-progress)*source.CH() + progress*dest.CH()

HMaterialFlatButtonPrivate::HMaterialFlatButtonPrivate(HMaterialFlatButton *q)
    : q_ptr(q)
{
}

HMaterialFlatButtonPrivate::~HMaterialFlatButtonPrivate()
{
}

void HMaterialFlatButtonPrivate::init()
{
    Q_Q(HMaterialFlatButton);

    rippleOverlay        = new HMaterialRippleOverlay(q);
    stateMachine         = new HMaterialFlatButtonStateMachine(q);
    role                 = HMaterial::Default;
    rippleStyle          = HMaterial::PositionedRipple;
    iconPlacement        = HMaterial::LeftIcon;
    overlayStyle         = HMaterial::GrayOverlay;
    bgMode               = Qt::TransparentMode;
    textAlignment        = Qt::AlignHCenter;
    fixedRippleRadius    = 64;
    cornerRadius         = 3;
    baseOpacity          = 0.13;
    fontSize             = 10;        
    useThemeColors       = true;
    useFixedRippleRadius = false;
    haloVisible          = true;

    q->setStyle(&HMaterialStyle::instance());
    q->setAttribute(Qt::WA_Hover);
    q->setMouseTracking(true);

    QFont font("Roboto", fontSize, QFont::Medium);
    font.setCapitalization(QFont::AllUppercase);
    q->setFont(font);

    QPainterPath path;
    path.addRoundedRect(q->rect(), cornerRadius, cornerRadius);
    rippleOverlay->setClipPath(path);
    rippleOverlay->setClipping(true);

    stateMachine->setupProperties();
    stateMachine->startAnimations();
}

HMaterialFlatButton::HMaterialFlatButton(QWidget *parent, HMaterial::ButtonPreset preset)
    : QPushButton(parent),
      d_ptr(new HMaterialFlatButtonPrivate(this))
{
    d_func()->init();

    applyPreset(preset);
}

HMaterialFlatButton::HMaterialFlatButton(const QString &text, QWidget *parent, HMaterial::ButtonPreset preset)
    : QPushButton(text, parent),
      d_ptr(new HMaterialFlatButtonPrivate(this))
{
    d_func()->init();

    applyPreset(preset);
}

HMaterialFlatButton::HMaterialFlatButton(const QString &text, HMaterial::Role role, QWidget *parent, HMaterial::ButtonPreset preset)
    : QPushButton(text, parent),
      d_ptr(new HMaterialFlatButtonPrivate(this))
{
    d_func()->init();

    applyPreset(preset);
    setRole(role);
}

HMaterialFlatButton::~HMaterialFlatButton()
{
}

void HMaterialFlatButton::applyPreset(HMaterial::ButtonPreset preset)
{
    switch (preset)
    {
    case HMaterial::FlatPreset:
        setOverlayStyle(HMaterial::NoOverlay);
        break;
    case HMaterial::CheckablePreset:
        setOverlayStyle(HMaterial::NoOverlay);
        setCheckable(true);
        setHaloVisible(false);
        break;
    default:
        break;
    }
}

void HMaterialFlatButton::setUseThemeColors(bool value)
{
    Q_D(HMaterialFlatButton);

    if (d->useThemeColors == value) {
        return;
    }

    d->useThemeColors = value;
    d->stateMachine->setupProperties();
}

bool HMaterialFlatButton::useThemeColors() const
{
    Q_D(const HMaterialFlatButton);

    return d->useThemeColors;
}

void HMaterialFlatButton::setRole(HMaterial::Role role)
{
    Q_D(HMaterialFlatButton);

    d->role = role;
    d->stateMachine->setupProperties();
}

HMaterial::Role HMaterialFlatButton::role() const
{
    Q_D(const HMaterialFlatButton);

    return d->role;
}

void HMaterialFlatButton::setForegroundColor(const QColor &color)
{
    Q_D(HMaterialFlatButton);

    d->foregroundColor = color;

    MATERIAL_DISABLE_THEME_COLORS
    update();
}

QColor HMaterialFlatButton::foregroundColor() const
{
    Q_D(const HMaterialFlatButton);

    if (d->useThemeColors || !d->foregroundColor.isValid())
    {
        if (Qt::OpaqueMode == d->bgMode) {
            return HMaterialStyle::instance().themeColor("canvas");
        }
        switch (d->role)
        {
        case HMaterial::Primary:
            return HMaterialStyle::instance().themeColor("primary1");
        case HMaterial::Secondary:
            return HMaterialStyle::instance().themeColor("accent1");
        case HMaterial::Default:
        default:
            return HMaterialStyle::instance().themeColor("text");
        }
    }
    return d->foregroundColor;
}

void HMaterialFlatButton::setBackgroundColor(const QColor &color)
{
    Q_D(HMaterialFlatButton);

    d->backgroundColor = color;

    MATERIAL_DISABLE_THEME_COLORS
    update();
}

QColor HMaterialFlatButton::backgroundColor() const
{
    Q_D(const HMaterialFlatButton);

    if (d->useThemeColors || !d->backgroundColor.isValid())
    {
        switch (d->role)
        {
        case HMaterial::Primary:
            return HMaterialStyle::instance().themeColor("primary1");
        case HMaterial::Secondary:
            return HMaterialStyle::instance().themeColor("accent1");
        case HMaterial::Default:
        default:
            return HMaterialStyle::instance().themeColor("text");
        }
    }
    return d->backgroundColor;
}

void HMaterialFlatButton::setOverlayColor(const QColor &color)
{
    Q_D(HMaterialFlatButton);

    d->overlayColor = color;

    MATERIAL_DISABLE_THEME_COLORS

    setOverlayStyle(HMaterial::TintedOverlay);
    update();
}

QColor HMaterialFlatButton::overlayColor() const
{
    Q_D(const HMaterialFlatButton);

    if (d->useThemeColors || !d->overlayColor.isValid()) {
        return foregroundColor();
    }
    return d->overlayColor;
}

void HMaterialFlatButton::setDisabledForegroundColor(const QColor &color)
{
    Q_D(HMaterialFlatButton);

    d->disabledColor = color;

    MATERIAL_DISABLE_THEME_COLORS
    update();
}

QColor HMaterialFlatButton::disabledForegroundColor() const
{
    Q_D(const HMaterialFlatButton);

    if (d->useThemeColors || !d->disabledColor.isValid()) {
        return HMaterialStyle::instance().themeColor("disabled");
    } else {
        return d->disabledColor;
    }
}

void HMaterialFlatButton::setDisabledBackgroundColor(const QColor &color)
{
    Q_D(HMaterialFlatButton);

    d->disabledBackgroundColor = color;

    MATERIAL_DISABLE_THEME_COLORS
    update();
}

QColor HMaterialFlatButton::disabledBackgroundColor() const
{
    Q_D(const HMaterialFlatButton);

    if (d->useThemeColors || !d->disabledBackgroundColor.isValid()) {
        return HMaterialStyle::instance().themeColor("disabled3");
    } else {
        return d->disabledBackgroundColor;
    }
}

void HMaterialFlatButton::setFontSize(qreal size)
{
    Q_D(HMaterialFlatButton);

    d->fontSize = size;

    QFont f(font());
    f.setPointSizeF(size);
    setFont(f);

    update();
}

qreal HMaterialFlatButton::fontSize() const
{
    Q_D(const HMaterialFlatButton);

    return d->fontSize;
}

void HMaterialFlatButton::setHaloVisible(bool visible)
{
    Q_D(HMaterialFlatButton);

    d->haloVisible = visible;
    update();
}

bool HMaterialFlatButton::isHaloVisible() const
{
    Q_D(const HMaterialFlatButton);

    return d->haloVisible;
}

void HMaterialFlatButton::setOverlayStyle(HMaterial::OverlayStyle style)
{
    Q_D(HMaterialFlatButton);

    d->overlayStyle = style;
    update();
}

HMaterial::OverlayStyle HMaterialFlatButton::overlayStyle() const
{
    Q_D(const HMaterialFlatButton);

    return d->overlayStyle;
}

void HMaterialFlatButton::setRippleStyle(HMaterial::RippleStyle style)
{
    Q_D(HMaterialFlatButton);

    d->rippleStyle = style;
}

HMaterial::RippleStyle HMaterialFlatButton::rippleStyle() const
{
    Q_D(const HMaterialFlatButton);

    return d->rippleStyle;
}

void HMaterialFlatButton::setIconPlacement(HMaterial::ButtonIconPlacement placement)
{
    Q_D(HMaterialFlatButton);

    d->iconPlacement = placement;
    update();
}

HMaterial::ButtonIconPlacement HMaterialFlatButton::iconPlacement() const
{
    Q_D(const HMaterialFlatButton);

    return d->iconPlacement;
}

void HMaterialFlatButton::setCornerRadius(qreal radius)
{
    Q_D(HMaterialFlatButton);

    d->cornerRadius = radius;
    updateClipPath();
    update();
}

qreal HMaterialFlatButton::cornerRadius() const
{
    Q_D(const HMaterialFlatButton);

    return d->cornerRadius;
}

void HMaterialFlatButton::setBackgroundMode(Qt::BGMode mode)
{
    Q_D(HMaterialFlatButton);

    d->bgMode = mode;
    d->stateMachine->setupProperties();
}

Qt::BGMode HMaterialFlatButton::backgroundMode() const
{
    Q_D(const HMaterialFlatButton);

    return d->bgMode;
}

void HMaterialFlatButton::setBaseOpacity(qreal opacity)
{
    Q_D(HMaterialFlatButton);

    d->baseOpacity = opacity;
    d->stateMachine->setupProperties();
}

qreal HMaterialFlatButton::baseOpacity() const
{
    Q_D(const HMaterialFlatButton);

    return d->baseOpacity;
}

void HMaterialFlatButton::setCheckable(bool value)
{
    Q_D(HMaterialFlatButton);

    d->stateMachine->updateCheckedStatus();

    QPushButton::setCheckable(value);
}

void HMaterialFlatButton::setHasFixedRippleRadius(bool value)
{
    Q_D(HMaterialFlatButton);

    d->useFixedRippleRadius = value;
}

bool HMaterialFlatButton::hasFixedRippleRadius() const
{
    Q_D(const HMaterialFlatButton);

    return d->useFixedRippleRadius;
}

void HMaterialFlatButton::setFixedRippleRadius(qreal radius)
{
    Q_D(HMaterialFlatButton);

    d->fixedRippleRadius = radius;
    setHasFixedRippleRadius(true);
}

void HMaterialFlatButton::setTextAlignment(Qt::Alignment alignment)
{
    Q_D(HMaterialFlatButton);

    d->textAlignment = alignment;
}

Qt::Alignment HMaterialFlatButton::textAlignment() const
{
    Q_D(const HMaterialFlatButton);

    return d->textAlignment;
}

QSize HMaterialFlatButton::sizeHint() const
{
    ensurePolished();

    QSize label(fontMetrics().size(Qt::TextSingleLine, text()));

    int w = 20 + label.width();
    int h = label.height();
    if (!icon().isNull()) {
        w += iconSize().width() + HMaterialFlatButton::IconPadding;
        h = qMax(h, iconSize().height());
    }
    return QSize(w, 20 + h);
}

HMaterialFlatButton::HMaterialFlatButton(HMaterialFlatButtonPrivate &d,QWidget *parent, HMaterial::ButtonPreset preset)
    : QPushButton(parent),
      d_ptr(&d)
{
    d_func()->init();

    applyPreset(preset);
}

void HMaterialFlatButton::checkStateSet()
{
    Q_D(HMaterialFlatButton);

    d->stateMachine->updateCheckedStatus();

    QPushButton::checkStateSet();
}

void HMaterialFlatButton::mousePressEvent(QMouseEvent *event)
{
    Q_D(HMaterialFlatButton);

    if (HMaterial::NoRipple != d->rippleStyle)
    {
        QPoint pos;
        qreal radiusEndValue;

        if (HMaterial::CenteredRipple == d->rippleStyle) {
            pos = rect().center();
        } else {
            pos = event->pos();
        }

        if (d->useFixedRippleRadius) {
            radiusEndValue = d->fixedRippleRadius;
        } else {
            radiusEndValue = static_cast<qreal>(width())/2;
        }

        HMaterialRipple *ripple = new HMaterialRipple(pos);

        ripple->setRadiusEndValue(radiusEndValue);
        ripple->setOpacityStartValue(0.35);
        ripple->setColor(foregroundColor());
        ripple->radiusAnimation()->setDuration(600);
        ripple->opacityAnimation()->setDuration(1300);

        d->rippleOverlay->addRipple(ripple);
    }

    QPushButton::mousePressEvent(event);
}

void HMaterialFlatButton::mouseReleaseEvent(QMouseEvent *event)
{
    Q_D(HMaterialFlatButton);

    QPushButton::mouseReleaseEvent(event);

    d->stateMachine->updateCheckedStatus();
}

void HMaterialFlatButton::resizeEvent(QResizeEvent *event)
{
    QPushButton::resizeEvent(event);

    updateClipPath();
}

void HMaterialFlatButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    Q_D(HMaterialFlatButton);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    const qreal cr = d->cornerRadius;

    if (cr > 0)
    {
        QPainterPath path;
        path.addRoundedRect(rect(), cr, cr);

        painter.setClipPath(path);
        painter.setClipping(true);
    }

    paintBackground(&painter);
    paintHalo(&painter);

    painter.setOpacity(1);
    painter.setClipping(false);

    paintForeground(&painter);
}

void HMaterialFlatButton::paintBackground(QPainter *painter)
{
    Q_D(HMaterialFlatButton);

    const qreal overlayOpacity = d->stateMachine->overlayOpacity();
    const qreal checkedProgress = d->stateMachine->checkedOverlayProgress();

    if (Qt::OpaqueMode == d->bgMode) {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        if (isEnabled()) {
            brush.setColor(backgroundColor());
        } else {
            brush.setColor(disabledBackgroundColor());
        }
        painter->setOpacity(1);
        painter->setBrush(brush);
        painter->setPen(Qt::NoPen);
        painter->drawRect(rect());
    }

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    painter->setPen(Qt::NoPen);

    if (!isEnabled()) {
        return;
    }

    if ((HMaterial::NoOverlay != d->overlayStyle) && (overlayOpacity > 0)) {
        if (HMaterial::TintedOverlay == d->overlayStyle) {
            brush.setColor(overlayColor());
        } else {
            brush.setColor(Qt::gray);
        }
        painter->setOpacity(overlayOpacity);
        painter->setBrush(brush);
        painter->drawRect(rect());
    }

    if (isCheckable() && checkedProgress > 0) {
        const qreal q = Qt::TransparentMode == d->bgMode ? 0.45 : 0.7;
        brush.setColor(foregroundColor());
        painter->setOpacity(q*checkedProgress);
        painter->setBrush(brush);
        QRect r(rect());
        r.setHeight(static_cast<qreal>(r.height())*checkedProgress);
        painter->drawRect(r);
    }
}

void HMaterialFlatButton::paintHalo(QPainter *painter)
{
    Q_D(HMaterialFlatButton);

    if (!d->haloVisible) {
        return;
    }

    const qreal opacity = d->stateMachine->haloOpacity();
    const qreal s = d->stateMachine->haloScaleFactor()*d->stateMachine->haloSize();
    const qreal radius = static_cast<qreal>(width())*s;

    if (isEnabled() && opacity > 0) {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(foregroundColor());
        painter->setOpacity(opacity);
        painter->setBrush(brush);
        painter->setPen(Qt::NoPen);
        const QPointF center = rect().center();
        painter->drawEllipse(center, radius, radius);
    }
}

void HMaterialFlatButton::paintForeground(QPainter *painter)
{
    Q_D(HMaterialFlatButton);

    if (isEnabled()) {
        painter->setPen(foregroundColor());
        const qreal progress = d->stateMachine->checkedOverlayProgress();
        if (isCheckable() && progress > 0) {
            QColor source = foregroundColor();
            QColor dest = Qt::TransparentMode == d->bgMode ? Qt::white
                                                           : backgroundColor();
            if (qFuzzyCompare(1, progress)) {
                painter->setPen(dest);
            } else {
                painter->setPen(QColor(COLOR_INTERPOLATE(red),
                                       COLOR_INTERPOLATE(green),
                                       COLOR_INTERPOLATE(blue),
                                       COLOR_INTERPOLATE(alpha)));
            }
        }
    } else {
        painter->setPen(disabledForegroundColor());
    }

    if (icon().isNull())  {
        if (Qt::AlignLeft == d->textAlignment) {
            painter->drawText(rect().adjusted(12, 0, 0, 0), Qt::AlignLeft | Qt::AlignVCenter, text());
        } else {
            painter->drawText(rect(), Qt::AlignCenter, text());
        }
        return;
    }

    QSize textSize(fontMetrics().size(Qt::TextSingleLine, text()));
    QSize base(size()-textSize);

    const int iw = iconSize().width() + IconPadding;
    QPoint pos(Qt::AlignLeft == d->textAlignment ? 12 : (base.width()-iw)/2, 0);

    QRect textGeometry(pos + QPoint(0, base.height()/2), textSize);
    QRect iconGeometry(pos + QPoint(0, (height()-iconSize().height())/2), iconSize());

    if (HMaterial::LeftIcon == d->iconPlacement) {
        textGeometry.translate(iw, 0);
    } else {
        iconGeometry.translate(textSize.width() + IconPadding, 0);
    }

    painter->drawText(textGeometry, Qt::AlignCenter, text());

    QPixmap pixmap = icon().pixmap(iconSize());
    QPainter icon(&pixmap);
    icon.setCompositionMode(QPainter::CompositionMode_SourceIn);
    icon.fillRect(pixmap.rect(), painter->pen().color());
    painter->drawPixmap(iconGeometry, pixmap);
}

void HMaterialFlatButton::updateClipPath()
{
    Q_D(HMaterialFlatButton);

    const qreal radius = d->cornerRadius;

    QPainterPath path;
    path.addRoundedRect(rect(), radius, radius);
    d->rippleOverlay->setClipPath(path);
}
