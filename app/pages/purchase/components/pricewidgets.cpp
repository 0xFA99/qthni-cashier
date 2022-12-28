#include "purchase/components/pricewidgets.h"
#include "purchase/components/pricewidget_p.h"

#include <QVBoxLayout>

PriceWidgetPrivate::PriceWidgetPrivate(PriceWidget *q)
    : q_ptr(q)
{
}

PriceWidgetPrivate::~PriceWidgetPrivate() = default;

void PriceWidgetPrivate::init()
{
    Q_Q(PriceWidget);

    m_layout    = new QVBoxLayout(q);
    m_total     = new QtMaterialTextField(q);
    m_subTotal  = new QtMaterialTextField(q);
    m_discount  = new QtMaterialTextField(q);
    m_button    = new QtMaterialFlatButton("SUBMIT", q);

    m_locale    = QLocale("id_ID");
    m_priceMapList  = QMap<int, int>();

    m_total->setLabel("TOTAL");
    m_total->setText("Rp 0");
    m_subTotal->setLabel("SUB TOTAL");
    m_subTotal->setText("Rp 0");
    m_discount->setLabel("DISCOUNT");
    m_discount->setText("Rp 0");

    m_total->setReadOnly(true);
    m_subTotal->setReadOnly(true);
    m_discount->setReadOnly(true);

    m_button->setBackgroundMode(Qt::OpaqueMode);
    m_button->setRole(Material::Primary);

    m_layout->addWidget(m_subTotal);
    m_layout->addWidget(m_discount);
    m_layout->addWidget(m_total);
    m_layout->addWidget(m_button);
}

PriceWidget::PriceWidget(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new PriceWidgetPrivate(this))
{
    d_func()->init();
}

PriceWidget::~PriceWidget() = default;

void PriceWidget::changeSubTotal(int index, int price)
{
    Q_D(PriceWidget);

    if (d->m_priceMapList.find(index) != d->m_priceMapList.end()) {
        d->m_priceMapList.insert(index, price);
    } else {
        d->m_priceMapList[index] = price;
    }

    updateTotal();
}

void PriceWidget::updateTotal()
{
    Q_D(PriceWidget);

    int subTotal = 0;

    if (!d->m_priceMapList.isEmpty()) {
        for (int i: d->m_priceMapList.values()) {
            subTotal += i;
        }
    }

    d->m_subTotal->setText("Rp " + d->m_locale.toString(subTotal));
}

void PriceWidget::deleteItemPrice(int index)
{
    Q_D(PriceWidget);

    d->m_priceMapList.remove(index);
    updateTotal();
}