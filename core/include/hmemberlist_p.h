#ifndef HMEMBERLIST_PRIVATE_H
#define HMEMBERLIST_PRIVATE_H

#include "hmemberview.h"
#include "hmemberedit.h"
#include "hmaterialdialog.h"
#include "hmaterialfab.h"
#include "hmateriallabel.h"
#include "hmaterialflatbutton.h"

#include <QScrollArea>
#include <QVector>

class QVBoxLayout;
class QGridLayout;

class HMember;
class HMemberList;
class HMemberListPrivate
{
    Q_DISABLE_COPY(HMemberListPrivate)
    Q_DECLARE_PUBLIC(HMemberList)

public:
    explicit HMemberListPrivate(HMemberList *q);
    ~HMemberListPrivate();

    void init();

    HMemberList *const  q_ptr;

    QGridLayout                     *m_layout;

    HMaterialLabel                  *m_title;
    HMaterialFlatButton             *m_gridButton;
    HMaterialFlatButton             *m_vertButton;
    HMaterialFloatingActionButton   *m_fabButton;

    QScrollArea                     *m_scrollArea;
    HMemberView                     *m_memberView;
    QVector<HMember *>              m_memberList;

    // Dialog
    HMaterialDialog                 *m_dialog;
    QVBoxLayout                     *m_dialogLayout;
    HMemberEdit                     *m_memberDialog;
};

#endif
