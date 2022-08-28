#ifndef HMATERIALSTATETRANSITION_H
#define HMATERIALSTATETRANSITION_H

#include <QAbstractTransition>

#include "hmaterialstatetransitionevent.h"

class HMaterialStateTransition : public QAbstractTransition
{
    Q_OBJECT

public:
    HMaterialStateTransition(HMaterialStateTransitionType type);

protected:
    virtual bool eventTest(QEvent *event);
    virtual void onTransition(QEvent *);

private:
    HMaterialStateTransitionType m_type;
};

#endif
