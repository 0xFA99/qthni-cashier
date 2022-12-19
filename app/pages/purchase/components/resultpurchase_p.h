#ifndef QTHNI_RESULTPURCHASE_P_H
#define QTHNI_RESULTPURCHASE_P_H

#include "qtmaterial/components/qtmaterialflatbutton.h"

class QGridLayout;

class ResultPurchase;
class ResultPurchasePrivate
{
    Q_DISABLE_COPY(ResultPurchasePrivate)
    Q_DECLARE_PUBLIC(ResultPurchase)

public:
    explicit ResultPurchasePrivate(ResultPurchase *q);
    ~ResultPurchasePrivate();

    void init();

    ResultPurchase *const       q_ptr;
    QGridLayout                 *m_layout;

    QtMaterialFlatButton        *m_closeButton;
    QtMaterialFlatButton        *m_submitButton;
};

#endif //QTHNI_RESULTPURCHASE_P_H
