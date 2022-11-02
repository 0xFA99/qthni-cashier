#ifndef HOPTIONPAGE_PRIVATE_H
#define HOPTIONPAGE_PRIVATE_H

#include "hconstructorpage.h"

class QHBoxLayout;

class HOptionPage;
class HOptionPagePrivate
{
    Q_DISABLE_COPY(HOptionPagePrivate)
    Q_DECLARE_PUBLIC(HOptionPage)

public:
    HOptionPagePrivate(HOptionPage *q);
    ~HOptionPagePrivate();

    void init();

    HOptionPage *const  q_ptr;
    QHBoxLayout         *m_layout;
    HConstructorPage    *m_constructor;
};

#endif
