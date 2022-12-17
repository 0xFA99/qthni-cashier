#ifndef QTHNI_PROFILEDIALOG_P_H
#define QTHNI_PROFILEDIALOG_P_H

#include "qtmaterial/components/qtmaterialavatar.h"
#include "qtmaterial/components/qtmaterialflatbutton.h"

#include <QScrollArea>
#include <QList>

class FlowLayout;
class QVBoxLayout;
class QGridLayout;

class ProfileDialog;
class ProfileDialogPrivate
{
    Q_DISABLE_COPY(ProfileDialogPrivate)
    Q_DECLARE_PUBLIC(ProfileDialog)

public:
    explicit ProfileDialogPrivate(ProfileDialog *q);
    ~ProfileDialogPrivate();

    void init();

    ProfileDialog *const    q_ptr;
    QVBoxLayout             *m_layout;

    // Front Side
    QWidget                 *m_frontWidget;
    QVBoxLayout             *m_frontLayout;

    // Top Side
    QtMaterialAvatar        *m_currentAvatar;

    // Bottom Side
    QScrollArea             *m_scrollArea;
    QWidget                 *m_profileList;
    FlowLayout             *m_profileLayout;

    QtMaterialFlatButton    *m_closeButton;
};


#endif //QTHNI_PROFILEDIALOG_P_H
