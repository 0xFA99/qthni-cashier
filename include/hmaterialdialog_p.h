#ifndef HMATERIALDIALOG_PRIVATE_H
#define HMATERIALDIALOG_PRIVATE_H

#include <QtGlobal>

class QStateMachine;
class HMaterialDialog;
class QStackedLayout;
class HMaterialDialogWindow;
class HMaterialDialogProxy;

class HMaterialDialogPrivate
{
    Q_DISABLE_COPY(HMaterialDialogPrivate)
    Q_DECLARE_PUBLIC(HMaterialDialog)

public:
    HMaterialDialogPrivate(HMaterialDialog *q);
    ~HMaterialDialogPrivate();

    void init();

    HMaterialDialog *const  q_ptr;
    HMaterialDialogWindow   *dialogWindow;
    QStackedLayout          *proxyStack;
    QStateMachine           *stateMachine;
    HMaterialDialogProxy    *proxy;
};

#endif
