#ifndef HPRODUCTNORMALVIEW_PRIVATE_H
#define HPRODUCTNORMALVIEW_PRIVATE_H

#include "hmaterialimage.h"
#include "hmateriallabel.h"
#include "hmaterialflatbutton.h"

class QVBoxLayout;

class HProductNormalView;
class HProductNormalViewPrivate
{
    Q_DISABLE_COPY(HProductNormalViewPrivate)
    Q_DECLARE_PUBLIC(HProductNormalView)

public:
    HProductNormalViewPrivate(HProductNormalView *q);
    ~HProductNormalViewPrivate();

    void init();

    HProductNormalView *const   q_ptr;

    QVBoxLayout                 *m_layout;
    HMaterialImage              *m_image;
    HMaterialLabel              *m_title;
    HMaterialLabel              *m_price;
    HMaterialFlatButton         *m_button;
};

#endif
