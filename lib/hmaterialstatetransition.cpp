#include "hmaterialstatetransition.h"

HMaterialStateTransition::HMaterialStateTransition(HMaterialStateTransitionType type)
    : m_type(type)
{
}

bool HMaterialStateTransition::eventTest(QEvent *event)
{
    if (event->type() != QEvent::Type(QEvent::User + 1)) {
        return false;
    }
    HMaterialStateTransitionEvent *transition = static_cast<HMaterialStateTransitionEvent *>(event);
    return (m_type == transition->type);
}

void HMaterialStateTransition::onTransition(QEvent *)
{
}
