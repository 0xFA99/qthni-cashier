#ifndef QTHNI_REMAININGSTOCK_H
#define QTHNI_REMAININGSTOCK_H

#include <QWidget>

class MinimalItem;
class RemainingStockPrivate;
class RemainingStock : public QWidget
{
    Q_OBJECT

public:
    explicit RemainingStock(QWidget *parent = nullptr);
    ~RemainingStock();

    void addRemaindItem(MinimalItem*);
    void deleteRemaindItem(int);

protected:
    const QScopedPointer<RemainingStockPrivate> d_ptr;

private:
    Q_DISABLE_COPY(RemainingStock)
    Q_DECLARE_PRIVATE(RemainingStock)
};

#endif //QTHNI_REMAININGSTOCK_H
