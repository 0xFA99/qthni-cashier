#include "hmaterialdialog.h"
#include "hmaterialdialog_p.h"

#include <QStackedLayout>
#include <QGraphicsDropShadowEffect>
#include <QStateMachine>
#include <QState>
#include <QApplication>
#include <QPropertyAnimation>
#include <QPainter>

#include "hmaterialdialog_internal.h"
#include "hmaterialstatetransition.h"

HMaterialDialogPrivate::HMaterialDialogPrivate(HMaterialDialog *q)
    : q_ptr(q)
{
}

HMaterialDialogPrivate::~HMaterialDialogPrivate()
{
}

void HMaterialDialogPrivate::init()
{
    Q_Q(HMaterialDialog);

    dialogWindow    = new HMaterialDialogWindow(q);
    proxyStack      = new QStackedLayout;
    stateMachine    = new QStateMachine(q);
    proxy           = new HMaterialDialogProxy(dialogWindow, proxyStack, q);

    QVBoxLayout *layout = new QVBoxLayout;
    q->setLayout(layout);

    QWidget *widget = new QWidget;
    widget->setLayout(proxyStack);
    widget->setMinimumWidth(400);

    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;
    effect->setColor(QColor(0, 0, 0, 200));
    effect->setBlurRadius(64);
    effect->setOffset(0, 13);
    widget->setGraphicsEffect(effect);

    layout->addWidget(widget);
    layout->setAlignment(widget, Qt::AlignCenter);

    proxyStack->addWidget(dialogWindow);
    proxyStack->addWidget(proxy);
    proxyStack->setCurrentIndex(1);

    q->setAttribute(Qt::WA_TransparentForMouseEvents);

    QState *hiddenState = new QState;
    QState *visibleState = new QState;

    stateMachine->addState(hiddenState);
    stateMachine->addState(visibleState);
    stateMachine->setInitialState(hiddenState);

    HMaterialStateTransition *transition;

    transition = new HMaterialStateTransition(DialogShowTransition);
    transition->setTargetState(visibleState);
    hiddenState->addTransition(transition);

    transition = new HMaterialStateTransition(DialogHideTransition);
    transition->setTargetState(hiddenState);
    visibleState->addTransition(transition);

    visibleState->assignProperty(proxy, "opacity", 1);
    visibleState->assignProperty(effect, "color", QColor(0, 0, 0, 200));
    visibleState->assignProperty(dialogWindow, "offset", 0);

    hiddenState->assignProperty(proxy, "opacity", 0);
    hiddenState->assignProperty(effect, "color", QColor(0, 0, 0, 0));
    hiddenState->assignProperty(dialogWindow, "offset", 200);

    QPropertyAnimation *animation;

    animation = new QPropertyAnimation(proxy, "opacity", q);
    animation->setDuration(280);
    stateMachine->addDefaultAnimation(animation);

    animation = new QPropertyAnimation(effect, "color", q);
    animation->setDuration(280);
    stateMachine->addDefaultAnimation(animation);

    animation = new QPropertyAnimation(dialogWindow, "offset", q);
    animation->setDuration(280);
    animation->setEasingCurve(QEasingCurve::OutCirc);
    stateMachine->addDefaultAnimation(animation);

    QObject::connect(visibleState, SIGNAL(propertiesAssigned()),
            proxy, SLOT(makeOpaque()));
    QObject::connect(hiddenState, SIGNAL(propertiesAssigned()),
            proxy, SLOT(makeTransparent()));

    stateMachine->start();
    QCoreApplication::processEvents();
}

HMaterialDialog::HMaterialDialog(QWidget *parent)
    : HMaterialOverlayWidget(parent)
    , d_ptr(new HMaterialDialogPrivate(this))
{
    d_func()->init();
}

HMaterialDialog::~HMaterialDialog()
{
}

QLayout *HMaterialDialog::windowLayout() const
{
    Q_D(const HMaterialDialog);

    return d->dialogWindow->layout();
}

void HMaterialDialog::setWindowLayout(QLayout *layout)
{
    Q_D(HMaterialDialog);

    d->dialogWindow->setLayout(layout);
}

void HMaterialDialog::showDialog()
{
    Q_D(HMaterialDialog);

    d->stateMachine->postEvent(new HMaterialStateTransitionEvent(DialogShowTransition));
    raise();
}

void HMaterialDialog::hideDialog()
{
    Q_D(HMaterialDialog);

    d->stateMachine->postEvent(new HMaterialStateTransitionEvent(DialogHideTransition));
    setAttribute(Qt::WA_TransparentForMouseEvents);
    d->proxyStack->setCurrentIndex(1);
}

void HMaterialDialog::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    Q_D(HMaterialDialog);

    QPainter painter(this);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);
    painter.setOpacity(d->proxy->opacity() / 2.4);
    painter.drawRect(rect());
}
