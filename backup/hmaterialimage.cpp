#include "hmaterialimage.h"
#include "hmaterialimage_p.h"

#include <QPainter>
#include <QSizePolicy>

#include <QDebug>

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

    m_image     = QImage(":/images/images/ANDRO.png");
    m_width     = 100;
    m_height    = 100;
}

HMaterialImage::HMaterialImage(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HMaterialImagePrivate(this))
{
    d_func()->init();

    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

HMaterialImage::HMaterialImage(const QImage &image, QSize size, QWidget *parent)
    : QWidget(parent)
    , d_ptr(new HMaterialImagePrivate(this))
{
    d_func()->init();

    setImage(image, size);

    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

HMaterialImage::~HMaterialImage()
{
}

void HMaterialImage::setImage(const QImage &image, QSize size)
{
    Q_D(HMaterialImage);

    d->m_image = image;
    d->m_width = size.width();
    d->m_height = size.height();

    qDebug() << "setImage called";

    update();
}

QImage HMaterialImage::getImage() const
{
    Q_D(const HMaterialImage);

    return d->m_image;
}

void HMaterialImage::setImageSize(QSize size)
{
    Q_D(HMaterialImage);

    d->m_width  = size.width();
    d->m_height = size.height();

    update();
}

QSize HMaterialImage::imageSize() const
{
    Q_D(const HMaterialImage);

    return QSize(d->m_width, d->m_height);
}

void HMaterialImage::setImageWidth(int width)
{
    Q_D(HMaterialImage);

    d->m_width = width;
    update();
}

int HMaterialImage::imageWidth() const
{
    Q_D(const HMaterialImage);

    return d->m_width;
}

void HMaterialImage::setImageHeight(int height)
{
    Q_D(HMaterialImage);

    d->m_height = height;
    update();
}

int HMaterialImage::imageHeight() const
{
    Q_D(const HMaterialImage);

    return d->m_height;
}

void HMaterialImage::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    Q_D(HMaterialImage);

    qDebug() << "Image Terupdate";

    //d->m_pixmap = QPixmap::fromImage(d->m_image.scaled(
    //            d->m_width, d->m_height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));

    //QPainter painter(this);
    //painter.setRenderHint(QPainter::Antialiasing);

    //painter.drawPixmap((rect().bottomRight() - d->m_pixmap.rect().bottomRight()) / 2, d->m_pixmap);
    //painter.drawPixmap(QRect(width() / 2, height() / 2, d->m_width, d->m_height), d->m_pixmap);
}
