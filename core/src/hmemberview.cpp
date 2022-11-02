#include "hmemberview.h"
#include "hmemberview_p.h"

#include <QVBoxLayout>

#include "hmemberitem.h"

HMemberViewPrivate::HMemberViewPrivate(HMemberView *q)
    : q_ptr(q)
{
}

HMemberViewPrivate::~HMemberViewPrivate()
{
}

void HMemberViewPrivate::init()
{
    Q_Q(HMemberView);

    m_layout    = new QVBoxLayout(q);

    m_layout->addStretch(1);
    m_layout->setContentsMargins(0, 0, 0, 0);
}

HMemberView::HMemberView(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HMemberViewPrivate(this))
{
    d_func()->init();
}

HMemberView::~HMemberView()
{
}

void HMemberView::addItem()
{
    Q_D(HMemberView);

    HMemberItem *item = new HMemberItem(this);

    d->m_layout->insertWidget(d->m_layout->count() - 1, item);
}
