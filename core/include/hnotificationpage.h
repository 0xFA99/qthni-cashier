#ifndef HNOTIFICATIONPAGE_H
#define HNOTIFICATIONPAGE_H

#include <QWidget>

class HNotificationPagePrivate;
class HNotificationPage : public QWidget
{
    Q_OBJECT

public:
    explicit HNotificationPage(QWidget *parent = nullptr);
    ~HNotificationPage();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    const QScopedPointer<HNotificationPagePrivate> d_ptr;

private:
    Q_DISABLE_COPY(HNotificationPage)
    Q_DECLARE_PRIVATE(HNotificationPage)
};

#endif
