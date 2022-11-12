#include "hmemberlist.h"
#include "hmemberlist_p.h"

#include <QPainter>
#include <QPainterPath>
#include <QGridLayout>

#include "hmember.h"
#include "hmemberitem.h"
#include "hmemberview.h"

HMemberListPrivate::HMemberListPrivate(HMemberList *q)
    : q_ptr(q)
{
}

HMemberListPrivate::~HMemberListPrivate()
= default;

void HMemberListPrivate::HMemberListPrivate::init()
{
    Q_Q(HMemberList);

    m_layout        = new QGridLayout(q);
    m_title         = new HMaterialLabel("Member List", q);
    m_gridButton    = new HMaterialFlatButton("\uE62A", q);
    m_vertButton    = new HMaterialFlatButton("\uE622", q);
    m_fabButton     = new HMaterialFloatingActionButton(HMaterialTheme::icon("toggle", "star"));
    m_scrollArea    = new QScrollArea(q);
    m_dialog        = new HMaterialDialog;
    m_dialogLayout  = new QVBoxLayout;
    m_memberDialog  = new HMemberEdit(q);
    m_memberView    = new HMemberView(q);

    // Dialog Configuration
    m_dialog->setParent(q);
    m_dialog->setWindowLayout(m_dialogLayout);
    m_dialogLayout->addWidget(m_memberDialog);

    // Bottom Widget (Scroll Member item)
    m_scrollArea->setWidget(m_memberView);
    m_scrollArea->setWidgetResizable(true);
    m_scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_scrollArea->setFrameShape(QFrame::NoFrame);

    // Add Member Button
    m_fabButton->setParent(m_scrollArea);
    m_fabButton->setHaloVisible(false);
    m_fabButton->setRippleStyle(HMaterial::NoRipple);
    // QObject::connect(m_fabButton, &QPushButton::clicked, m_memberView, &HMemberView::memberAdd);

    m_title->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);

    QFont font("iconfont", 12, QFont::Bold);
    m_gridButton->setFont(font);
    m_vertButton->setFont(font);

    m_layout->addWidget(m_title, 0, 0, 1, 1);
    m_layout->addWidget(m_gridButton, 0, 1, 1, 1);
    m_layout->addWidget(m_vertButton, 0, 2, 1, 1);
    m_layout->addWidget(m_scrollArea, 1, 0, 1, 3);

    m_layout->setContentsMargins(16, 10, 16, 10);
}

HMemberList::HMemberList(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HMemberListPrivate(this))
{
    d_func()->init();

    syncMemberDB();
    performConnection();
}

HMemberList::~HMemberList()
= default;

void HMemberList::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);

    QPainterPath path;
    path.addRoundedRect(rect(), 16, 16);

    QPainter painter(this);
    painter.setClipPath(path);
    painter.setClipping(true);
    painter.setOpacity(1);
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);
    painter.drawRect(rect());

    QRect line(16, 46, rect().width() - 32, 1);
    painter.fillRect(line, QColor("#f1f4f9"));
}

void HMemberList::performConnection()
{
    Q_D(HMemberList);

    // Show Empty Dialog
    QObject::connect(d->m_fabButton, &QPushButton::clicked, [=]() -> void {
        d->m_memberDialog->setMode(HMemberEdit::Mode::AddMode);
        d->m_dialog->showDialog();
    });

    // Hide Dialog(Submit)
    QObject::connect(d->m_memberDialog, &HMemberEdit::hideDialog,
                     d->m_dialog, &HMaterialDialog::hideDialog);

    // Add Member(Submit)
    QObject::connect(d->m_memberDialog, &HMemberEdit::addSignal,
                     this, &HMemberList::addMember);
}

void HMemberList::syncMemberDB()
{
    Q_D(HMemberList);

    HMember *newMember = new HMember(this);
    newMember->setAvatar(QImage(":/images/images/default.png"));
    newMember->setName(QString("Margaretha"));
    newMember->setID(QString("123456789"));

    d->m_memberList.push_back(newMember);

    HMemberItem *newItem = new HMemberItem(newMember, d->m_memberView);

    QObject::connect(
            newItem, &HMemberItem::removeItem,
            d->m_memberView, &HMemberView::removeItem);
    QObject::connect(
            newItem, &HMemberItem::editItem,
            this, &HMemberList::editMember);

    d->m_memberView->addItem(newItem);
}

void HMemberList::addMember(const QImage &image, const QString &name, const QString &id)
{
    Q_D(HMemberList);

    HMember *newMember = new HMember(this);
    newMember->setAvatar(image);
    newMember->setName(name);
    newMember->setID(id);

    d->m_memberList.push_back(newMember);

    HMemberItem *newItem = new HMemberItem(newMember, d->m_memberView);

    QObject::connect(
            newItem, &HMemberItem::removeItem,
            this, &HMemberList::removeMember);
    QObject::connect(
            newItem, &HMemberItem::editItem,
            this, &HMemberList::editMember);

    d->m_memberView->addItem(newItem);
}

void HMemberList::editMember(HMember *member)
{
    Q_D(HMemberList);

    d->m_memberDialog->setMode(HMemberEdit::Mode::EditMode);
    d->m_memberDialog->setTargetMember(member);

    d->m_dialog->showDialog();
}

/*
void HMemberList::updateMember(HMember *member)
{
    Q_D(HMemberList);

    QVector<HMember *>::iterator it;
    for (it = d->m_memberList.begin(); it != d->m_memberList.end(); it++) {
        qDebug() << (*it)->name();
    }
}
 */

void HMemberList::removeMember(const QString &id)
{
    Q_D(HMemberList);

    // TODO: Delete member to DB

    d->m_memberView->removeItem(id);
}