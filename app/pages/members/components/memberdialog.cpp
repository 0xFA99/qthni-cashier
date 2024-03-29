#include "members/components/memberdialog.h"
#include "members/components/memberdialog_p.h"

#include <QGridLayout>
#include <QDebug>

#include "members/MemberObject.h"
#include "members/MemberObjectManager.h"

MemberDialogPrivate::MemberDialogPrivate(MemberDialog *q)
    : q_ptr(q)
{
}

MemberDialogPrivate::~MemberDialogPrivate() = default;

void MemberDialogPrivate::init()
{
    Q_Q(MemberDialog);

    m_layout                = new QGridLayout(q);
    m_avatar                = new QtMaterialAvatar(q);
    m_changeAvatarButton    = new QtMaterialIconButton(QtMaterialTheme::icon("image", "add_a_photo"), q);
    m_nameField             = new QtMaterialTextField(q);
    m_idField               = new QtMaterialTextField(q);
    m_closeButton           = new QtMaterialFlatButton("CLOSE", q);
    m_submitButton          = new QtMaterialFlatButton("SUBMIT", q);
    m_mode                  = MemberDialog::Mode::Add;

    m_avatar->setImage(QImage(":/images/images/profiles/defaultimage.png"));
    m_avatar->setSize(72);

    m_changeAvatarButton->setColor(QRgb(0x8a8a8a));

    QFont font("Roboto", 12, QFont::Normal);
    font.setPixelSize(16);
    m_nameField->setFont(font);
    m_nameField->setLabel("Nama Member");

    m_idField->setFont(font);
    m_idField->setLabel("ID Member");

    m_closeButton->setHaloVisible(false);
    m_closeButton->setRole(Material::Secondary);
    m_closeButton->setRippleStyle(Material::NoRipple);
    m_closeButton->setOverlayStyle(Material::TintedOverlay);

    m_submitButton->setHaloVisible(false);
    m_submitButton->setRole(Material::Primary);
    m_submitButton->setRippleStyle(Material::NoRipple);
    m_submitButton->setOverlayStyle(Material::TintedOverlay);

    m_layout->addWidget(m_avatar, 0, 0, 1, 2);
    m_layout->addWidget(m_changeAvatarButton, 1, 0, 1, 2, Qt::AlignCenter);
    m_layout->addWidget(m_nameField, 2, 0, 1, 2);
    m_layout->addWidget(m_idField, 3, 0, 1, 2);
    m_layout->addWidget(m_closeButton, 4, 0, 1, 1);
    m_layout->addWidget(m_submitButton, 4, 1, 1, 1);
    m_layout->setSpacing(18);

    QObject::connect(m_closeButton, &QPushButton::clicked, [q]() {
        emit q->closedMemberDialog();
    });

    QObject::connect(m_submitButton, &QPushButton::clicked,
                     q, &MemberDialog::addSlot);

    QObject::connect(m_changeAvatarButton, &QPushButton::clicked, [q]() {
        emit q->showProfileDialog();
    });
}

MemberDialog::MemberDialog(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new MemberDialogPrivate(this))
{
    d_func()->init();
}

MemberDialog::~MemberDialog() = default;

void MemberDialog::clearField()
{
    Q_D(MemberDialog);

    d->m_nameField->clear();
    d->m_idField->clear();
}

void MemberDialog::addSlot()
{
    Q_D(MemberDialog);

    MemberObject newMember;

    QUuid newUUID = QUuid::createUuid();
    qDebug() << "App - Success - Create new Member UUID: " << newUUID;

    newMember.setUUID(newUUID);
    newMember.setImage(d->m_avatar->image());
    newMember.setName(d->m_nameField->text());
    newMember.setID(d->m_idField->text());

    addedMember(newMember);

    closedMemberDialog();
    clearField();
}

void MemberDialog::editSlot()
{
    Q_D(MemberDialog);

    MemberObject tempMember;
    tempMember.setImage(d->m_avatar->image());
    tempMember.setName(d->m_nameField->text());
    tempMember.setID(d->m_idField->text());

    editedMember(d->m_uuid, tempMember);
    closedMemberDialog();
    clearField();
}

void MemberDialog::setMode(MemberDialog::Mode mode)
{
    Q_D(MemberDialog);

    if (d->m_mode != mode) {
        if (mode == Mode::Add) {
            d->m_mode = Mode::Add;
            addMode();
        } else {
            d->m_mode = Mode::Edit;
            editMode();
        }
    }
}

void MemberDialog::addMode()
{
    Q_D(MemberDialog);

    QObject::disconnect(d->m_submitButton, &QPushButton::clicked,
                        this, &MemberDialog::editSlot);
    QObject::connect(d->m_submitButton, &QPushButton::clicked,
                     this, &MemberDialog::addSlot);
}

void MemberDialog::editMode()
{
    Q_D(MemberDialog);

    QObject::disconnect(d->m_submitButton, &QPushButton::clicked,
                        this, &MemberDialog::addSlot);
    QObject::connect(d->m_submitButton, &QPushButton::clicked,
                     this, &MemberDialog::editSlot);
}

/*
void MemberDialog::setImageField(const QImage &image)
{
    Q_D(MemberDialog);

    d->m_avatar->setImage(image);
}

void MemberDialog::setNameField(const QString &name)
{
    Q_D(MemberDialog);

    d->m_nameField->setText(name);
}

void MemberDialog::setIDField(const QString &id)
{
    Q_D(MemberDialog);

    d->m_idField->setText(id);
}

void MemberDialog::setIndex(int index)
{
    Q_D(MemberDialog);

    d->m_index = index;
}
*/

void MemberDialog::setMemberFromUUID(QUuid uuid)
{
    Q_D(MemberDialog);

    d->m_uuid = uuid;

    MemberObject *member = d->m_memberManager->getMemberObject(uuid);

    d->m_avatar->setImage(member->image());
    d->m_nameField->setText(member->name());
    d->m_idField->setText(member->id());
}

void MemberDialog::addMemberManager(MemberObjectManager* manager)
{
    Q_D(MemberDialog);

    d->m_memberManager = manager;
}