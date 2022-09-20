#ifndef HANALYSICPAGE_H
#define HANALYSICPAGE_H

#include "hmaterialframe.h"

class HAnalysicPage : public HMaterialFrame
{
    Q_OBJECT

public:
    explicit HAnalysicPage(QWidget *parent = nullptr);
    ~HAnalysicPage();
};

#endif
