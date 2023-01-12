#include "members/MemberObjectManager.h"
#include "members/MemberObjectManager_p.h"

#include "members/MemberObject.h"

#include "database/HNIDatabase.h"

#include <QImage>
#include <QUuid>
#include <QDebug>

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

/*
int MemberObjectManager::lastItemIndex() const
{
    Q_D(const MemberObjectManager);

    return d->m_memberList.size();
}
*/

void MemberObjectManager::addMember(MemberObject *member_object)
{
    Q_D(MemberObjectManager);

    member_object->setParent(this);
    d->m_memberList.push_back(member_object);
}

MemberObject*
MemberObjectManager::getMemberObject(const QUuid &uuid)
{
    Q_D(static MemberObjectManager);

    MemberObject *member;
    for (MemberObject *mem : d->m_memberList) {
        if (mem->uuid() == uuid) {
            member = mem;
        }
    }

    return member;
}

void
MemberObjectManager::updateMember(QUuid uuid, MemberObject& member)
{
    Q_D(MemberObjectManager);

    for (MemberObject *mem : d->m_memberList) {
        if (mem->uuid() == uuid) {
            mem->editMember(member);
            mem->Update();

            HNIDatabase::updateMember(uuid, member);

            break;
        }
    }
}

void
MemberObjectManager::deleteMember(QUuid uuid)
{
    Q_D(MemberObjectManager);

    for (MemberObject *mem : d->m_memberList) {
        if (mem->uuid() == uuid) {
            d->m_memberList.removeOne(mem);
            mem->deleteLater();

            HNIDatabase::deleteMember(uuid);

            break;
        }
    }
}