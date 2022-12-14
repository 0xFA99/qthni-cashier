#ifndef QTHNI_NOTIFICATIONPAGE_P_H
#define QTHNI_NOTIFICATIONPAGE_P_H

#include <QtCore>

class NotificationPage;
class NotificationPagePrivate
{
    Q_DISABLE_COPY(NotificationPagePrivate)
    Q_DECLARE_PUBLIC(NotificationPage)

public:
    explicit NotificationPagePrivate(NotificationPage *q);
    ~NotificationPagePrivate();

    void init();

    NotificationPage *const     q_ptr;
};

#endif //QTHNI_NOTIFICATIONPAGE_P_H
