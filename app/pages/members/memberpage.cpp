#include "members/memberpage.h"
#include "members/memberpage_p.h"

#include <QHBoxLayout>

#include "members/member.h"
#include "members/MemberObject.h"
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
    m_memberManager         = new MemberManager(q);
    m_memberListTitle       = new FrameTitle(q);
    m_memberList            = new MemberList(q);
    m_memberScrollArea      = new QScrollArea(q);
    m_memberDialog          = new QtMaterialDialog;
    m_memberDialogWidget    = new MemberDialog(q);
    m_profileDialog         = new QtMaterialDialog;
    m_profileDialogWidget   = new ProfileDialog(q);

    m_snackBar              = new QtMaterialSnackbar;
    m_fabButton             = new QtMaterialFloatingActionButton(QtMaterialTheme::icon("content", "add"), q);

    m_member_object_manager = new MemberObjectManager(q);

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

    /*
    QObject::connect(m_memberDialogWidget, &MemberDialog::addedMember,
                     q, &MemberPage::addingMember);

    QObject::connect(m_memberDialogWidget, &MemberDialog::editedMember,
                     q, &MemberPage::updateMember);

                     */
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

MemberPage::MemberPage(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new MemberPagePrivate(this))
{
    d_func()->init();
}

MemberPage::~MemberPage() = default;

void MemberPage::addingMember(Member *member)
{
    Q_D(MemberPage);

    /*
    auto newMember = new Member;
    newMember->setImage(member->image());
    newMember->setName(member->name());
    newMember->setID(member->id());
    d->m_memberManager->addMember(newMember);
     */

    /*
     * Adding Member to Member Manager
     */
    auto newMemberObject = new MemberObject;
    newMemberObject->setImage(member->image());
    newMemberObject->setName(member->name());
    newMemberObject->setID(member->id());

    d->m_member_object_manager->addMember(newMemberObject);

    /*
    auto newItemMember = new OperateItem(d->m_memberManager->lastItemIndex() - 1);
    newItemMember->setImage(member->image());
    newItemMember->setTitle(member->name());
    newItemMember->setSubTitle(member->id());
     */
    /*
     * Make Item for Member
     */
    auto newItemManager = new OperateItem;
    newItemManager->setImage(member->image());
    newItemManager->setTitle(member->name());
    newItemManager->setSubTitle(member->id());


    /*
    QObject::connect(newItemMember, &OperateItem::editItem,
                     this, &MemberPage::editMember);

    QObject::connect(newItemMember, &OperateItem::deleteItem,
                     this, &MemberPage::deleteMember);

    d->m_memberList->addMemberItem(newItemMember);
     */

    d->m_snackBar->addMessage(QString("Berhasil Menambahkan Member"));
}

void MemberPage::editMember(int index)
{
    Q_D(MemberPage);

    d->m_memberDialogWidget->setMode(MemberDialog::Edit);

    Member *tempMember = d->m_memberManager->getMember(index);

    d->m_memberDialogWidget->setImageField(tempMember->image());
    d->m_memberDialogWidget->setNameField(tempMember->name());
    d->m_memberDialogWidget->setIDField(tempMember->id());
    d->m_memberDialogWidget->setIndex(index);

    d->m_memberDialog->showDialog();
}

void MemberPage::updateMember(int index, Member *member)
{
    Q_D(MemberPage);

    d->m_memberManager->updateMember(index, member);
    // d->m_memberList->updateMemberItem(index, member);

    d->m_snackBar->addMessage(QString("Berhasil Mengedit Member"));
}

void MemberPage::deleteMember(int index)
{
    Q_D(MemberPage);

    d->m_memberList->deleteMemberItem(index);
    d->m_memberManager->deleteMember(index);

    d->m_snackBar->addInstantMessage(QString("Berhasil Menghapus Member"));
}