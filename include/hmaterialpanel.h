#ifndef HMATERIALPANEL_H
#define HMATERIALPANEL_H

#include "hmaterialpanel_p.h"

class HMaterialPanelPrivate;

class HMaterialPanel : public HMaterialFrame
{
    Q_OBJECT

public:
    explicit HMaterialPanel(QWidget *parent = nullptr);
    ~HMaterialPanel();

private:
    Q_DISABLE_COPY(HMaterialPanel);
    Q_DECLARE_PRIVATE(HMaterialPanel);
};

#endif
