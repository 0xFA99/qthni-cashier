#include "hmemberedit.h"
#include "hmemberedit_p.h"

#include <QGridLayout>

#include "hmember.h"

HMemberEditPrivate::HMemberEditPrivate(HMemberEdit *q)
    : q_ptr(q)
{
}

HMemberEditPrivate::~HMemberEditPrivate()
{
}

void HMemberEditPrivate::init()
{
    Q_Q(HMemberEdit);

    m_layout        = new QGridLayout(q);

    m_avatar        = new HMaterialAvatar(QImage(":/images/images/default.png"), q);
    m_name          = new HMaterialTextField(q);
    m_id            = new HMaterialTextField(q);
    m_avatarButton  = new HMaterialFlatButton("\uE626", q);
    m_cancelButton  = new HMaterialFlatButton(q);
    m_submitButton  = new HMaterialFlatButton(q);
    m_mode          = HMemberEdit::Mode::AddMode;

    QFont font("iconfont", 12, QFont::Medium);
    m_avatarButton->setFont(font);
    m_avatarButton->setBackgroundColor(QColor("#f1f4f9"));
    m_avatarButton->setForegroundColor(QColor("#545557"));
    m_avatarButton->setFixedWidth(m_avatarButton->sizeHint().height());
    m_avatarButton->setCornerRadius(m_avatarButton->sizeHint().height() / 2);
    m_avatarButton->setHaloVisible(false);
    m_avatarButton->setBackgroundMode(Qt::OpaqueMode);

    m_avatar->setSize(112);

    m_name->setLabel("Member Name");
    m_id->setLabel("Member ID");

    m_cancelButton->setRippleStyle(HMaterial::NoRipple);
    m_cancelButton->setForegroundColor(QColor("#ff8296"));
    m_cancelButton->setText("Cancel");

    m_submitButton->setRippleStyle(HMaterial::NoRipple);
    m_submitButton->setForegroundColor(QColor("#657ef8"));
    m_submitButton->setText("Submit");

    QFrame *sp = new QFrame(q);
    sp->setMinimumHeight(50);

    m_layout->addWidget(m_avatar, 0, 0, 1, 2);
    m_layout->addWidget(m_avatarButton, 1, 0, 1, 2, Qt::AlignCenter);
    m_layout->addWidget(m_name, 2, 0, 1, 2);
    m_layout->addWidget(m_id, 3, 0, 1, 2);
    m_layout->addWidget(sp, 4, 0, 1, 2); 
    m_layout->addWidget(m_cancelButton, 5, 0, 1, 1);
    m_layout->addWidget(m_submitButton, 5, 1, 1, 1);

    QObject::connect(m_cancelButton, &QPushButton::clicked, q, &HMemberEdit::hideDialog);
    QObject::connect(m_submitButton, &QPushButton::clicked, q, &HMemberEdit::addSlot);
}

HMemberEdit::HMemberEdit(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HMemberEditPrivate(this))
{
    d_func()->init();
}

HMemberEdit::~HMemberEdit()
{
}

void HMemberEdit::addSlot() {
    Q_D(HMemberEdit);

    emit hideDialog();
    emit addSignal(
            d->m_avatar->getImage(),
            d->m_name->text(),
            d->m_id->text());

    // Back to default
    setEmptyField();
}

void HMemberEdit::editSlot()
{
    Q_D(HMemberEdit);

    emit hideDialog();

    d->m_editMember->setAvatar(d->m_avatar->getImage());
    d->m_editMember->setName(d->m_name->text());
    d->m_editMember->setID(d->m_id->text());

    // emit editSignal(d->m_editMember);

    emit d->m_editMember->updateSlot();

    setEmptyField();
}

void HMemberEdit::setMode(HMemberEdit::Mode mode)
{
    Q_D(HMemberEdit);

    if (d->m_mode != mode) {
        if (mode == Mode::AddMode) {
            d->m_mode = Mode::AddMode;
            addMode();
        } else {
            d->m_mode = Mode::EditMode;
            editMode();
        }
    }
}

void HMemberEdit::addMode()
{
    Q_D(HMemberEdit);

    // QObject::disconnect(d->m_submitButton, &QPushButton::clicked, this, &HMemberEdit::editSlot);
    // QObject::disconnect(d->m_submitButton, &QPushButton::clicked, d->m_editMember, &HMember::editSlot);
    // QObject::connect(d->m_submitButton, &QPushButton::clicked, this, &HMemberEdit::addSlot);

    QObject::disconnect(d->m_submitButton, &QPushButton::clicked, this, &HMemberEdit::editSlot);
    QObject::connect(d->m_submitButton, &QPushButton::clicked, this, &HMemberEdit::addSlot);
}

void HMemberEdit::editMode()
{
    Q_D(HMemberEdit);

    /*
    QObject::disconnect(d->m_submitButton, &QPushButton::clicked, this, &HMemberEdit::addSlot);
    QObject::connect(d->m_submitButton, &QPushButton::clicked, this, &HMemberEdit::editSlot);
    QObject::connect(d->m_submitButton, &QPushButton::clicked, d->m_editMember, &HMember::editSlot);
    */
    QObject::disconnect(d->m_submitButton, &QPushButton::clicked, this, &HMemberEdit::addSlot);
    QObject::connect(d->m_submitButton, &QPushButton::clicked, this, &HMemberEdit::editSlot);
}

void HMemberEdit::setEmptyField()
{
    Q_D(HMemberEdit);

    d->m_avatar->setImage(QImage(":/images/images/default.png"));
    d->m_name->clear();
    d->m_id->clear();
}

void HMemberEdit::setTargetMember(HMember *member)
{
    Q_D(HMemberEdit);

    d->m_editMember = member;

    d->m_avatar->setImage(member->avatar());
    d->m_name->setText(member->name());
    d->m_id->setText(member->id());
}