#ifndef HMATERIALCURRENCY_H
#define HMATERIALCURRENCY_H

#include "hmateriallabel.h"

class HMaterialCurrencyPrivate;

class HMaterialCurrency : public HMaterialLabel
{
public:
    explicit HMaterialCurrency(QWidget *parent);
    explicit HMaterialCurrency(int money, QWidget *parent);
    ~HMaterialCurrency();

    void setMoney(int value);
    void increaseMoney(int value);
    void decreaseMoney(int value);

    int money() const;

protected:
    const QScopedPointer<HMaterialCurrencyPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HMaterialCurrency)
    Q_DECLARE_PRIVATE(HMaterialCurrency)
};

#endif
