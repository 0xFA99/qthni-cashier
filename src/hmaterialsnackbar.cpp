#include <QApplication>
#include <QPainter>
#include <QDebug>

#include "hmaterialsnackbar.h"
#include "hmaterialsnackbar_p.h"
#include "hmaterialsnackbar_internal.h"

#include "hmaterialstyle.h"
#include "hmaterialstatetransition.h"

HMaterialSnackbarPrivate::HMaterialSnackbarPrivate(HMaterialSnackbar *q)
    : q_ptr(q)
{
}

HMaterialSnackbarPrivate::~HMaterialSnackbarPrivate()
{
}

void HMaterialSnackbarPrivate::init()
{
    Q_Q(HMaterialSnackbar);

    stateMachine    = new HMaterialSnackbarStateMachine(q);
    bgOpacity       = 0.9;
    duration        = 3000;
    boxWidth        = 300;
    clickDismiss    = false;
    useThemeColors  = true;

    q->setAttribute(Qt::WA_TransparentForMouseEvents);

    QFont font("Roboto", 10, QFont::Medium);
    font.setCapitalization(QFont::AllUppercase);
    q->setFont(font);

    stateMachine->start();
    QCoreApplication::processEvents();
}

HMaterialSnackbar::HMaterialSnackbar(QWidget *parent)
    : HMaterialOverlayWidget(parent),
      d_ptr(new HMaterialSnackbarPrivate(this))
{
    d_func()->init();
}

HMaterialSnackbar::~HMaterialSnackbar()
{
}

void HMaterialSnackbar::setAutoHideDuration(int duration)
{
    Q_D(HMaterialSnackbar);

    d->duration = duration;
}

int HMaterialSnackbar::autoHideDuration() const
{
    Q_D(const HMaterialSnackbar);

    return d->duration;
}

void HMaterialSnackbar::setUseThemeColors(bool value)
{
    Q_D(HMaterialSnackbar);

    if (d->useThemeColors == value)
        return;

    d->useThemeColors = value;
    update();
}

bool HMaterialSnackbar::useThemeColors() const
{
    Q_D(const HMaterialSnackbar);

    return d->useThemeColors;
}

void HMaterialSnackbar::setBackgroundColor(const QColor &color)
{
    Q_D(HMaterialSnackbar);

    d->backgroundColor = color;

    MATERIAL_DISABLE_THEME_COLORS
    update();
}

QColor HMaterialSnackbar::backgroundColor() const
{
    Q_D(const HMaterialSnackbar);

    if (d->useThemeColors || !d->backgroundColor.isValid()) {
        return HMaterialStyle::instance().themeColor("text");
    } else {
        return d->backgroundColor;
    }
}

void HMaterialSnackbar::setBackgroundOpacity(qreal opacity)
{
    Q_D(HMaterialSnackbar);

    d->bgOpacity = opacity;
    update();
}

qreal HMaterialSnackbar::backgroundOpacity() const
{
    Q_D(const HMaterialSnackbar);

    return d->bgOpacity;
}

void HMaterialSnackbar::setTextColor(const QColor &color)
{
    Q_D(HMaterialSnackbar);

    d->textColor = color;

    MATERIAL_DISABLE_THEME_COLORS
    update();
}

QColor HMaterialSnackbar::textColor() const 
{
    Q_D(const HMaterialSnackbar);

    if (d->useThemeColors || !d->textColor.isValid()) {
        return HMaterialStyle::instance().themeColor("canvas");
    } else {
        return d->textColor;
    }
}

void HMaterialSnackbar::setFontSize(qreal size)
{
    QFont f(font());
    f.setPointSizeF(size);
    setFont(f);

    update();
}

qreal HMaterialSnackbar::fontSize() const
{
    return font().pointSizeF();
}

void HMaterialSnackbar::setBoxWidth(int width)
{
    Q_D(HMaterialSnackbar);

    d->boxWidth = width;
    update();
}

int HMaterialSnackbar::boxWidth() const
{
    Q_D(const HMaterialSnackbar);

    return d->boxWidth;
}

void HMaterialSnackbar::setClickToDismissMode(bool value)
{
    Q_D(HMaterialSnackbar);
    
    d->clickDismiss = value;
}

bool HMaterialSnackbar::clickToDismissMode() const
{
    Q_D(const HMaterialSnackbar);

    return d->clickDismiss;
}

void HMaterialSnackbar::addMessage(const QString &message)
{
    Q_D(HMaterialSnackbar);

    d->messages.push_back(message);
    d->stateMachine->postEvent(new HMaterialStateTransitionEvent(SnackbarShowTransition));
    raise();
}

void HMaterialSnackbar::addInstantMessage(const QString &message)
{
    Q_D(HMaterialSnackbar);

    if (d->messages.isEmpty()) {
        d->messages.push_back(message);
    } else {
        d->messages.insert(1, message);
    }

    d->stateMachine->progress();
}

void HMaterialSnackbar::dequeue()
{
    Q_D(HMaterialSnackbar);

    if (d->messages.isEmpty())
        return;

    d->messages.removeFirst();

    if (!d->messages.isEmpty()) {
        d->stateMachine->postEvent(new HMaterialStateTransitionEvent(SnackbarNextTransition));
    } else {
        d->stateMachine->postEvent(new HMaterialStateTransitionEvent(SnackbarWaitTransition));
    }
}

void HMaterialSnackbar::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    Q_D(HMaterialSnackbar);

    if (d->messages.isEmpty())
        return;

    QString message = d->messages.first();

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(backgroundColor());
    
    painter.setBrush(brush);
    painter.setOpacity(d->bgOpacity);

    QRect r(0, 0, d->boxWidth, 40);

    painter.setPen(Qt::white);
    QRect br = painter.boundingRect(r, Qt::AlignHCenter | Qt::AlignTop | Qt::TextWordWrap, message);

    painter.setPen(Qt::NoPen);
    r = br.united(r).adjusted(-10, -10, 10, 20);


    const qreal s = 1 - d->stateMachine->offset();

    painter.translate(  (width() - (r.width() - 20)) / 2,
                        height() + 10 - s * (r.height()));

    br.moveCenter(r.center());
    painter.drawRoundedRect(r.adjusted(0, 0, 0, 3), 3, 3);
    painter.setPen(textColor());
    painter.drawText(br, Qt::AlignHCenter | Qt::AlignTop | Qt::TextWordWrap, message);
}
