#include "hmaterialimage.h"
#include "hmaterialimage_p.h"

#include <QPainter>

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

    m_size = 50;
    m_image = QImage(":/images/images/ANDRO.png");
}

HMaterialImage::HMaterialImage(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HMaterialImagePrivate(this))
{
    d_func()->init();
}

HMaterialImage::HMaterialImage(const QImage &image, QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HMaterialImagePrivate(this))
{
    d_func()->init();

    setImage(image);
}

HMaterialImage::~HMaterialImage()
{
}

void HMaterialImage::setImage(const QImage &image)
{
    Q_D(HMaterialImage);

    d->m_image = image;
    d->m_pixmap = QPixmap::fromImage(d->m_image.scaled(d->m_size, d->m_size,
                                    Qt::KeepAspectRatio,
                                    Qt::SmoothTransformation));

    update();
}

QImage HMaterialImage::getImage() const
{
    Q_D(const HMaterialImage);

    return d->m_image;
}

void HMaterialImage::setSize(int size)
{
    Q_D(HMaterialImage);

    d->m_size = size;
    d->m_pixmap = QPixmap::fromImage(d->m_image.scaled(d->m_size, d->m_size,
                                    Qt::KeepAspectRatio,
                                    Qt::SmoothTransformation));

    update();
}

int HMaterialImage::size() const
{
    Q_D(const HMaterialImage);

    return d->m_size;
}

void HMaterialImage::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    Q_D(HMaterialImage);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.drawPixmap((rect().bottomRight() - d->m_pixmap.rect().bottomRight()) / 2, d->m_pixmap);
}
