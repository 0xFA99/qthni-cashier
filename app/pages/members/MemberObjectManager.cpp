#include "members/MemberObjectManager.h"
#include "members/MemberObjectManager_p.h"

#include "members/MemberObject.h"

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

void MemberObjectManager::addMember(MemberObject *member_object)
{
    Q_D(MemberObjectManager);

    member_object->setParent(this);
    d->m_memberList.push_back(member_object);
}