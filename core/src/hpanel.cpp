#include "hpanel.h"
#include "hpanel_p.h"
#include "hpanel_internal.h"

#include <QVBoxLayout>
#include <QPainter>

HPanelPrivate::HPanelPrivate(HPanel *q)
    : q_ptr(q)
{
}

HPanelPrivate::~HPanelPrivate()
{
}

void HPanelPrivate::HPanelPrivate::init()
{
    Q_Q(HPanel);

    m_layout            = new QVBoxLayout(q);
    m_textColor         = QColor(0, 0, 0, 222);
    m_item              = -1;

    m_logo              = new QLabel("\uE631", q);
    m_logo->setFont(QFont("iconfont", 18, QFont::Medium));
    m_logo->setAlignment(Qt::AlignCenter);
    m_logo->setFixedHeight(50);
    
    QPalette logopal;
    QBrush brush(QColor("#ff8585"));
    logopal.setBrush(QPalette::ColorRole::Text, brush);

    m_logo->setPalette(logopal);
    m_logo->setForegroundRole(QPalette::Text);

    m_layout->addWidget(m_logo);
}

HPanel::HPanel(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HPanelPrivate(this))
{
    d_func()->init();
}

HPanel::~HPanel()
{
}

void HPanel::addLogo()
{
    Q_D(HPanel);
    d->m_layout->insertWidget(0, d->m_logo);
}

void HPanel::setCurrentItem(HPanelItem *item)
{
    Q_D(HPanel);

    setCurrentItem(d->m_layout->indexOf(item));
}

void HPanel::setCurrentItem(int index)
{
    Q_D(HPanel);

    setActiveItem(d->m_item, false);
    d->m_item = index;
    setActiveItem(index, true);

    emit currentChanged(index);
}

void HPanel::addStretch()
{
    Q_D(HPanel);

    d->m_layout->addStretch(1);
}

void HPanel::addItem(const QString &text)
{
    Q_D(HPanel);

    HPanelItem *item = new HPanelItem(text, this);

    d->m_layout->addWidget(item);

    if (d->m_item == -1) {
        d->m_item = 1;
        item->setActive(true);
    }
}

int HPanel::currentIndex() const
{
    Q_D(const HPanel);

    return d->m_item; 
}

void HPanel::setActiveItem(int index, bool active)
{
    Q_D(HPanel);

    HPanelItem *item;

    if (index > -1) {
        item = static_cast<HPanelItem *>(d->m_layout->itemAt(index)->widget());
        if (item) {
            item->setActive(active);
        }
    }
}

void HPanel::updateItems()
{
    Q_D(HPanel);

    HPanelItem *tab;
    for (int i=1; i < d->m_layout->count(); i++) {
        QLayoutItem *item = d->m_layout->itemAt(i);
        if ((tab = static_cast<HPanelItem *>(item->widget()))) {
            tab->setForegroundColor(textColor());
        }
    }
}

void HPanel::setTextColor(const QColor &color)
{
    Q_D(HPanel);

    d->m_textColor = color;

    updateItems();
    update();
}

QColor HPanel::textColor() const
{
    Q_D(const HPanel);

    return d->m_textColor;
}

void HPanel::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    
    QPainter painter(this);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);

    painter.setOpacity(1);
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);

    painter.drawRect(rect());
}
