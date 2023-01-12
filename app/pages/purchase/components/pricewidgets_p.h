#ifndef QTHNI_PRICEWIDGETS_P_H
#define QTHNI_PRICEWIDGETS_P_H

#include "qtmaterial/components/qtmaterialtextfield.h"
#include "qtmaterial/components/qtmaterialflatbutton.h"

#include <QLocale>
#include <QUuid>

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

    QLocale                 m_locale;
    // QMap<int, int>      m_priceMapList;
    QMap<QUuid, int>        m_memPriceList;
    QMap<QUuid, int>        m_cusPriceList;
    QMap<QUuid, int>        m_disPriceList;
    bool                    m_hasMember;

    int                     m_subTotalInt;
    int                     m_memTotalInt;
    int                     m_disTotalInt;

};

#endif //QTHNI_PRICEWIDGETS_P_H
