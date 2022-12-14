#ifndef QTHNI_LASTPURCHASE_H
#define QTHNI_LASTPURCHASE_H

#include <QWidget>

class LastPurchasePrivate;
class LastPurchase : public QWidget
{
    Q_OBJECT

public:
    explicit LastPurchase(QWidget *parent = nullptr);
    ~LastPurchase();

protected:
    const QScopedPointer<LastPurchasePrivate> d_ptr;

private:
    Q_DISABLE_COPY(LastPurchase)
    Q_DECLARE_PRIVATE(LastPurchase)
};

#endif //QTHNI_LASTPURCHASE_H
