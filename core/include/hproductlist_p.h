#ifndef HNILIB_HPRODUCTLIST_P_H
#define HNILIB_HPRODUCTLIST_P_H

#include "hproductview.h"
#include "hproductedit.h"
#include "hmaterialfab.h"
#include "hmateriallabel.h"
#include "hmaterialdialog.h"
#include "hmaterialflatbutton.h"

#include <QScrollArea>
#include <QVector>

class QVBoxLayout;
class QGridLayout;

class HProduct;
class HProductList;
class HProductListPrivate
{
    Q_DISABLE_COPY(HProductListPrivate)
    Q_DECLARE_PUBLIC(HProductList)

public:
    explicit HProductListPrivate(HProductList *q);
    ~HProductListPrivate();

    void init();

    HProductList *const             q_ptr;
    QGridLayout                     *m_layout;

    HMaterialLabel                  *m_title;
    HMaterialFlatButton             *m_gridButton;
    HMaterialFlatButton             *m_vertButton;
    HMaterialFloatingActionButton   *m_fabButton;

    QScrollArea                     *m_scrollArea;
    HProductView                    *m_productView;
    QVector<HProduct *>             m_productList;

    HMaterialDialog                 *m_dialog;
    QVBoxLayout                     *m_dialogLayout;
    HProductEdit                    *m_productDialog;
};

#endif
