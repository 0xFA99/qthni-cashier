#ifndef HPRODUCTDETAIL_PRIVATE_H
#define HPRODUCTDETAIL_PRIVATE_H

#include "hmaterialimage.h"
#include "hmaterialtextfield.h"
#include "hmaterialflatbutton.h"

class QGridLayout;

class HProductDetail;
class HProductDetailPrivate
{
    Q_DISABLE_COPY(HProductDetailPrivate)
    Q_DECLARE_PUBLIC(HProductDetail)

public:
    HProductDetailPrivate(HProductDetail *q);
    ~HProductDetailPrivate();

    void init();

    HProductDetail *const   q_ptr;

    QGridLayout             *m_layout;
    HMaterialImage          *m_image;
    HMaterialTextField      *m_name;
    HMaterialTextField      *m_category;
    HMaterialTextField      *m_stock;
    HMaterialTextField      *m_normalPrice;
    HMaterialTextField      *m_memberPrice;

    HMaterialFlatButton     *m_cancelButton;
    HMaterialFlatButton     *m_submitButton;
};

#endif
