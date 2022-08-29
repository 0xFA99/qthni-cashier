#ifndef HMATERIALAUTOCOMPLETESTATEMACHINE_H
#define HMATERIALAUTOCOMPLETESTATEMACHINE_H

#include <QStateMachine>

#include "hmaterialautocomplete.h"

class HMaterialAutoCompleteStateMachine : public QStateMachine
{
    Q_OBJECT

public:
    explicit HMaterialAutoCompleteStateMachine(QWidget *menu);
    ~HMaterialAutoCompleteStateMachine();

signals:
    void shouldOpen();
    void shouldClose();
    void shouldFade();

private:
    Q_DISABLE_COPY(HMaterialAutoCompleteStateMachine);

    QWidget *const m_menu;
    QState  *const m_closedState;
    QState  *const m_openState;
    QState  *const m_closingState;
};

#endif
