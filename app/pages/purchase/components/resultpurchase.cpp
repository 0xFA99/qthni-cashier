#include "purchase/components/resultpurchase.h"
#include "purchase/components/resultpurchase_p.h"

#include <QGridLayout>

ResultPurchasePrivate::ResultPurchasePrivate(ResultPurchase *q)
    : q_ptr(q)
{
}

ResultPurchasePrivate::~ResultPurchasePrivate() = default;

void ResultPurchasePrivate::init()
{
    Q_Q(ResultPurchase);

    m_layout        = new QGridLayout(q);
    m_closeButton   = new QtMaterialFlatButton(q);
    m_submitButton  = new QtMaterialFlatButton(q);

    m_layout->addWidget(m_closeButton, 0, 0, 1, 1);
    m_layout->addWidget(m_submitButton, 0, 1, 1, 1);
}

ResultPurchase::ResultPurchase(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new ResultPurchasePrivate(this))
{
    d_func()->init();
}

ResultPurchase::~ResultPurchase() = default;