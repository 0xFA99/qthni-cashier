#include "members/memberpage.h"
#include "members/memberpage_p.h"

#include <QHBoxLayout>

#include "members/MemberObject.h"
#include "members/MemberObjectManager.h"
#include "widgets/items/OperateItem.h"

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

void MemberPage::addingMember(MemberObject *member)
{
    Q_D(MemberPage);

    auto newMemberObject = new MemberObject;    // As Subject
    newMemberObject->editMember(member);
    d->m_memberManager->addMember(newMemberObject);

    auto newItemManager = new OperateItem;      // As Observer
    newItemManager->setImage(member->image());
    newItemManager->setTitle(member->name());
    newItemManager->setSubTitle(member->id());
    newItemManager->setIndex(d->m_memberManager->lastItemIndex() - 1);

    QObject::connect(newItemManager, &OperateItem::s_editButton, this, &MemberPage::editMember);
    QObject::connect(newItemManager, &OperateItem::s_deleteButton, this, &MemberPage::deleteMember);

    newMemberObject->Attach(newItemManager);    // Subject Attach Observer
    d->m_memberList->addMemberItem(newItemManager);

    d->m_snackBar->addMessage(QString("Berhasil Menambahkan Member"));
}

void MemberPage::editMember(int index)
{
    Q_D(MemberPage);

    d->m_memberDialogWidget->setMode(MemberDialog::Edit);

    MemberObject *member_object = d->m_memberManager->getMemberObject(index);

    d->m_memberDialogWidget->setImageField(member_object->image());
    d->m_memberDialogWidget->setNameField(member_object->name());
    d->m_memberDialogWidget->setIDField(member_object->id());
    d->m_memberDialogWidget->setIndex(index);

    d->m_memberDialog->showDialog();
}
void MemberPage::updateMember(int index, MemberObject* member)
{
    Q_D(MemberPage);

    d->m_memberManager->updateMember(index, member);

    d->m_snackBar->addInstantMessage(QString("Berhasil Mengedit Member"));
}

void MemberPage::deleteMember(int index)
{
    Q_D(MemberPage);

    d->m_memberManager->deleteMember(index);
    d->m_memberList->deleteMemberItem(index);

    d->m_snackBar->addInstantMessage(QString("Berhasil Menghapus Member"));
}

void MemberPage::addMemberManager(MemberObjectManager *manager)
{
    Q_D(MemberPage);

    d->m_memberManager = manager;
}