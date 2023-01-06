#ifndef QTHNI_PURCHASE_ORDER_DIALOG_P_H
#define QTHNI_PURCHASE_ORDER_DIALOG_P_H

#include "qtmaterial/components/qtmaterialavatar.h"
#include "qtmaterial/components/qtmaterialflatbutton.h"

#include <QScrollArea>
#include <QLabel>
#include <QLocale>

class QGridLayout;
class QVBoxLayout;

class PurchaseOrderDialog;
class PurchaseOrderDialogPrivate
{
    Q_DISABLE_COPY(PurchaseOrderDialogPrivate)
    Q_DECLARE_PUBLIC(PurchaseOrderDialog)

public:
    explicit PurchaseOrderDialogPrivate(PurchaseOrderDialog *q);
    ~PurchaseOrderDialogPrivate();

    void init();

    PurchaseOrderDialog *const  q_ptr;
    QGridLayout                 *m_layout;

    QLabel                      *m_memberNameTitle;
    QScrollArea                 *m_scrollArea;
    QWidget                     *m_orderWidget;
    QVBoxLayout                 *m_orderWidgetLayout;

    QtMaterialFlatButton        *m_closeButton;
    QtMaterialFlatButton        *m_submitButton;

    QLabel                         *m_subTotal;
    QLabel                         *m_discount;
    QLabel                         *m_total;

    QLocale                         m_locale;
};

#endif //QTHNI_PURCHASE_ORDER_DIALOG_P_H
