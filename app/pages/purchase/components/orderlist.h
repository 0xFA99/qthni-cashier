#ifndef QTHNI_ORDERLIST_H
#define QTHNI_ORDERLIST_H

#include <QWidget>

class OrderListPrivate;
class OrderList : public QWidget
{
    Q_OBJECT

public:
    explicit OrderList(QWidget *parent = nullptr);
    ~OrderList();

protected:
    const QScopedPointer<OrderListPrivate> d_ptr;

private:
    Q_DISABLE_COPY(OrderList)
    Q_DECLARE_PRIVATE(OrderList)
};

#endif //QTHNI_ORDERLIST_H
