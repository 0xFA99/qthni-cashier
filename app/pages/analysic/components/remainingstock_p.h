#ifndef QTHNI_REMAININGSTOCK_P_H
#define QTHNI_REMAININGSTOCK_P_H

#include <QtCore>

class QVBoxLayout;

class RemainingStock;
class RemainingStockPrivate
{
    Q_DISABLE_COPY(RemainingStockPrivate)
    Q_DECLARE_PUBLIC(RemainingStock)

public:
    explicit RemainingStockPrivate(RemainingStock *q);
    ~RemainingStockPrivate();

    void init();

    RemainingStock *const   q_ptr;
    QVBoxLayout             *m_layout;
};

#endif //QTHNI_REMAININGSTOCK_P_H
