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
    // m_priceMapList  = QMap<int, int>();
    m_memPriceList     = QMap<QUuid, int>();
    m_cusPriceList     = QMap<QUuid, int>();
    m_hasMember        = false;

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

    QObject::connect(m_button, &QPushButton::clicked, [q]() {
        emit q->s_submitButton();
    });
}

PriceWidget::PriceWidget(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new PriceWidgetPrivate(this))
{
    d_func()->init();
}

PriceWidget::~PriceWidget() = default;

void PriceWidget::changeSubTotal(QUuid uuid, int price)
{
    Q_D(PriceWidget);

    if (d->m_memPriceList.find(uuid) != d->m_memPriceList.end()) {
        d->m_memPriceList.insert(uuid, price);
    } else {
        d->m_memPriceList[uuid] = price;
    }

    updateTotal();
}

void PriceWidget::changeDiscount(QUuid uuid, int price)
{
    Q_D(PriceWidget);

    if (d->m_cusPriceList.find(uuid) != d->m_cusPriceList.end()) {
        d->m_cusPriceList.insert(uuid, price);
    } else {
        d->m_cusPriceList[uuid] = price;
    }

    updateTotal();
}

void PriceWidget::updateTotal()
{
    Q_D(PriceWidget);

    int subTotal = 0, discount = 0, total;

    for (auto i : d->m_memPriceList.values()) {
        subTotal += i;
    }

    if (d->m_hasMember) {
        for (auto i: d->m_cusPriceList.values()) {
            discount += i;
        }
    }

    total = subTotal - discount;

    d->m_total->setText("Rp " + d->m_locale.toString(total));
    d->m_subTotal->setText("Rp " + d->m_locale.toString(subTotal));
    d->m_discount->setText("Rp " + d->m_locale.toString(discount));

    updateSubTotal(d->m_subTotal->text());
    updateDiscount(d->m_discount->text());
}

void PriceWidget::deleteItemPrice(QUuid uuid)
{
    Q_D(PriceWidget);

    d->m_memPriceList.remove(uuid);
    d->m_cusPriceList.remove(uuid);

    updateTotal();
}

void PriceWidget::memberChoosen(bool status)
{
    Q_D(PriceWidget);

    d->m_hasMember = status;

    updateTotal();
}