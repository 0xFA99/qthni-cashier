#ifndef QTHNI_ORDERLIST_P_H
#define QTHNI_ORDERLIST_P_H

class QVBoxLayout;

class OrderList;
class OrderListPrivate
{
    Q_DISABLE_COPY(OrderListPrivate)
    Q_DECLARE_PUBLIC(OrderList);

public:
    explicit OrderListPrivate(OrderList *q);
    ~OrderListPrivate();

    void init();

    OrderList *const    q_ptr;
    QVBoxLayout         *m_layout;
};

#endif //QTHNI_ORDERLIST_P_H
