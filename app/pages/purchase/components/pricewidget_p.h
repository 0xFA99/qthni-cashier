#ifndef QTHNI_PRICEWIDGET_P_H
#define QTHNI_PRICEWIDGET_P_H

#include "qtmaterial/components/qtmaterialtextfield.h"
#include "qtmaterial/components/qtmaterialflatbutton.h"

class QVBoxLayout;
class PriceWidget;
class PriceWidgetPrivate
{
    Q_DISABLE_COPY(PriceWidgetPrivate)
    Q_DECLARE_PUBLIC(PriceWidget)

public:
    explicit PriceWidgetPrivate(PriceWidget *q);
    ~PriceWidgetPrivate();

    void init();

    PriceWidget *const      q_ptr;
    QVBoxLayout             *m_layout;

    QtMaterialTextField     *m_total;
    QtMaterialTextField     *m_subTotal;
    QtMaterialTextField     *m_discount;

    QtMaterialFlatButton    *m_button;
};

#endif //QTHNI_PRICEWIDGET_P_H
