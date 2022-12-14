#ifndef QTHNI_SEARCHFIELD_P_H
#define QTHNI_SEARCHFIELD_P_H

#include "qtmaterial/components/qtmaterialtextfield.h"
#include "qtmaterial/components/qtmaterialiconbutton.h"

class QHBoxLayout;

class SearchField;
class SearchFieldPrivate
{
    Q_DISABLE_COPY(SearchFieldPrivate)
    Q_DECLARE_PUBLIC(SearchField)

public:
    explicit SearchFieldPrivate(SearchField *q);
    ~SearchFieldPrivate();

    void init();

    SearchField *const      q_ptr;
    QHBoxLayout             *m_layout;
    QtMaterialTextField     *m_lineEdit;
    QtMaterialIconButton    *m_iconButton;
};

#endif //QTHNI_SEARCHFIELD_P_H
