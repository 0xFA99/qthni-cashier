#include "hmaterialsearch.h"
#include "hmaterialsearch_p.h"

#include <QPainter>
#include <QPainterPath>
#include <QHBoxLayout>

HMaterialSearchPrivate::HMaterialSearchPrivate(HMaterialSearch *q)
    : q_ptr(q)
{
}

HMaterialSearchPrivate::~HMaterialSearchPrivate()
{
}

void HMaterialSearchPrivate::init()
{
    Q_Q(HMaterialSearch);

    m_layout    = new QHBoxLayout(q);
    m_search    = new HMaterialTextField(q);
    m_button    = new HMaterialFlatButton("\uE661", q);

    m_search->setFont(QFont("Roboto", 12, QFont::Medium));
    m_search->setTextColor(QColor(0, 0, 0, 166));
    m_search->setShowInputLine(false);

    m_button->setHaloVisible(false);
    m_button->setFontSize(14);
    m_button->setForegroundColor(QColor(0, 0, 0, 115));
    m_button->setRippleStyle(HMaterial::NoRipple);

    m_layout->addWidget(m_search);
    m_layout->addWidget(m_button);
    m_layout->setContentsMargins(20, 10, 20, 10);
}

HMaterialSearch::HMaterialSearch(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HMaterialSearchPrivate(this))
{
    d_func()->init();

    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    setFixedHeight(50);
}

HMaterialSearch::~HMaterialSearch()
{
}

void HMaterialSearch::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    // brush.setColor(QColor("#f1f4f9"));
    brush.setColor(Qt::white);
    
    QPainterPath path;
    path.addRoundedRect(rect(), 25, 25);

    QPainter painter(this);
    painter.setClipPath(path);
    painter.setClipping(true);

    painter.setOpacity(1);
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);
    painter.drawRect(rect());
}
