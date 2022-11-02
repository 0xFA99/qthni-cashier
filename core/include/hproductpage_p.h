#ifndef HPRODUCTPAGE_PRIVATE_H
#define HPRODUCTPAGE_PRIVATE_H

#include "hconstructorpage.h"

class QHBoxLayout;

class HProductPage;
class HProductPagePrivate
{
    Q_DISABLE_COPY(HProductPagePrivate)
    Q_DECLARE_PUBLIC(HProductPage)

public:
    HProductPagePrivate(HProductPage *q);
    ~HProductPagePrivate();

    void init();

    HProductPage *const  q_ptr;
    QHBoxLayout         *m_layout;
    HConstructorPage    *m_constructor;
};

#endif
