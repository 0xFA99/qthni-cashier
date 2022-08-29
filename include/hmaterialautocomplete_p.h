#ifndef HMATERIALAUTOCOMPLETE_P_H
#define HMATERIALAUTOCOMPLETE_P_H

#include "hmaterialtextfield_p.h"

class QWidget;
class QVBoxLayout;

class HMaterialAutoCompleteOverlay;
class HMaterialAutoCompleteStateMachine;

class HMaterialAutoCompletePrivate : public HMaterialTextFieldPrivate
{
    Q_DISABLE_COPY(HMaterialAutoCompletePrivate)
    Q_DECLARE_PUBLIC(HMaterialAutoComplete)

public:
    HMaterialAutoCompletePrivate(HMaterialAutoComplete *q);
    virtual ~HMaterialAutoCompletePrivate();

    void init();

    QWidget                             *menu;
    QWidget                             *frame;
    HMaterialAutoCompleteStateMachine   *stateMachine;
    QVBoxLayout                         *menuLayout;
    QStringList                         dataSource;
    int                                 maxWidth;
};

#endif
