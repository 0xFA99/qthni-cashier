#include "members/MemberObjectManager.h"
#include "members/MemberObjectManager_p.h"

#include "members/MemberObject.h"

#include <QImage>

MemberObjectManagerPrivate::MemberObjectManagerPrivate(MemberObjectManager *q)
    : q_ptr(q)
{
}

MemberObjectManagerPrivate::~MemberObjectManagerPrivate() = default;

void MemberObjectManagerPrivate::init()
{
    Q_Q(MemberObjectManager);

    m_memberList    = QVector<MemberObject *>();
}

MemberObjectManager::MemberObjectManager(QObject *parent)
    : QObject(parent)
    , d_ptr(new MemberObjectManagerPrivate(this))
{
    d_func()->init();
}

MemberObjectManager::~MemberObjectManager() = default;

int MemberObjectManager::lastItemIndex() const
{
    Q_D(const MemberObjectManager);

    return d->m_memberList.size();
}

void MemberObjectManager::addMember(MemberObject *member_object)
{
    Q_D(MemberObjectManager);

    member_object->setParent(this);
    d->m_memberList.push_back(member_object);
}

MemberObject*
MemberObjectManager::getMemberObject(int index)
{
    Q_D(MemberObjectManager);

    return d->m_memberList.at(index);
}

void
MemberObjectManager::updateMember(int index, MemberObject *member)
{
    Q_D(MemberObjectManager);

    MemberObject *updateMember = d->m_memberList.at(index);

    updateMember->setImage(member->image());
    updateMember->setName(member->name());
    updateMember->setID(member->id());

    updateMember->Update();
}

void
MemberObjectManager::deleteMember(int index)
{
    Q_D(MemberObjectManager);

    MemberObject *deleteMember = d->m_memberList.at(index);

    d->m_memberList.removeAt(index);
    delete deleteMember;
}