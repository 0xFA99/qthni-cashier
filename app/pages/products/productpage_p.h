#ifndef QTHNI_PRODUCTPAGE_P_H
#define QTHNI_PRODUCTPAGE_P_H

#include "widgets/frametitle.h"

#include "products/ProductObjectManager.h"
#include "products/components/productlist.h"
#include "products/components/productdialog.h"

#include "qtmaterial/components/qtmaterialscrollbar.h"
#include "qtmaterial/components/qtmaterialsnackbar.h"
#include "qtmaterial/components/qtmaterialdialog.h"
#include "qtmaterial/components/qtmaterialfab.h"

#include <QScrollArea>
#include <QLocale>

class QHBoxLayout;

class ProductPage;
class ProductPagePrivate
{
    Q_DISABLE_COPY(ProductPagePrivate)
    Q_DECLARE_PUBLIC(ProductPage)

public:
    explicit ProductPagePrivate(ProductPage *q);
    ~ProductPagePrivate();

    void init();

    ProductPage *const              q_ptr;
    QHBoxLayout                     *m_layout;
    QtMaterialFloatingActionButton  *m_fabButton;

    // Product Manager
    ProductObjectManager            *m_productManager;

    // Product List
    FrameTitle                      *m_productListTitle;
    ProductList                     *m_productList;

    // Scroll Area
    QScrollArea                     *m_productScrollArea;

    // Product Dialog
    QtMaterialDialog                *m_productDialog;
    ProductDialog                   *m_productDialogWidget;

    // Notification
    QtMaterialSnackbar              *m_snackBar;
    QLocale                         m_locale;
};

#endif //QTHNI_PRODUCTPAGE_P_H
