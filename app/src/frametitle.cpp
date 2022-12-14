#include "widgets/frametitle.h"
#include "widgets/frametitle_p.h"

#include <QVBoxLayout>
#include <QPainter>
#include <QPainterPath>

FrameTitlePrivate::FrameTitlePrivate(FrameTitle *q)
    : q_ptr(q)
{
}

FrameTitlePrivate::~FrameTitlePrivate() = default;

void FrameTitlePrivate::init()
{
    Q_Q(FrameTitle);

    m_layout    = new QVBoxLayout(q);
    m_title     = new QLabel("Untitled", q);
    m_fontSize  = 12;

    QFont font("Roboto", m_fontSize, QFont::Medium);
    // font.setCapitalization(QFont::AllUppercase);
    q->setFont(font);

    m_layout->addWidget(m_title);
    m_layout->setContentsMargins(16, 16, 16, 16);
}

FrameTitle::FrameTitle(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new FrameTitlePrivate(this))
{
    d_func()->init();
}

FrameTitle::FrameTitle(const QString &title, QWidget *parent)
    : QWidget(parent)
    , d_ptr(new FrameTitlePrivate(this))
{
    d_func()->init();

    setTitle(title);
}

FrameTitle::~FrameTitle() = default;

void FrameTitle::setTitle(const QString &text)
{
    Q_D(FrameTitle);

    d->m_title->setText(text);
}

QString FrameTitle::title() const
{
    Q_D(const FrameTitle);

    return d->m_title->text();
}

void FrameTitle::addChildWidget(QWidget *widget)
{
    Q_D(FrameTitle);

    d->m_layout->addWidget(widget);
    d->m_layout->setSpacing(14);
}

void FrameTitle::setFontSize(int size)
{
    Q_D(FrameTitle);

    d->m_fontSize = size;

    QFont f(font());
    f.setPointSize(size);
    setFont(f);

    update();
}

void FrameTitle::setTitleColor(const QColor &color)
{
    Q_D(FrameTitle);

    d->m_titleColor = color;

    QPalette palette = d->m_title->palette();
    palette.setColor(d->m_title->foregroundRole(), color);
    d->m_title->setPalette(palette);
}

QColor FrameTitle::titleColor() const
{
    Q_D(const FrameTitle);

    return d->m_titleColor;
}

int FrameTitle::fontSize() const
{
    Q_D(const FrameTitle);

    return d->m_fontSize;
}

void FrameTitle::paintEvent(QPaintEvent *event)
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

    // Draw separate line
    QRect line(16, 46, rect().width() - 32, 1);
    painter.fillRect(line, QRgb(0xf1f4f9));
}