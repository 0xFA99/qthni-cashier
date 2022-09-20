#ifndef HOPTIONPAGE_H
#define HOPTIONPAGE_H

#include "hmaterialframe.h"

class HOptionPage : public HMaterialFrame
{
    Q_OBJECT

public:
    explicit HOptionPage(QWidget *parent = nullptr);
    ~HOptionPage();
};

#endif
