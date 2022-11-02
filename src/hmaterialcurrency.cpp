#include "hmaterialcurrency.h"
#include "hmaterialcurrency_p.h"

HMaterialCurrencyPrivate::HMaterialCurrencyPrivate(HMaterialCurrency *q)
    : q_ptr(q)
{
}

HMaterialCurrencyPrivate::~HMaterialCurrencyPrivate()
{
}

void HMaterialCurrencyPrivate::init()
{
    Q_Q(HMaterialCurrency);

    m_money = 0;
    m_locale = QLocale("id_ID");
}

HMaterialCurrency::HMaterialCurrency(QWidget *parent)
    : HMaterialLabel(parent)
    , d_ptr(new HMaterialCurrencyPrivate(this))
{
    d_func()->init();

    setMoney(0);
    setAlignment(Qt::AlignRight | Qt::AlignVCenter);
}

HMaterialCurrency::HMaterialCurrency(int value, QWidget *parent)
    : HMaterialLabel(parent)
    , d_ptr(new HMaterialCurrencyPrivate(this))
{
    d_func()->init();

    setMoney(value);
    setAlignment(Qt::AlignRight | Qt::AlignVCenter);
}

HMaterialCurrency::~HMaterialCurrency()
{
}

void HMaterialCurrency::setMoney(int value)
{
    Q_D(HMaterialCurrency);

    d->m_money = value;

    setText("Rp " + d->m_locale.toString(d->m_money));
}

void HMaterialCurrency::increaseMoney(int value)
{
    Q_D(HMaterialCurrency);

   d->m_money += value;

   setText("Rp " + d->m_locale.toString(d->m_money));
}

void HMaterialCurrency::decreaseMoney(int value)
{
    Q_D(HMaterialCurrency);

    d->m_money -= value;
    if (d->m_money < 0)
        d->m_money = 0;

    setText("Rp " + d->m_locale.toString(d->m_money));
}

int HMaterialCurrency::money() const
{
    Q_D(const HMaterialCurrency);

    return d->m_money;
}
