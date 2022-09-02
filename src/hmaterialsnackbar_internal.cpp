#include <QPropertyAnimation>
#include <QDebug>

#include "hmaterialsnackbar.h"
#include "hmaterialsnackbar_internal.h"

#include "hmaterialstatetransition.h"

HMaterialSnackbarStateMachine::HMaterialSnackbarStateMachine(HMaterialSnackbar *parent)
    : QStateMachine(parent),
      m_snackbar(parent)
{
    m_timer.setSingleShot(true);

    QState *hiddenState     = new QState;
    QState *visibleState    = new QState;
    QState *finalState      = new QState;

    addState(hiddenState);
    addState(visibleState);
    addState(finalState);

    setInitialState(hiddenState);

    HMaterialStateTransition *transition;

    transition = new HMaterialStateTransition(SnackbarShowTransition);
    transition->setTargetState(visibleState);
    hiddenState->addTransition(transition);

    transition = new HMaterialStateTransition(SnackbarHideTransition);
    transition->setTargetState(visibleState);
    hiddenState->addTransition(transition);

    transition = new HMaterialStateTransition(SnackbarHideTransition);
    transition->setTargetState(finalState);
    visibleState->addTransition(transition);

    transition = new HMaterialStateTransition(SnackbarWaitTransition);
    transition->setTargetState(hiddenState);
    finalState->addTransition(transition);

    transition = new HMaterialStateTransition(SnackbarNextTransition);
    transition->setTargetState(visibleState);
    finalState->addTransition(transition);

    QObject::connect(   visibleState, SIGNAL(propertiesAssigned()),
                        this, SLOT(snackbarShown()));
    QObject::connect(   finalState, SIGNAL(propertiesAssigned()),
                        m_snackbar, SLOT(dequeue()));

    QPropertyAnimation *animation;

    animation = new QPropertyAnimation(this, "offset", this);
    animation->setEasingCurve(QEasingCurve::OutCubic);
    animation->setDuration(300);
    addDefaultAnimation(animation);

    hiddenState->assignProperty(    this, "offset", 1);
    visibleState->assignProperty(   this, "offset", 0);
    finalState->assignProperty(     this, "offset", 1);

    QObject::connect(&m_timer, SIGNAL(timeout()), this, SLOT(progress()));

    m_snackbar->installEventFilter(this);
}

HMaterialSnackbarStateMachine::~HMaterialSnackbarStateMachine()
{
}

bool HMaterialSnackbarStateMachine::eventFilter(QObject *watched, QEvent *event)
{
    if (QEvent::MouseButtonPress == event->type() && m_snackbar->clickToDismissMode())
        progress();

    return QStateMachine::eventFilter(watched, event);
}

void HMaterialSnackbarStateMachine::setOffset(qreal offset)
{
    m_offset = offset;
    m_snackbar->update();
}

void HMaterialSnackbarStateMachine::progress()
{
    m_timer.stop();
    postEvent(new HMaterialStateTransitionEvent(SnackbarHideTransition));
    if (m_snackbar->clickToDismissMode())
        m_snackbar->setAttribute(Qt::WA_TransparentForMouseEvents, true);
}

void HMaterialSnackbarStateMachine::snackbarShown()
{
    m_timer.start(m_snackbar->autoHideDuration());
    if (m_snackbar->clickToDismissMode())
        m_snackbar->setAttribute(Qt::WA_TransparentForMouseEvents, false);
}
