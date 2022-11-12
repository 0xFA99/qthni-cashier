#ifndef HMEMBERMODEL_PRIVATE_H
#define HMEMBERMODEL_PRIVATE_H

#include "hmateriallabel.h"
#include "hmaterialavatar.h"
#include "hmaterialflatbutton.h"

class QGridLayout;

class HMemberModel;
class HMemberModelPrivate
{
    Q_DISABLE_COPY(HMemberModelPrivate);
    Q_DECLARE_PUBLIC(HMemberModel);

public:
    HMemberModelPrivate(HMemberModel *q);
    ~HMemberModelPrivate();

    void init();

    HMemberModel *const q_ptr;

    QGridLayout         *m_layout;

    HMaterialAvatar     *m_avatar;
    HMaterialLabel      *m_nameLabel;
    HMaterialLabel      *m_idLabel;
    HMaterialFlatButton *m_editButton;
    HMaterialFlatButton *m_removeButton;

    QImage              m_image;
    QString             m_name;
    QString             m_id;
};

#endif
