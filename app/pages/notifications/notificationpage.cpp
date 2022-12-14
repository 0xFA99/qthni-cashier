#include "notifications/notificationpage.h"
#include "notifications/notificationpage_p.h"

NotificationPagePrivate::NotificationPagePrivate(NotificationPage *q)
    : q_ptr(q)
{
}

NotificationPagePrivate::~NotificationPagePrivate() = default;

void NotificationPagePrivate::init()
{
    Q_Q(NotificationPage);
}

NotificationPage::NotificationPage(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new NotificationPagePrivate(this))
{
    d_func()->init();
}

NotificationPage::~NotificationPage() = default;