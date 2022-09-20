#ifndef HPURCHASEPAGE_H
#define HPURCHASEPAGE_H

#include "hmaterialframe.h"

class HPurchasePage : public HMaterialFrame
{
    Q_OBJECT

public:
    explicit HPurchasePage(QWidget *parent = nullptr);
    ~HPurchasePage();
};

#endif
