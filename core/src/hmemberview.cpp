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
    
    setStyleSheet("QWidget { background-color: white; };");
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
}

HMemberView::~HMemberView()
{
}

void HMemberView::addItem(HMemberItem *item)
{
    Q_D(HMemberView);

    d->m_layout->insertWidget(d->m_layout->count() - 1, item);
}

void HMemberView::removeItem(const QString &id)
{
    Q_D(HMemberView);

    HMemberItem *mem;
    for (int i = 0; i < d->m_layout->count(); i++) {
        QLayoutItem *item = d->m_layout->itemAt(i);
        if ((mem = dynamic_cast<HMemberItem *>(item->widget()))) {
            if (mem->getID() == id) {
                d->m_layout->removeItem(reinterpret_cast<QLayoutItem *>(mem));
                delete mem;
            }
        }
    }
}