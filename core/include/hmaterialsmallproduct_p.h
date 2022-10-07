#ifndef HMATERIALSMALLPRODUCT_PRIVATE_H
#define HMATERIALSMALLPRODUCT_PRIVATE_H

#include "hmateriallabel.h"
#include "hmaterialimage.h"

class QLabel;
class QGridLayout;

class HMaterialSmallProduct;

class HMaterialSmallProductPrivate
{
    Q_DISABLE_COPY(HMaterialSmallProductPrivate)
    Q_DECLARE_PUBLIC(HMaterialSmallProduct)

public:
    HMaterialSmallProductPrivate(HMaterialSmallProduct *q);
    ~HMaterialSmallProductPrivate();

    void init();

    HMaterialSmallProduct *const    q_ptr;
    QGridLayout                     *m_layout;
    HMaterialImage                  *m_image;
    HMaterialLabel                  *m_title;
    HMaterialLabel                  *m_price;
    HMaterialLabel                  *m_amount;
};

#endif
