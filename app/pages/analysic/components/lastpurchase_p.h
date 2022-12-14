#ifndef QTHNI_LASTPURCHASE_P_H
#define QTHNI_LASTPURCHASE_P_H

#include <QtCore>

class QVBoxLayout;

class LastPurchase;
class LastPurchasePrivate
{
    Q_DISABLE_COPY(LastPurchasePrivate)
    Q_DECLARE_PUBLIC(LastPurchase)

public:
    explicit LastPurchasePrivate(LastPurchase *q);
    ~LastPurchasePrivate();

    void init();

    LastPurchase *const     q_ptr;
    QVBoxLayout             *m_layout;
};

#endif //QTHNI_LASTPURCHASE_P_H
