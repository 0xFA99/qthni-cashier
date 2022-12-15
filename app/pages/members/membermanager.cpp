#include "members/membermanager.h"
#include "members/membermanager_p.h"

#include "members/member.h"

MemberManagerPrivate::MemberManagerPrivate(MemberManager *q)
    : q_ptr(q)
{
}

MemberManagerPrivate::~MemberManagerPrivate() = default;

void MemberManagerPrivate::init()
{
    Q_Q(MemberManager);

    m_memberList = QVector<Member *>();
}

MemberManager::MemberManager(QObject *parent)
    : QObject(parent)
    , d_ptr(new MemberManagerPrivate(this))
{
    d_func()->init();
}

MemberManager::~MemberManager() = default;

void MemberManager::addMember(Member *member)
{
    Q_D(MemberManager);

    member->setParent(this);
    d->m_memberList.push_back(member);
}

void MemberManager::updateMember(int index, Member *member)
{
    Q_D(MemberManager);

    Member *updatedMember;
    updatedMember = d->m_memberList.at(index);

    updatedMember->setName(member->name());
    updatedMember->setID(member->id());
}

void MemberManager::deleteMember(int index)
{
    Q_D(MemberManager);

    Member *deleteMember;
    deleteMember = d->m_memberList.at(index);

    d->m_memberList.removeAt(index);
    delete deleteMember;
}

QString MemberManager::getMemberName(int index) const
{
    Q_D(const MemberManager);

    return d->m_memberList.at(index)->name();
}

QString MemberManager::getMemberID(int index) const
{
    Q_D(const MemberManager);

    return d->m_memberList.at(index)->id();
}

int MemberManager::lastItemIndex() const
{
    Q_D(const MemberManager);

    return d->m_memberList.size();
}

Member *MemberManager::getMember(int index)
{
    Q_D(MemberManager);

    return d->m_memberList.at(index);
}