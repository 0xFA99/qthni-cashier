#ifndef HMATERIALPANEL_PRIVATE_H
#define HMATERIALPANEL_PRIVATE_H

#include "hmaterialbutton.h"

class HMaterialPanel;

class HMaterialPanelPrivate
{
    Q_DISABLE_COPY(HMaterialPanelPrivate)
    Q_DECLARE_PUBLIC(HMaterialPanel)

public:
    HMaterialPanelPrivate(HMaterialPanel *parent);
    ~HMaterialPanelPrivate();

    void init();

    HMaterialPanel *const   q_ptr;
    HMaterialButton         *m_analysicButton;
    HMaterialButton         *m_purchaseButton;
    HMaterialButton         *m_productsButton;
    HMaterialButton         *m_membersButton;
    HMaterialButton         *m_optionsButton;
};

#endif
