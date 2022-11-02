#include "hmateriallabel.h"
#include "hmateriallabel_p.h"

#include <QPainter>

HMaterialLabelPrivate::HMaterialLabelPrivate(HMaterialLabel *q)
    : q_ptr(q)
{
}

HMaterialLabelPrivate::~HMaterialLabelPrivate()
{
}

void HMaterialLabelPrivate::init()
{
    Q_Q(HMaterialLabel);

    m_size      = 12;
    m_weight    = QFont::Medium;
    m_color     = Qt::black;

    QFont f("Roboto", m_size, m_weight);
    q->setFont(f);
}

HMaterialLabel::HMaterialLabel(QWidget *parent)
    : QLabel(parent)
    , d_ptr(new HMaterialLabelPrivate(this))
{
    d_func()->init();

    setAttribute(Qt::WA_TranslucentBackground);
    setForegroundRole(QPalette::WindowText);
    setTextColor(QColor(0, 0, 0, 217));
}

HMaterialLabel::HMaterialLabel(const QString &text, QWidget *parent)
    : QLabel(text, parent)
    , d_ptr(new HMaterialLabelPrivate(this))
{
    d_func()->init();

    setAttribute(Qt::WA_TranslucentBackground);
    setForegroundRole(QPalette::WindowText);
    setTextColor(QColor(0, 0, 0, 217));
}

HMaterialLabel::~HMaterialLabel()
{
}

void HMaterialLabel::setFontSize(int size)
{
    Q_D(HMaterialLabel);

    d->m_size = size;

    QFont f(font());
    f.setPixelSize(size);
    setFont(f);
}

int HMaterialLabel::fontSize() const
{
    Q_D(const HMaterialLabel);

    return d->m_size;
}

void HMaterialLabel::setFontWeight(QFont::Weight weight)
{
    Q_D(HMaterialLabel);

    d->m_weight = weight;

    QFont f(font());
    f.setWeight(weight);
    setFont(f);
}

QFont::Weight HMaterialLabel::fontWeight() const
{
    Q_D(const HMaterialLabel);

    return d->m_weight;
}

void HMaterialLabel::setTextColor(const QColor &color)
{
    Q_D(HMaterialLabel);

    d->m_color = color;

    QPalette pal = palette();
    pal.setColor(foregroundRole(), d->m_color);
    setPalette(pal);
}

QColor HMaterialLabel::textColor() const
{
    Q_D(const HMaterialLabel);

    return d->m_color;
}
