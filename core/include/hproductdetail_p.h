#ifndef HPRODUCTDETAIL_PRIVATE_H
#define HPRODUCTDETAIL_PRIVATE_H

#include "hmaterialimage.h"
#include "hmaterialtextfield.h"
#include "hmaterialflatbutton.h"

class QVBoxLayout;

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
    QVBoxLayout             *m_layout;
    HMaterialImage          *m_image;
    HMaterialTextField      *m_title;
    HMaterialTextField      *m_customerPrice;
    HMaterialTextField      *m_memberPrice;
    HMaterialFlatButton     *m_closeButton;
};

#endif
