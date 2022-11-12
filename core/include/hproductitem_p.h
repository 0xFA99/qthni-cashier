#ifndef HNILIB_HPRODUCTITEM_P_H
#define HNILIB_HPRODUCTITEM_P_H

#include "hproduct.h"

#include "hmaterialavatar.h"
#include "hmateriallabel.h"
#include "hmaterialflatbutton.h"
#include "hmaterialcurrency.h"
#include "hmaterialbadge.h"

class QGridLayout;

class HProductItem;
class HProductItemPrivate
{
    Q_DISABLE_COPY(HProductItemPrivate)
    Q_DECLARE_PUBLIC(HProductItem);

public:
    explicit HProductItemPrivate(HProductItem *q);
    ~HProductItemPrivate();

    void init();

    HProductItem *const     q_ptr;
    QGridLayout             *m_layout;

    HMaterialAvatar         *m_image;
    HMaterialLabel          *m_name;
    HMaterialCurrency       *m_price;
    HMaterialBadge          *m_stock;

    HMaterialFlatButton     *m_editButton;
    HMaterialFlatButton     *m_removeButton;

    HProduct                *m_product;
};

#endif
