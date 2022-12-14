#ifndef QTHNI_PRODUCTDIALOG_P_H
#define QTHNI_PRODUCTDIALOG_P_H

#include "qtmaterial/components/qtmaterialavatar.h"
#include "qtmaterial/components/qtmaterialiconbutton.h"
#include "qtmaterial/components/qtmaterialflatbutton.h"
#include "qtmaterial/components/qtmaterialtextfield.h"

class Product;
class OperateItem;
class QGridLayout;

class ProductDialog;
class ProductDialogPrivate
{
    Q_DISABLE_COPY(ProductDialogPrivate)
    Q_DECLARE_PUBLIC(ProductDialog)

public:
    explicit ProductDialogPrivate(ProductDialog *q);
    ~ProductDialogPrivate();

    void init();

    ProductDialog *const        q_ptr;
    QGridLayout                 *m_layout;
    QtMaterialAvatar            *m_avatar;
    QtMaterialIconButton        *m_changeAvatarButton;
    QtMaterialTextField         *m_nameField;
    QtMaterialTextField         *m_priceField;
    QtMaterialTextField         *m_stockField;
    QtMaterialTextField         *m_pointField;
    QtMaterialFlatButton        *m_cancelButton;
    QtMaterialFlatButton        *m_submitButton;

    ProductDialog::Mode         m_mode;
    int                         m_index;
};

#endif //QTHNI_PRODUCTDIALOG_P_H
