#ifndef HMEMBEREDIT_PRIVATE_H
#define HMEMBEREIDT_PRIVATE_H

#include "hmaterialavatar.h"
#include "hmaterialtextfield.h"
#include "hmaterialflatbutton.h"

class QGridLayout;

class HMemberEdit;
class HMemberEditPrivate
{
    Q_DISABLE_COPY(HMemberEditPrivate)
    Q_DECLARE_PUBLIC(HMemberEdit)

public:
    HMemberEditPrivate(HMemberEdit *q);
    ~HMemberEditPrivate();

    void init();

    HMemberEdit *const  q_ptr;

    QGridLayout         *m_layout;

    HMaterialAvatar     *m_avatar;
    HMaterialTextField  *m_name;
    HMaterialTextField  *m_id;
    HMaterialFlatButton *m_avatarButton;
    HMaterialFlatButton *m_cancelButton;
    HMaterialFlatButton *m_submitButton;
};

#endif
