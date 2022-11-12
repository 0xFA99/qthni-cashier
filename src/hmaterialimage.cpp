#include "hmaterialimage.h"
#include "hmaterialimage_p.h"

#include <QPainter>

#include "hmaterialstyle.h"

HMaterialImagePrivate::HMaterialImagePrivate(HMaterialImage *q)
    : q_ptr(q)
{
}

HMaterialImagePrivate::~HMaterialImagePrivate()
{
}

void HMaterialImagePrivate::init()
{
    Q_Q(HMaterialImage);

    m_size      = 40;
    m_type      = HMaterial::LetterAvatar;

    m_textColor          = QColor(Qt::white);
    m_backgroundColor    = QColor(Qt::gray);

    QFont font(q->font());
    font.setPointSizeF(16);
    q->setFont(font);

    /*
    QSizePolicy policy( QSizePolicy::MinimumExpanding,
                        QSizePolicy::MinimumExpanding);
                        */
    QSizePolicy policy( QSizePolicy::Preferred,
                        QSizePolicy::Preferred);
    q->setSizePolicy(policy);
}

HMaterialImage::HMaterialImage(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HMaterialImagePrivate(this))
{
    d_func()->init();
}

HMaterialImage::HMaterialImage(const QIcon &icon, QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HMaterialImagePrivate(this))
{
    d_func()->init();

    setIcon(icon);
}

HMaterialImage::HMaterialImage(const QImage &image, QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HMaterialImagePrivate(this))
{
    d_func()->init();

    setImage(image);
}

HMaterialImage::HMaterialImage(const QChar &letter, QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HMaterialImagePrivate(this))
{
    d_func()->init();

    setLetter(letter);
}

HMaterialImage::~HMaterialImage()
{
}

void HMaterialImage::setTextColor(const QColor &color)
{
    Q_D(HMaterialImage);

    d->m_textColor = color;
    update();
}

QColor HMaterialImage::textColor() const
{
    Q_D(const HMaterialImage);

    return d->m_textColor;
}

void HMaterialImage::setBackgroundColor(const QColor &color)
{
    Q_D(HMaterialImage);

    d->m_backgroundColor = color;
    update();
}

QColor HMaterialImage::backgroundColor() const
{
    Q_D(const HMaterialImage);

    return d->m_backgroundColor;
}

QSize HMaterialImage::sizeHint() const
{
    Q_D(const HMaterialImage);

    return QSize(d->m_size + 2, d->m_size + 2);
}

void HMaterialImage::setSize(int size)
{
    Q_D(HMaterialImage);

    d->m_size = size;

    if (!d->m_image.isNull()) {
        d->m_pixmap = QPixmap::fromImage(d->m_image.scaled(d->m_size, d->m_size,
                      Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    }

    QFont f(font());
    f.setPointSizeF(size * 16 / 40);
    setFont(f);

    update();
}

int HMaterialImage::size() const
{
    Q_D(const HMaterialImage);

    return d->m_size;
}

void HMaterialImage::setLetter(const QChar &letter)
{
    Q_D(HMaterialImage);

    d->m_letter = letter;
    d->m_type   = HMaterial::LetterAvatar;
    update();
}

void HMaterialImage::setImage(const QImage &image)
{
    Q_D(HMaterialImage);

    d->m_image  = image;
    d->m_type     = HMaterial::ImageAvatar;

    d->m_pixmap = QPixmap::fromImage(image.scaled(d->m_size, d->m_size,
                  Qt::KeepAspectRatio, Qt::SmoothTransformation));

    update();
}

void HMaterialImage::setIcon(const QIcon &icon)
{
    Q_D(HMaterialImage);

    d->m_icon = icon;
    d->m_type = HMaterial::IconAvatar;

    update();
}

HMaterial::AvatarType HMaterialImage::type() const
{
    Q_D(const HMaterialImage);

    return d->m_type;
}

void HMaterialImage::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    Q_D(HMaterialImage);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QRect r = rect();
    const qreal hs = d->m_size / 2;

    if (HMaterial::ImageAvatar != d->m_type) {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(backgroundColor());
        
        painter.setPen(Qt::NoPen);
        painter.setBrush(brush);
        painter.drawRect(QRectF((width() - d->m_size) / 2, (height() - d->m_size) / 2,
                    d->m_size, d->m_size));
    }

    switch (d->m_type) {
        case HMaterial::ImageAvatar: {
            painter.drawPixmap(QRect(width() / 2 - hs, height() / 2 - hs, d->m_size, d->m_size),
                    d->m_pixmap);
            break;
        }
        case HMaterial::LetterAvatar: {
            painter.setPen(textColor());
            painter.setBrush(Qt::NoBrush);
            painter.drawText(r, Qt::AlignCenter, QString(d->m_letter));
            break;
        }
        default:
            break;
    }
}

QImage HMaterialImage::image() const
{
    Q_D(const HMaterialImage);

    return d->m_image;
}