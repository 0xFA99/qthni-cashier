#include "members/components/profiledialog.h"
#include "members/components/profiledialog_p.h"

#include <QVBoxLayout>

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
    m_currentAvatar->setSize(72);

    m_scrollArea    = new QScrollArea(q);
    m_profileList   = new QWidget(m_scrollArea);
    m_profileLayout = new QGridLayout(m_profileList);
    m_closeButton   = new QtMaterialFlatButton(q);

    m_scrollArea->setWidget(m_profileList);
    m_scrollArea->setWidgetResizable(true);
    m_scrollArea->setStyleSheet("background-color: transparent");
    m_scrollArea->setVerticalScrollBar(new QtMaterialScrollBar(m_scrollArea));

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

}