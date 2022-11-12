#include "hmaterialfab.h"
#include "hmaterialfab_p.h"
#include <QGraphicsDropShadowEffect>
#include <QState>
#include <QEvent>
#include <QPainter>
#include "hmaterialrippleoverlay.h"

/*!
 *  \class HMaterialFloatingActionButtonPrivate
 *  \internal
 */

/*!
 *  \internal
 */
HMaterialFloatingActionButtonPrivate::HMaterialFloatingActionButtonPrivate(HMaterialFloatingActionButton *q)
    : HMaterialRaisedButtonPrivate(q)
{
}

/*!
 *  \internal
 */
HMaterialFloatingActionButtonPrivate::~HMaterialFloatingActionButtonPrivate()
{
}

/*!
 *  \internal
 */
void HMaterialFloatingActionButtonPrivate::init()
{
    Q_Q(HMaterialFloatingActionButton);

    corner = Qt::BottomRightCorner;
    mini   = false;
    offsX  = 34;
    offsY  = 36;

    q->setRole(HMaterial::Primary);
    q->setFixedSize(DefaultDiameter, DefaultDiameter);
    q->setGeometry(fabGeometry());

    setupProperties();

    if (q->parentWidget()) {
        q->parentWidget()->installEventFilter(q);
    }

    q->setFixedRippleRadius(50);
}

/*!
 *  \internal
 */
QRect HMaterialFloatingActionButtonPrivate::fabGeometry() const
{
    Q_Q(const HMaterialFloatingActionButton);

    QWidget *parent = q->parentWidget();
    if (!parent) {
        return QRect();
    }

    const int s = mini ? MiniDiameter : DefaultDiameter;

    switch (corner)
    {
    case Qt::TopLeftCorner:
        return QRect(offsX, offsY, s, s);
    case Qt::TopRightCorner:
        return QRect(parent->width()-(offsX+s), offsY, s, s);
    case Qt::BottomLeftCorner:
        return QRect(offsX, parent->height()-(offsY+s), s, s);
    case Qt::BottomRightCorner:
    default:
        break;
    }
    return QRect(parent->width()-(offsX+s), parent->height()-(offsY+s), s, s);
}

/*!
 *  \internal
 */
void HMaterialFloatingActionButtonPrivate::setupProperties()
{
    if (mini) {
        effect->setColor(QColor(0, 0, 0, 80));
        normalState->assignProperty(effect, "offset", QPointF(0, 3));
        normalState->assignProperty(effect, "blurRadius", 13);
        pressedState->assignProperty(effect, "offset", QPointF(0, 7));
        pressedState->assignProperty(effect, "blurRadius", 20);
    } else {
        effect->setColor(QColor(0, 0, 0, 105));
        normalState->assignProperty(effect, "offset", QPointF(0, 6));
        normalState->assignProperty(effect, "blurRadius", 16);
        pressedState->assignProperty(effect, "offset", QPointF(0, 11));
        pressedState->assignProperty(effect, "blurRadius", 28);
    }
}

/*!
 *  \class HMaterialFloatingActionButton
 */

HMaterialFloatingActionButton::HMaterialFloatingActionButton(const QIcon &icon, QWidget *parent)
    : HMaterialRaisedButton(*new HMaterialFloatingActionButtonPrivate(this), parent)
{
    d_func()->init();

    setIcon(icon);
}

HMaterialFloatingActionButton::~HMaterialFloatingActionButton()
{
}

/*!
 *  \reimp
 */
QSize HMaterialFloatingActionButton::sizeHint() const
{
    Q_D(const HMaterialFloatingActionButton);

    if (d->mini) {
        return QSize(HMaterialFloatingActionButtonPrivate::MiniDiameter,
                     HMaterialFloatingActionButtonPrivate::MiniDiameter);
    } else {
        return QSize(HMaterialFloatingActionButtonPrivate::DefaultDiameter,
                     HMaterialFloatingActionButtonPrivate::DefaultDiameter);
    }
}

void HMaterialFloatingActionButton::setMini(bool state)
{
    Q_D(HMaterialFloatingActionButton);

    if (d->mini == state) {
        return;
    }

    d->mini = state;

    setFixedSize(d->diameter(), d->diameter());
    setFixedRippleRadius(state ? 30 : 50);

    d->setupProperties();
    updateClipPath();
    setGeometry(d->fabGeometry());
    update();
}

bool HMaterialFloatingActionButton::isMini() const
{
    Q_D(const HMaterialFloatingActionButton);

    return d->mini;
}

void HMaterialFloatingActionButton::setCorner(Qt::Corner corner)
{
    Q_D(HMaterialFloatingActionButton);

    if (d->corner == corner) {
        return;
    }

    d->corner = corner;
    setGeometry(d->fabGeometry());
    update();
}

Qt::Corner HMaterialFloatingActionButton::corner() const
{
    Q_D(const HMaterialFloatingActionButton);

    return d->corner;
}

void HMaterialFloatingActionButton::setOffset(int x, int y)
{
    Q_D(HMaterialFloatingActionButton);

    d->offsX = x;
    d->offsY = y;
    setGeometry(d->fabGeometry());
    update();
}

QSize HMaterialFloatingActionButton::offset() const
{
    Q_D(const HMaterialFloatingActionButton);

    return QSize(d->offsX, d->offsY);
}

void HMaterialFloatingActionButton::setXOffset(int x)
{
    Q_D(HMaterialFloatingActionButton);

    d->offsX = x;
    setGeometry(d->fabGeometry());
    update();
}

int HMaterialFloatingActionButton::xOffset() const
{
    Q_D(const HMaterialFloatingActionButton);

    return d->offsX;
}

void HMaterialFloatingActionButton::setYOffset(int y)
{
    Q_D(HMaterialFloatingActionButton);

    d->offsY = y;
    setGeometry(d->fabGeometry());
    update();
}

int HMaterialFloatingActionButton::yOffset() const
{
    Q_D(const HMaterialFloatingActionButton);

    return d->offsY;
}

/*!
 *  \reimp
 */
bool HMaterialFloatingActionButton::event(QEvent *event)
{
    Q_D(HMaterialFloatingActionButton);

    if (!parent()) {
        return HMaterialRaisedButton::event(event);
    }
    switch (event->type())
    {
    case QEvent::ParentChange:
    {
        parent()->installEventFilter(this);
        setGeometry(d->fabGeometry());
        break;
    }
    case QEvent::ParentAboutToChange:
    {
        parent()->removeEventFilter(this);
        break;
    }
    default:
        break;
    }
    return HMaterialRaisedButton::event(event);
}

/*!
 *  \reimp
 */
bool HMaterialFloatingActionButton::eventFilter(QObject *obj, QEvent *event)
{
    const QEvent::Type type = event->type();

    if (QEvent::Move == type || QEvent::Resize == type)
    {
        Q_D(HMaterialFloatingActionButton);
        setGeometry(d->fabGeometry());
    }

    return HMaterialRaisedButton::eventFilter(obj, event);
}

/*!
 *  \reimp
 */
void HMaterialFloatingActionButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    Q_D(HMaterialFloatingActionButton);

    QRect square = QRect(0, 0, d->diameter(), d->diameter());
    square.moveCenter(rect().center());

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);

    if (isEnabled()) {
        brush.setColor(backgroundColor());
    } else {
        brush.setColor(disabledBackgroundColor());
    }

    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(square);

    QRect iconGeometry(0, 0, d->iconSize(), d->iconSize());
    iconGeometry.moveCenter(square.center());

    QPixmap pixmap = icon().pixmap(QSize(d->iconSize(), d->iconSize()));
    QPainter icon(&pixmap);
    icon.setCompositionMode(QPainter::CompositionMode_SourceIn);
    icon.fillRect(pixmap.rect(), isEnabled() ? foregroundColor()
                                             : disabledForegroundColor());
    painter.drawPixmap(iconGeometry, pixmap);
}

void HMaterialFloatingActionButton::updateClipPath()
{
    Q_D(HMaterialFloatingActionButton);

    QPainterPath path;
    path.addEllipse(0, 0, d->diameter(), d->diameter());
    d->rippleOverlay->setClipPath(path);
}
