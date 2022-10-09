#ifndef HMATERIALCURRENCY_H
#define HMATERIALCURRENCY_H

#include "hmateriallabel.h"
#include "hmaterialtheme.h"

class HMaterialCurrencyPrivate;

class HMaterialCurrency : public HMaterialLabel
{
public:
    explicit HMaterialCurrency(QWidget *parent = nullptr);
    explicit HMaterialCurrency(int value, QWidget *parent = nullptr);
    ~HMaterialCurrency();

    void setRole(HMaterial::Role role);

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
