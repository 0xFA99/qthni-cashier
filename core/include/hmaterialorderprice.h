#ifndef HMATERIALORDERPRICE_H
#define HMATERIALORDERPRICE_H

#include "hmaterialframe.h"

class HMaterialOrderPricePrivate;
class HMaterialOrderPrice : public HMaterialFrame
{
    Q_OBJECT

public:
    explicit HMaterialOrderPrice(QWidget *parent = nullptr);
    ~HMaterialOrderPrice();

    void increaseSubTotal(int value);
    void decreaseSubTotal(int value);
    int subTotal() const;

    void increaseDiscount(int value);
    void decreaseDiscount(int value);
    int discount() const;

    int total() const;

protected:
    const QScopedPointer<HMaterialOrderPricePrivate> d_ptr;

private:
    Q_DISABLE_COPY(HMaterialOrderPrice)
    Q_DECLARE_PRIVATE(HMaterialOrderPrice)
};

#endif
