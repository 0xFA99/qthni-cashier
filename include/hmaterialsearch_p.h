#ifndef HMATERIALSEARCH_PRIVATE_H
#define HMATERIALSEARCH_PRIVATE_H

#include "hmaterialflatbutton.h"
#include "hmaterialtextfield.h"

class QHBoxLayout;

class HMaterialSearch;
class HMaterialSearchPrivate
{
    Q_DISABLE_COPY(HMaterialSearchPrivate)
    Q_DECLARE_PUBLIC(HMaterialSearch)

public:
    HMaterialSearchPrivate(HMaterialSearch *q);
    ~HMaterialSearchPrivate();

    void init();

    HMaterialSearch *const  q_ptr;
    QHBoxLayout             *m_layout;
    HMaterialTextField      *m_search;
    HMaterialFlatButton     *m_button;
};

#endif
