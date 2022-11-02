#include "hmemberlist.h"
#include "hmemberlist_internal.h"

#include <QVBoxLayout>
#include <QPainter>

HMember::HMember(QWidget *parent)
    : QWidget(parent)
{
    m_layout        = new QGridLayout(this);
    m_avatar        = new HMaterialAvatar(this);
    m_name          = new HMaterialLabel("Unknown", this);
    m_id            = new HMaterialLabel("No ID", this);
    m_buttonEdit    = new HMaterialFlatButton(this);
    m_buttonDelete  = new HMaterialFlatButton(this);

    m_avatar->setImage(QImage(":/images/images/profile.png"));
    m_avatar->setSize(48);
    m_avatar->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);

    m_name->setAlignment(Qt::AlignBottom);

    m_id->setAlignment(Qt::AlignTop);
    m_id->setTextColor(QColor("#969cf2"));

    m_buttonEdit->setFont(QFont("iconfont", 16, QFont::Medium));
    m_buttonEdit->setText("\uE65C");
    m_buttonEdit->setForegroundColor(QColor("#ff9b36"));
    m_buttonEdit->setHaloVisible(false);
    m_buttonEdit->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    m_buttonEdit->setCornerRadius(m_buttonEdit->sizeHint().height() / 2);

    m_buttonDelete->setFont(QFont("iconfont", 16, QFont::Medium));
    m_buttonDelete->setText("\uE652");
    m_buttonDelete->setForegroundColor(QColor("#ff8296"));
    m_buttonDelete->setHaloVisible(false);
    m_buttonDelete->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    m_buttonDelete->setCornerRadius(m_buttonDelete->sizeHint().height() / 2);

    m_layout->addWidget(m_avatar, 0, 0, 2, 1);
    m_layout->addWidget(m_name, 0, 1, 1, 1);
    m_layout->addWidget(m_id, 1, 1, 1, 1);
    m_layout->addWidget(m_buttonEdit, 0, 2, 2, 1);
    m_layout->addWidget(m_buttonDelete, 0, 3, 2, 1);
    m_layout->setContentsMargins(0, 0, 0, 0);
}

HMember::~HMember()
{
}

HMemberListItem::HMemberListItem(HMemberList *parent)
    : QWidget(parent)
    , m_memberList(parent)
{
    m_layout = new QVBoxLayout(this);
    m_layout->setContentsMargins(0, 16, 0, 0);
    m_layout->addStretch(1);
    m_haveMember = false;

    addMember();
    addMember();
}

HMemberListItem::~HMemberListItem()
{
}

void HMemberListItem::addMember()
{
    if (m_haveMember != true)
        m_haveMember = true;

    HMember *newMember = new HMember(this);
    // HMaterialLabel  *avatar = new HMaterialLabel("Example", this);

    m_layout->insertWidget(m_layout->count() - 1, newMember);
    update();
}

void HMemberListItem::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    if (!m_haveMember) {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setPen(QColor(0, 0, 0, 115));
        painter.setFont(QFont("Roboto", 12, QFont::Medium));

        const int z = (24 / 1.33);
        const int x = (rect().width() - size().width()) / 2;
        int y = ((rect().height() - size().height()) / 2) + z;

        QRect textGeometry(x, y, size().width(), size().height());
        painter.drawText(textGeometry, Qt::AlignCenter, "No Member Added");

        painter.setFont(QFont("iconfont", 24, QFont::Medium));
        y = ((rect().height() - size().height()) / 2) - z;

        textGeometry = QRect(x, y, size().width(), size().height());
        painter.drawText(textGeometry, Qt::AlignCenter, "\uE652");
    }
}
