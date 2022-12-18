#include "members/components/profiledialog.h"
#include "members/components/profiledialog_p.h"

#include <QVBoxLayout>

#include "purchase/components/flowlayout.h"

#include "qtmaterial/components/qtmaterialscrollbar.h"
#include "qtmaterial/components/qtmaterialavatar.h"

ProfileDialogPrivate::ProfileDialogPrivate(ProfileDialog *q)
    : q_ptr(q)
{
}

ProfileDialogPrivate::~ProfileDialogPrivate() = default;

void ProfileDialogPrivate::init()
{
    Q_Q(ProfileDialog);

    m_layout        = new QVBoxLayout(q);
    m_frontWidget   = new QWidget(q);
    m_frontLayout   = new QVBoxLayout(m_frontWidget);

    m_currentAvatar = new QtMaterialAvatar(q);
    m_currentAvatar->setSize(112);

    m_scrollArea    = new QScrollArea(q);
    m_profileList   = new QWidget(m_scrollArea);
    m_profileLayout = new FlowLayout(m_profileList, 10, -1, -1);
    m_closeButton   = new QtMaterialFlatButton("PILIH", q);

    m_layout->setSpacing(16);

    m_scrollArea->setWidget(m_profileList);
    m_scrollArea->setWidgetResizable(true);
    m_scrollArea->setStyleSheet("background-color: transparent");
    m_scrollArea->setVerticalScrollBar(new QtMaterialScrollBar(m_scrollArea));

    m_closeButton->setRole(Material::Role::Primary);

    m_layout->addWidget(m_currentAvatar);
    m_layout->addWidget(m_scrollArea);
    m_layout->addWidget(m_closeButton);

    QObject::connect(m_closeButton, &QPushButton::clicked, [q]() {
        emit q->closedProfileDialog();
    });
}

ProfileDialog::ProfileDialog(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new ProfileDialogPrivate(this))
{
    d_func()->init();
    initImagePack();
}

ProfileDialog::~ProfileDialog() = default;

void ProfileDialog::initImagePack()
{
    Q_D(ProfileDialog);

    for (int i = 1; i <= 20; i++) {
        auto newAvatar = new QtMaterialAvatar(this);
        newAvatar->setImage(QImage(":/images/images/profiles/avatar" + QString::number(i)));
        newAvatar->setSize(72);
        d->m_profileLayout->addWidget(newAvatar);
    }
}