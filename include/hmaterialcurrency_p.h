#ifndef HMATERIALCURRENCY_PRIVATE_H
#define HMATERIALCURRENCY_PRIVATE_H

#include <QLocale>

class HMaterialCurrency;

class HMaterialCurrencyPrivate
{
    Q_DISABLE_COPY(HMaterialCurrencyPrivate)
    Q_DECLARE_PUBLIC(HMaterialCurrency)

public:
    HMaterialCurrencyPrivate(HMaterialCurrency *q);
    ~HMaterialCurrencyPrivate();

    void init();

    HMaterialCurrency *const    q_ptr;
    int                         m_money;
    QLocale                     m_locale;
};

#endif
