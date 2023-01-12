#ifndef QTHNI_PRODUCTDIALOG_P_H
#define QTHNI_PRODUCTDIALOG_P_H

#include "qtmaterial/components/qtmaterialavatar.h"
#include "qtmaterial/components/qtmaterialiconbutton.h"
#include "qtmaterial/components/qtmaterialflatbutton.h"
#include "qtmaterial/components/qtmaterialtextfield.h"
#include "qtmaterial/components/qtmaterialdialog.h"

#include <QLocale>
#include <QLabel>
#include <QUuid>

#include "products/ProductObjectManager.h"
#include "qtmaterial/components/qtmaterialradiobutton.h"

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
    QtMaterialTextField         *m_memberPriceField;
    QtMaterialTextField         *m_customerPriceField;
    QtMaterialTextField         *m_stockField;
    QtMaterialTextField         *m_pointField;

    QtMaterialFlatButton        *m_cancelButton;
    QtMaterialFlatButton        *m_submitButton;

    QLocale                     m_locale;
    ProductDialog::Mode         m_mode;

    QUuid                       m_uuid;
    ProductObjectManager        *m_productManager;
};

#endif //QTHNI_PRODUCTDIALOG_P_H
