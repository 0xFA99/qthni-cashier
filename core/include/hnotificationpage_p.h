#ifndef HNOTIFICATION_PRIVATE_H
#define HNOTIFICATION_PRIVATE_H

#include "hconstructorpage.h"

class QHBoxLayout;

class HNotificationPage;
class HNotificationPagePrivate
{
    Q_DISABLE_COPY(HNotificationPagePrivate)
    Q_DECLARE_PUBLIC(HNotificationPage)

public:
    HNotificationPagePrivate(HNotificationPage *q);
    ~HNotificationPagePrivate();

    void init();

    HNotificationPage *const  q_ptr;
    QHBoxLayout         *m_layout;
    HConstructorPage    *m_constructor;
};

#endif
