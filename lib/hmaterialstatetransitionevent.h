#ifndef HMATERIALSTATETRANSITIONEVENT_H
#define HMATERIALSTATETRANSITIONEVENT_H

#include <QEvent>

enum HMaterialStateTransitionType {
    SnackbarShowTransition = 1,
    SnackbarHideTransition,
    SnackbarWaitTransition,
    SnackbarNextTransition,

    FlatButtonPressedTransition,
    FlatButtonCheckedTransition,
    FlatButtonUncheckedTransition,

    CollapsibleMenuExpand,
    CollapsibleMenuCollapse,
    
    SliderChangedToMinimum,
    SliderChangedFromMinimum,
    SliderNoFocusMouseEnter,
    SliderNoFocusMouseLeave,
    
    DialogShowTransition,
    DialogHideTransition,
    
    MaxTransitionType = 65535
};

struct HMaterialStateTransitionEvent : public QEvent
{
    HMaterialStateTransitionEvent(HMaterialStateTransitionType type)
        : QEvent(QEvent::Type(QEvent::User + 1)),
          type(type)
    {
    }

    HMaterialStateTransitionType type;
};

#endif
