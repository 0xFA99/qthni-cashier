#ifndef QTHNI_MEMBERPAGE_P_H
#define QTHNI_MEMBERPAGE_P_H

#include "widgets/frametitle.h"

#include "members/MemberObjectManager.h"
#include "members/components/memberlist.h"
#include "members/components/memberdialog.h"
#include "members/components/profiledialog.h"

#include "qtmaterial/components/qtmaterialdialog.h"
#include "qtmaterial/components/qtmaterialscrollbar.h"
#include "qtmaterial/components/qtmaterialfab.h"
#include "qtmaterial/components/qtmaterialsnackbar.h"

#include <QScrollArea>

class QHBoxLayout;

class MemberPage;
class MemberPagePrivate
{
    Q_DISABLE_COPY(MemberPagePrivate)
    Q_DECLARE_PUBLIC(MemberPage)

public:
    explicit MemberPagePrivate(MemberPage *q);
    ~MemberPagePrivate();

    void init();

    MemberPage *const               q_ptr;
    QHBoxLayout                     *m_layout;
    QtMaterialFloatingActionButton  *m_fabButton;

    // Member List
    FrameTitle                      *m_memberListTitle;
    MemberList                      *m_memberList;

    // Scroll Area
    QScrollArea                     *m_memberScrollArea;

    // Member Dialog
    QtMaterialDialog                *m_memberDialog;
    MemberDialog                    *m_memberDialogWidget;

    // Notification
    QtMaterialSnackbar              *m_snackBar;

    // Profile Dialog
    QtMaterialDialog                *m_profileDialog;
    ProfileDialog                   *m_profileDialogWidget;

    // TEST
    MemberObjectManager             *m_memberManager;

};

#endif //QTHNI_MEMBERPAGE_P_H
