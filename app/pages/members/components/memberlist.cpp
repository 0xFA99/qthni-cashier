#include "members/components/memberlist.h"
#include "members/components/memberlist_p.h"

#include <QVBoxLayout>

#include "widgets/items/operateitem.h"

MemberListPrivate::MemberListPrivate(MemberList *q)
    : q_ptr(q)
{
}

MemberListPrivate::~MemberListPrivate() = default;

void MemberListPrivate::init()
{
    Q_Q(MemberList);

    m_layout    = new QVBoxLayout(q);

    m_layout->addStretch(1);
    m_layout->setContentsMargins(0, 0, 0, 0);
}

MemberList::MemberList(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new MemberListPrivate(this))
{
    d_func()->init();

    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
}

MemberList::~MemberList() = default;

void MemberList::addMemberItem(OperateItem *item)
{
    Q_D(MemberList);

    item->setParent(this);
    d->m_layout->insertWidget(d->m_layout->count() - 1, item);
}

void MemberList::updateMemberItem(int index, Member *member)
{
    Q_D(MemberList);

    QLayoutItem *item = d->m_layout->itemAt(index);
    auto mem = dynamic_cast<OperateItem *>(item->widget());
    mem->setTitle(member->name());
    mem->setSubTitle(member->id());
}

void MemberList::deleteMemberItem(int index)
{
    Q_D(MemberList);

    OperateItem *item;
    for (int i = 0; i < d->m_layout->count(); i++) {
        QLayoutItem *litem = d->m_layout->itemAt(i);

        if (i > index && (item = dynamic_cast<OperateItem *>(litem->widget()))) {
            item->setIndex(item->getIndex() - 1);
        }
    }

    QLayoutItem *litem = d->m_layout->itemAt(index);
    if ((item = dynamic_cast<OperateItem *>(litem->widget()))) {
        delete item;
    }
}

// 0 1 2 3 4