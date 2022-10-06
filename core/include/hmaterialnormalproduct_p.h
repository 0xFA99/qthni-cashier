#ifndef HMATERIALNORMALPRODUCT_PRIVATE_H
#define HMATERIALNORMALPRODUCT_PRIVATE_H

#include "hmaterialimage.h"
#include "hmateriallabel.h"
#include "hmaterialflatbutton.h"

class QGridLayout;

class HMaterialNormalProduct;
class HMaterialNormalProductPrivate
{
    Q_DISABLE_COPY(HMaterialNormalProductPrivate)
    Q_DECLARE_PUBLIC(HMaterialNormalProduct)

public:
    HMaterialNormalProductPrivate(HMaterialNormalProduct *q);
    ~HMaterialNormalProductPrivate();

    void init();

    HMaterialNormalProduct *const   q_ptr;
    QGridLayout                     *m_layout;
    HMaterialImage                  *m_image;
    HMaterialLabel                  *m_title;
    HMaterialLabel                  *m_price;
    HMaterialLabel                  *m_amount;
    HMaterialFlatButton             *m_button;
};

#endif
