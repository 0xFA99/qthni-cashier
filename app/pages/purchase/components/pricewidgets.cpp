#include "purchase/components/pricewidgets.h"
#include "purchase/components/pricewidgets_p.h"

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
    m_disPriceList     = QMap<QUuid, int>();
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

    if (d->m_cusPriceList.find(uuid) != d->m_cusPriceList.end()) {
        d->m_cusPriceList.insert(uuid, price);
    } else {
        d->m_cusPriceList[uuid] = price;
    }

    int subTotal = 0;
    for (auto i : d->m_cusPriceList.values()) {
        subTotal += i;
    }

    d->m_subTotalInt = subTotal;

    updateDiscount(uuid, (price - d->m_memPriceList[uuid]));
    updateTotal();
}

void PriceWidget::changeMemTotal(QUuid uuid, int price)
{
    Q_D(PriceWidget);

    if (d->m_memPriceList.find(uuid) != d->m_memPriceList.end()) {
        d->m_memPriceList.insert(uuid, price);
    } else {
        d->m_memPriceList[uuid] = price;
    }

    int memTotal = 0;
    for (auto i : d->m_memPriceList.values()) {
        memTotal += i;
    }

    d->m_memTotalInt = memTotal;

    updateDiscount(uuid, (d->m_cusPriceList[uuid] - price));
    updateTotal();
}

void
PriceWidget::updateDiscount(QUuid uuid, int price)
{
    Q_D(PriceWidget);

    if (d->m_disPriceList.find(uuid) != d->m_disPriceList.end()) {
        d->m_disPriceList.insert(uuid, price);
    } else {
        d->m_disPriceList[uuid] = price;
    }

    int discount = 0;
    for (auto i : d->m_disPriceList.values()) {
        discount += i;
    }

    d->m_disTotalInt = discount;
    updateTotal();
}

void PriceWidget::updateTotal()
{
    Q_D(PriceWidget);

    d->m_subTotal->setText("Rp " + d->m_locale.toString(d->m_subTotalInt));

    if (d->m_hasMember) {
        d->m_discount->setText("Rp " + d->m_locale.toString(d->m_disTotalInt));
        d->m_total->setText("Rp " + d->m_locale.toString(d->m_memTotalInt));
    } else {
        d->m_discount->setText("Rp 0");
        d->m_total->setText("Rp " + d->m_locale.toString(d->m_subTotalInt));
    }

    updateSubTotal(d->m_subTotal->text());
    updateDiscount(d->m_discount->text());
}

void PriceWidget::deleteItemPrice(QUuid uuid)
{
    Q_D(PriceWidget);

    d->m_memPriceList.remove(uuid);
    d->m_cusPriceList.remove(uuid);
    d->m_disPriceList.remove(uuid);

    int x = 0;
    for (auto i : d->m_cusPriceList.values()) {
        x += i;
    }
    d->m_subTotalInt = x;

    x = 0;
    for (auto i : d->m_disPriceList.values()) {
        x += i;
    }
    d->m_disTotalInt = x;

    x = 0;
    for (auto i : d->m_memPriceList.values()) {
        x += i;
    }
    d->m_memTotalInt = x;

    updateTotal();
}

void PriceWidget::memberChoosen(bool status)
{
    Q_D(PriceWidget);

    d->m_hasMember = status;

    updateTotal();
}