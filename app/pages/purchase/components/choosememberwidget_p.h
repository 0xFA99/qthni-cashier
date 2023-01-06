#ifndef QTHNI_CHOOSEMEMBERWIDGET_P_H
#define QTHNI_CHOOSEMEMBERWIDGET_P_H

#include "qtmaterial/components/qtmaterialautocomplete.h"
#include "qtmaterial/components/qtmaterialflatbutton.h"

#include <QStringList>

class QVBoxLayout;
class ChooseMemberWidget;
class ChooseMemberWidgetPrivate
{
    Q_DISABLE_COPY(ChooseMemberWidgetPrivate)
    Q_DECLARE_PUBLIC(ChooseMemberWidget)

public:
    explicit ChooseMemberWidgetPrivate(ChooseMemberWidget *q);
    ~ChooseMemberWidgetPrivate();

    void init();

    ChooseMemberWidget *const       q_ptr;
    QVBoxLayout                     *m_layout;
    QtMaterialAutoComplete          *m_autoComplete;
    QtMaterialFlatButton            *m_submitButton;

    QStringList                     m_memberList;
};

#endif //QTHNI_CHOOSEMEMBERWIDGET_P_H
