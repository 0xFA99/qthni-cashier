#ifndef HMATERIAL_P_H
#define HMATERIAL_P_H

#include <QtGlobal>

class HMaterialStyle;
class HMaterialTheme;

class HMaterialStylePrivate
{
    Q_DISABLE_COPY(HMaterialStylePrivate)
    Q_DECLARE_PUBLIC(HMaterialStyle)

public:
    HMaterialStylePrivate(HMaterialStyle *q);
    ~HMaterialStylePrivate();

    void init();

    HMaterialStyle *const q_ptr;
    HMaterialTheme *theme;
};

#endif
