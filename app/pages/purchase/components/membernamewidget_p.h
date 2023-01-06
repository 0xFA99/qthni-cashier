#ifndef QTHNI_MEMBERNAMEWIDGET_P_H
#define QTHNI_MEMBERNAMEWIDGET_P_H

#include "qtmaterial/components/qtmaterialflatbutton.h"

class QLabel;
class QHBoxLayout;

class MemberNameWidget;
class MemberNameWidgetPrivate
{
    Q_DISABLE_COPY(MemberNameWidgetPrivate)
    Q_DECLARE_PUBLIC(MemberNameWidget)

public:
    explicit MemberNameWidgetPrivate(MemberNameWidget *q);
    ~MemberNameWidgetPrivate();

    void init();

    MemberNameWidget *const     q_ptr;
    QHBoxLayout                 *m_layout;
    QLabel                      *m_memberName;
    QtMaterialFlatButton        *m_changeButton;
};

#endif //QTHNI_MEMBERNAMEWIDGET_P_H
