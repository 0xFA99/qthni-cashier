#include <QStateMachine>
#include <QGraphicsDropShadowEffect>
#include <QPropertyAnimation>
#include <QEventTransition>

#include "hmaterialraisedbutton.h"
#include "hmaterialraisedbutton_p.h"

HMaterialRaisedButtonPrivate::HMaterialRaisedButtonPrivate(HMaterialRaisedButton *q)
    : HMaterialFlatButtonPrivate(q)
{
}

HMaterialRaisedButtonPrivate::~HMaterialRaisedButtonPrivate()
{
}

void HMaterialRaisedButtonPrivate::init()
{
    Q_Q(HMaterialRaisedButton);

    shadowStateMachine  = new QStateMachine(q);
    normalState         = new QState;
    pressedState        = new QState;
    effect              = new QGraphicsDropShadowEffect;

    effect->setBlurRadius(7);
    effect->setOffset(QPointF(0, 2));
    effect->setColor(QColor(0, 0, 0, 75));

    q->setBackgroundMode(Qt::OpaqueMode);
    q->setMinimumHeight(2);
    q->setGraphicsEffect(effect);
    q->setBaseOpacity(0.3);

    shadowStateMachine->addState(normalState);
    shadowStateMachine->addState(pressedState);

    normalState->assignProperty(effect, "offset", QPoint(0, 2));
    normalState->assignProperty(effect, "blurRadius", 7);

    pressedState->assignProperty(effect, "offset", QPoint(0, 5));
    pressedState->assignProperty(effect, "blurRadius", 29);

    QAbstractTransition *transition;

    transition = new QEventTransition(q, QEvent::MouseButtonPress);
    transition->setTargetState(pressedState);
    normalState->addTransition(transition);

    transition = new QEventTransition(q, QEvent::MouseButtonDblClick);
    transition->setTargetState(pressedState);
    normalState->addTransition(transition);

    transition = new QEventTransition(q, QEvent::MouseButtonRelease);
    transition->setTargetState(normalState);
    pressedState->addTransition(transition);

    QPropertyAnimation *animation;

    animation = new QPropertyAnimation(effect, "offset", q);
    animation->setDuration(100);
    shadowStateMachine->addDefaultAnimation(animation);

    animation = new QPropertyAnimation(effect, "blurRadius", q);
    animation->setDuration(100);
    shadowStateMachine->addDefaultAnimation(animation);

    shadowStateMachine->setInitialState(normalState);
    shadowStateMachine->start();
}

HMaterialRaisedButton::HMaterialRaisedButton(QWidget *parent)
    : HMaterialFlatButton(*new HMaterialRaisedButtonPrivate(this), parent)
{
    d_func()->init();
}

HMaterialRaisedButton::HMaterialRaisedButton(const QString &text, QWidget *parent)
    : HMaterialFlatButton(*new HMaterialRaisedButtonPrivate(this), parent)
{
    d_func()->init();

    setText(text);
}

HMaterialRaisedButton::~HMaterialRaisedButton()
{
}

HMaterialRaisedButton::HMaterialRaisedButton(HMaterialRaisedButtonPrivate &d, QWidget *parent)
    : HMaterialFlatButton(d, parent)
{
    d_func()->init();
}

bool HMaterialRaisedButton::event(QEvent *event)
{
    Q_D(HMaterialRaisedButton);

    if (QEvent::EnabledChange == event->type()) {
        if (isEnabled()) {
            d->shadowStateMachine->start();
            d->effect->setEnabled(true);
        } else {
            d->shadowStateMachine->stop();
            d->effect->setEnabled(false);
        }
    }

    return HMaterialFlatButton::event(event);
}
