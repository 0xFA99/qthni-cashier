#include "members/memberpage.h"
#include "members/memberpage_p.h"

#include <QHBoxLayout>
#include <QUuid>
#include <QDebug>

#include "members/MemberObject.h"
#include "members/MemberObjectManager.h"
#include "widgets/items/OperateItem.h"
#include "database/HNIDatabase.h"

MemberPagePrivate::MemberPagePrivate(MemberPage *q)
    : q_ptr(q)
{
}

MemberPagePrivate::~MemberPagePrivate() = default;

void MemberPagePrivate::init()
{
    Q_Q(MemberPage);

    m_layout                = new QHBoxLayout(q);
    m_memberListTitle       = new FrameTitle(q);
    m_memberList            = new MemberList(q);
    m_memberScrollArea      = new QScrollArea(q);
    m_memberDialog          = new QtMaterialDialog;
    m_memberDialogWidget    = new MemberDialog(q);
    m_profileDialog         = new QtMaterialDialog;
    m_profileDialogWidget   = new ProfileDialog(q);

    m_snackBar              = new QtMaterialSnackbar;
    m_fabButton             = new QtMaterialFloatingActionButton(QtMaterialTheme::icon("content", "add"), q);

    m_snackBar->setParent(q);

    m_fabButton->setHaloVisible(false);
    m_fabButton->setRippleStyle(Material::NoRipple);

    // START - CONFIG MEMBER DIALOG
    auto *dialogLayout = new QVBoxLayout;

    m_memberDialog->setParent(q);
    m_memberDialog->setWindowLayout(dialogLayout);

    dialogLayout->addWidget(m_memberDialogWidget);

    QObject::connect(m_fabButton, &QPushButton::clicked, [=]() {
        m_memberDialogWidget->setMode(MemberDialog::Mode::Add);
        m_memberDialog->showDialog();
    });

    QObject::connect(m_memberDialogWidget, &MemberDialog::closedMemberDialog,
                     m_memberDialog, &QtMaterialDialog::hideDialog);

    QObject::connect(m_memberDialogWidget, &MemberDialog::addedMember,
                     q, &MemberPage::addingMember);

    QObject::connect(m_memberDialogWidget, &MemberDialog::editedMember,
                     q, &MemberPage::updateMember);

    // END
    // START PROFILE DIALOG
    auto *profileLayout = new QVBoxLayout;

    m_profileDialog->setParent(q);
    m_profileDialog->setWindowLayout(profileLayout);

    profileLayout->addWidget(m_profileDialogWidget);

    QObject::connect(m_memberDialogWidget, &MemberDialog::showProfileDialog, [=]() {
        m_profileDialog->showDialog();
    });

    QObject::connect(m_profileDialogWidget, &ProfileDialog::closedProfileDialog, [=]() {
        m_profileDialog->hideDialog();
    });
    // END
    QFont font("Roboto", 12, QFont::Medium);

    m_memberScrollArea->setWidget(m_memberList);
    m_memberScrollArea->setWidgetResizable(true);
    m_memberScrollArea->setStyleSheet("background-color: transparent");
    m_memberScrollArea->setVerticalScrollBar(new QtMaterialScrollBar(m_memberScrollArea));
    m_memberScrollArea->setHorizontalScrollBar(new QtMaterialScrollBar(m_memberScrollArea));

    m_memberListTitle->setFont(font);
    m_memberListTitle->setTitleColor(QRgb(0x1f1f1f));
    m_memberListTitle->setTitle("Daftar Member");
    m_memberListTitle->addChildWidget(m_memberScrollArea);

    m_layout->addWidget(m_memberListTitle);
}

MemberPage::MemberPage(MemberObjectManager *manager, QWidget *parent)
    : QWidget(parent)
    , d_ptr(new MemberPagePrivate(this))
{
    d_func()->init();

    addMemberManager(manager);
}

MemberPage::~MemberPage() = default;

void MemberPage::addingMember(MemberObject& member)
{
    Q_D(MemberPage);

    addMemberToManager(member);
    addMemberToDB(member);

    d->m_snackBar->addInstantMessage(QString("Berhasil Menambahkan Member"));
}

void MemberPage::editMember(QUuid uuid)
{
    Q_D(MemberPage);

    d->m_memberDialogWidget->setMode(MemberDialog::Edit);

    d->m_memberDialogWidget->setMemberFromUUID(uuid);

    d->m_memberDialog->showDialog();
}
void MemberPage::updateMember(QUuid uuid, MemberObject& member)
{
    Q_D(MemberPage);

    d->m_memberManager->updateMember(uuid, member);

    d->m_snackBar->addInstantMessage(QString("Berhasil Mengedit Member"));
}

void MemberPage::deleteMember(QUuid uuid)
{
    Q_D(MemberPage);

    d->m_memberManager->deleteMember(uuid);
    d->m_memberList->deleteMemberItem(uuid);

    d->m_snackBar->addInstantMessage(QString("Berhasil Menghapus Member"));
}

void MemberPage::addMemberManager(MemberObjectManager *manager)
{
    Q_D(MemberPage);

    d->m_memberManager = manager;
    d->m_memberDialogWidget->addMemberManager(d->m_memberManager);
}

void MemberPage::addMemberToManager(MemberObject &member)
{
    Q_D(MemberPage);

    auto newMemberObject = new MemberObject;
    newMemberObject->editMember(member);
    newMemberObject->setUUID(member.uuid());

    d->m_memberManager->addMember(newMemberObject);

    addMemberToItemList(newMemberObject);
}

void MemberPage::addMemberToItemList(MemberObject *member)
{
    Q_D(MemberPage);

    auto newItemMember = new OperateItem(*member);
    newItemMember->setUUID(member->uuid());
    newItemMember->setImage(member->image());
    newItemMember->setTitle(member->name());
    newItemMember->setSubTitle(member->id());

    QObject::connect(newItemMember, &OperateItem::s_editButton, this, &MemberPage::editMember);
    QObject::connect(newItemMember, &OperateItem::s_deleteButton, this, &MemberPage::deleteMember);

    // member->Attach(newItemMember);

    d->m_memberList->addMemberItem(newItemMember);
}

void MemberPage::addMemberToDB(MemberObject &member)
{
    Q_D(MemberPage);

    if (HNIDatabase::addMember(member)) {
        qDebug() << "DB - Success - Insert Member " << member.name();
    } else {
        qDebug() << "DB - Error - Insert Member" << member.name();
    }
}

void MemberPage::syncMemberFromDB()
{
    QVector<MemberObject *> getAllMember = HNIDatabase::getAllMember();
    for (auto i : getAllMember) {
        MemberObject loadMember;
        loadMember.setUUID(i->uuid());
        loadMember.setImage(i->image());
        loadMember.setName(i->name());
        loadMember.setID(i->id());

        delete i;

        addMemberToManager(loadMember);
    }
}