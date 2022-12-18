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

    m_total->setLabel("TOTAL");
    m_total->setText("Rp 100.000");
    m_subTotal->setLabel("SUB TOTAL");
    m_subTotal->setText("Rp 50.000");
    m_discount->setLabel("DISCOUNT");
    m_discount->setText("Rp 50.000");

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