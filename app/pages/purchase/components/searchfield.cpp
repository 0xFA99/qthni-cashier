#include "purchase/components/searchfield.h"
#include "purchase/components/searchfield_p.h"

#include <QHBoxLayout>
#include <QPainterPath>
#include <QPainter>

#include "qtmaterial/lib/qtmaterialtheme.h"

SearchFieldPrivate::SearchFieldPrivate(SearchField *q)
    : q_ptr(q)
{
}

SearchFieldPrivate::~SearchFieldPrivate() = default;

void SearchFieldPrivate::init()
{
    Q_Q(SearchField);

    m_layout    = new QHBoxLayout(q);
    m_lineEdit  = new QtMaterialTextField(q);
    m_iconButton = new QtMaterialIconButton(QtMaterialTheme::icon("action", "search"), q);

    m_iconButton->setIconSize(QSize(24, 24));

    m_lineEdit->setFont(QFont("Roboto", 12, QFont::Normal));
    m_lineEdit->setTextColor(QColor(0, 0, 0, 166));
    m_lineEdit->setShowInputLine(false);

    m_layout->addWidget(m_iconButton);
    m_layout->addWidget(m_lineEdit);
    m_layout->setContentsMargins(16, 10, 16, 10);
}

SearchField::SearchField(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new SearchFieldPrivate(this))
{
    d_func()->init();
}

SearchField::~SearchField() = default;

void SearchField::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    Q_D(SearchField);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);

    QPainterPath path;
    path.addRoundedRect(rect(), 18, 18);

    QPainter painter(this);
    painter.setClipPath(path);
    painter.setClipping(true);

    painter.setOpacity(1);
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);
    painter.drawRect(rect());
}