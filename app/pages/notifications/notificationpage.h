#ifndef QTHNI_NOTIFICATIONPAGE_H
#define QTHNI_NOTIFICATIONPAGE_H

#include <QWidget>

class NotificationPagePrivate;
class NotificationPage : public QWidget
{
    Q_OBJECT;

public:
    explicit NotificationPage(QWidget *parent = nullptr);
    ~NotificationPage();

protected:
    const QScopedPointer<NotificationPagePrivate> d_ptr;

private:
    Q_DISABLE_COPY(NotificationPage)
    Q_DECLARE_PRIVATE(NotificationPage)
};

#endif //QTHNI_NOTIFICATIONPAGE_H
