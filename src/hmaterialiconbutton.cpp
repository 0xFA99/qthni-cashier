#include <QPainter>
#include <QEvent>

#include "hmaterialiconbutton.h"
#include "hmaterialiconbutton_p.h"

#include "hmaterialstyle.h"
#include "hmaterialrippleoverlay.h"

HMaterialIconButtonPrivate::HMaterialIconButtonPrivate(HMaterialIconButton *q)
    : q_ptr(q)
{
}

HMaterialIconButtonPrivate::~HMaterialIconButtonPrivate()
{
}

void HMaterialIconButtonPrivate::init()
{
    Q_Q(HMaterialIconButton);

    rippleOverlay   = new HMaterialRippleOverlay(q->parentWidget());
    useThemeColors  = true;

    rippleOverlay->installEventFilter(q);

    q->setStyle(&HMaterialStyle::instance());

    QSizePolicy policy;
    policy.setWidthForHeight(true);
    q->setSizePolicy(policy);
}

void HMaterialIconButtonPrivate::updateRipple()
{
    Q_Q(HMaterialIconButton);

    QRect r(q->rect());
    r.setSize(QSize(q->width() * 2, q->height() * 2));
    r.moveCenter(q->geometry().center());
    rippleOverlay->setGeometry(r);
}

HMaterialIconButton::HMaterialIconButton(const QIcon &icon, QWidget *parent)
    : QAbstractButton(parent),
      d_ptr(new HMaterialIconButtonPrivate(this))
{
    d_func()->init();

    setIcon(icon);
}

HMaterialIconButton::~HMaterialIconButton()
{
}

QSize HMaterialIconButton::sizeHint() const
{
    return iconSize();
}

void HMaterialIconButton::setUseThemeColors(bool value)
{
    Q_D(HMaterialIconButton);

    if (d->useThemeColors == value)
        return;

    d->useThemeColors = value;
    update();
}

bool HMaterialIconButton::useThemeColors() const
{
    Q_D(const HMaterialIconButton);

    return d->useThemeColors;
}

void HMaterialIconButton::setColor(const QColor &color)
{
    Q_D(HMaterialIconButton);

    d->color = color;

    MATERIAL_DISABLE_THEME_COLORS
    update();
}

QColor HMaterialIconButton::color() const
{
    Q_D(const HMaterialIconButton);

    if (d->useThemeColors || !d->color.isValid())
        HMaterialStyle::instance().themeColor("text");

    return d->color;
}

void HMaterialIconButton::setDisabledColor(const QColor &color)
{
    Q_D(HMaterialIconButton);

    d->disabledColor = color;

    MATERIAL_DISABLE_THEME_COLORS
    update();
}

QColor HMaterialIconButton::disabledColor() const
{
    Q_D(const HMaterialIconButton);

    if (d->useThemeColors || !d->disabledColor.isValid())
        return HMaterialStyle::instance().themeColor("disabled");

    return d->disabledColor;
}

HMaterialIconButton::HMaterialIconButton(HMaterialIconButtonPrivate &d, QWidget *parent)
    : QAbstractButton(parent),
      d_ptr(&d)
{
    d_func()->init();
}

bool HMaterialIconButton::event(QEvent *event)
{
    Q_D(HMaterialIconButton);

    switch (event->type()) {
        case QEvent::Move:
        case QEvent::Resize:
            d->updateRipple();
            break;
        case QEvent::ParentChange: {
            QWidget *widget;
            if ((widget == parentWidget()))
                d->rippleOverlay->setParent(widget);

            break;
        } default:
            break;
    }

    return QAbstractButton::event(event);
}

bool HMaterialIconButton::eventFilter(QObject *obj, QEvent *event)
{
    if (QEvent::Resize == event->type()) {
        Q_D(HMaterialIconButton);
        d->updateRipple();
    }

    return QAbstractButton::eventFilter(obj, event);
}

void HMaterialIconButton::mousePressEvent(QMouseEvent *event)
{
    Q_D(HMaterialIconButton);

    d->rippleOverlay->addRipple(QPoint(d->rippleOverlay->width(),
                                       d->rippleOverlay->height()) / 2,
                                iconSize().width());
    emit clicked();

    QAbstractButton::mousePressEvent(event);
}

void HMaterialIconButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);

    QPixmap pixmap = icon().pixmap(iconSize());
    QPainter icon(&pixmap);
    icon.setCompositionMode(QPainter::CompositionMode_SourceIn);
    icon.fillRect(pixmap.rect(), isEnabled() ? color() : disabledColor());

    QRect r(rect());
    const qreal w = pixmap.width();
    const qreal h = pixmap.height();
    painter.drawPixmap(QRect((r.width() - w) / 2, (r.height() - h) / 2, w, h), pixmap);
}
