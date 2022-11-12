#ifndef HPRODUCTEDIT_PRIVATE_H
#define HPRODUCTEDIT_PRIVATE_H

#include "hmaterialavatar.h"
#include "hmaterialtextfield.h"
#include "hmaterialflatbutton.h"

class QGridLayout;

class HProduct;
class HProductEdit;
class HProductEditPrivate
{
    Q_DISABLE_COPY(HProductEditPrivate);
    Q_DECLARE_PUBLIC(HProductEdit);

public:
    HProductEditPrivate(HProductEdit *q);
    ~HProductEditPrivate();

    void init();

    HProductEdit *const q_ptr;

    QGridLayout         *m_layout;

    HMaterialAvatar     *m_image;
    HMaterialTextField  *m_name;
    HMaterialTextField  *m_price;
    HMaterialTextField  *m_stock;
    HMaterialFlatButton *m_imageButton;
    HMaterialFlatButton *m_cancelButton;
    HMaterialFlatButton *m_submitButton;

    HProductEdit::Mode  m_mode;
    HProduct            *m_product;
};

#endif
