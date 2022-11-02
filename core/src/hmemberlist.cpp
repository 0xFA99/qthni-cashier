#include "hmemberlist.h"
#include "hmemberlist_p.h"

#include <QPainter>
#include <QPainterPath>
#include <QGridLayout>

#include "hmemberview.h"

HMemberListPrivate::HMemberListPrivate(HMemberList *q)
    : q_ptr(q)
{
}

HMemberListPrivate::~HMemberListPrivate()
{
}

void HMemberListPrivate::HMemberListPrivate::init()
{
    Q_Q(HMemberList);

    m_layout        = new QGridLayout(q);
    m_title         = new HMaterialLabel("Member List", q);
    m_gridButton    = new HMaterialFlatButton("\uE62A", q);
    m_vertButton    = new HMaterialFlatButton("\uE622", q);
    m_badge         = new HMaterialBadge(q);

    HMemberView *view = new HMemberView(q);
    view->addItem();
    view->addItem();
    view->addItem();

    m_title->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);

    QFont font("iconfont", 12, QFont::Bold);
    m_gridButton->setFont(font);
    m_vertButton->setFont(font);

    m_layout->addWidget(m_title, 0, 0, 1, 1);
    m_layout->addWidget(m_gridButton, 0, 1, 1, 1);
    m_layout->addWidget(m_vertButton, 0, 2, 1, 1);
    m_layout->addWidget(view, 1, 0, 1, 3);

    m_layout->setContentsMargins(16, 10, 16, 10);
}

HMemberList::HMemberList(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HMemberListPrivate(this))
{
    d_func()->init();
}

HMemberList::~HMemberList()
{
}

void HMemberList::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

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
