#ifndef HMATERIALPROFILE_PRIVATE_H
#define HMATERIALPROFILE_PRIVATE_H

#include "hmaterialavatar.h"
#include "hmateriallabel.h"

#include "hmaterialflatbutton.h"

class QGridLayout;

class HMaterialProfile;
class HMaterialProfilePrivate
{
    Q_DISABLE_COPY(HMaterialProfilePrivate)
    Q_DECLARE_PUBLIC(HMaterialProfile)

public:
    HMaterialProfilePrivate(HMaterialProfile *q);
    ~HMaterialProfilePrivate();

    void init();

    HMaterialProfile *const q_ptr;
    QGridLayout             *m_layout;

    HMaterialAvatar         *m_avatar;
    HMaterialLabel          *m_name;
    HMaterialLabel          *m_id;

    HMaterialFlatButton     *m_editButton;
};

#endif
