#ifndef QTHNI_RESULTPURCHASE_H
#define QTHNI_RESULTPURCHASE_H

#include <QWidget>

class ResultPurchasePrivate;
class ResultPurchase : public QWidget
{
    Q_OBJECT

public:
    explicit ResultPurchase(QWidget *parent = nullptr);
    ~ResultPurchase();

protected:
    const QScopedPointer<ResultPurchasePrivate> d_ptr;

private:
    Q_DISABLE_COPY(ResultPurchase)
    Q_DECLARE_PRIVATE(ResultPurchase)
};

#endif //QTHNI_RESULTPURCHASE_H
