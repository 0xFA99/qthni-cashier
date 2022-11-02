#ifndef HANALYSICPAGE_PRIVATE_H
#define HANALYSICPAGE_PRIVATE_H

#include <QWidget>

#include "hconstructorpage.h"

class QHBoxLayout;

class HAnalysicPage;
class HAnalysicPagePrivate
{
    Q_DISABLE_COPY(HAnalysicPagePrivate)
    Q_DECLARE_PUBLIC(HAnalysicPage)

public:
    HAnalysicPagePrivate(HAnalysicPage *q);
    ~HAnalysicPagePrivate();

    void init();

    HAnalysicPage *const    q_ptr;
    QHBoxLayout             *m_layout;
    HConstructorPage        *m_emptyPage;
};

#endif
