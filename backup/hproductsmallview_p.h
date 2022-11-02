#ifndef HPRODUCTSMALLVIEW_PRIVATE_H
#define HPRODUCTSMALLVIEW_PRIVATE_H

#include "hmaterialimage.h"
#include "hmateriallabel.h"

class QGridLayout;
class HProductSmallView;
class HProductSmallViewPrivate
{
    Q_DISABLE_COPY(HProductSmallViewPrivate)
    Q_DECLARE_PUBLIC(HProductSmallView)

public:
    HProductSmallViewPrivate(HProductSmallView *q);
    ~HProductSmallViewPrivate();

    void init();

    HProductSmallView *const    q_ptr;
    QGridLayout                 *m_layout;
    HMaterialImage              *m_image;
    HMaterialLabel              *m_title;
    HMaterialLabel              *m_price;
};

#endif
