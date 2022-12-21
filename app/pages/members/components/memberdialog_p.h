#ifndef QTHNI_MEMBERDIALOG_P_H
#define QTHNI_MEMBERDIALOG_P_H

#include "qtmaterial/components/qtmaterialavatar.h"
#include "qtmaterial/components/qtmaterialiconbutton.h"
#include "qtmaterial/components/qtmaterialflatbutton.h"
#include "qtmaterial/components/qtmaterialtextfield.h"

class OperateItem;
class QGridLayout;

class MemberDialog;
class MemberDialogPrivate
{
    Q_DISABLE_COPY(MemberDialogPrivate)
    Q_DECLARE_PUBLIC(MemberDialog)

public:
    explicit MemberDialogPrivate(MemberDialog *q);
    ~MemberDialogPrivate();

    void init();

    MemberDialog *const     q_ptr;
    QGridLayout             *m_layout;
    QtMaterialAvatar        *m_avatar;
    QtMaterialIconButton    *m_changeAvatarButton;
    QtMaterialTextField     *m_nameField;
    QtMaterialTextField     *m_idField;
    QtMaterialFlatButton    *m_closeButton;
    QtMaterialFlatButton    *m_submitButton;

    MemberDialog::Mode      m_mode;
    int                     m_index;
};

#endif //QTHNI_MEMBERDIALOG_P_H
