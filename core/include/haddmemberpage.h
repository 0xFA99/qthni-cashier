#ifndef HADDMEMBERPAGE_H
#define HADDMEMBERPAGE_H

#include "hmaterialframe.h"

class HAddMemberPage : public HMaterialFrame
{
    Q_OBJECT

public:
    explicit HAddMemberPage(QWidget *parent = nullptr);
    ~HAddMemberPage();
};

#endif
