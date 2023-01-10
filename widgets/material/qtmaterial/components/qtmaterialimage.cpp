#include "qtmaterial/components/qtmaterialimage.h"
#include "qtmaterial/components/qtmaterialimage_p.h"

#include <QDebug>
#include <QPainter>
#include <QPainterPath>

#include "qtmaterial/lib/qtmaterialstyle.h"

QtMaterialImagePrivate::QtMaterialImagePrivate(QtMaterialImage *q)
    : q_ptr(q)
{
}

QtMaterialImagePrivate::~QtMaterialImagePrivate() = default;

void QtMaterialImagePrivate::init()
{
    Q_Q(QtMaterialImage);

    useThemeColors  = true;
    type            = Material::LetterAvatar;
    size            = 40;

    QFont font(q->font());
    font.setPointSizeF(16);
    q->setFont(font);

    q->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
}

QtMaterialImage::QtMaterialImage(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new QtMaterialImagePrivate(this))
{
    d_func()->init();
}

QtMaterialImage::QtMaterialImage(const QIcon &icon, QWidget *parent)
    : QWidget(parent)
    , d_ptr(new QtMaterialImagePrivate(this))
{
    d_func()->init();

    setIcon(icon);
}

QtMaterialImage::QtMaterialImage(const QChar &letter, QWidget *parent)
    : QWidget(parent)
    , d_ptr(new QtMaterialImagePrivate(this))
{
    d_func()->init();

    setLetter(letter);
}

QtMaterialImage::QtMaterialImage(const QImage &image, QWidget *parent)
    : QWidget(parent)
    , d_ptr(new QtMaterialImagePrivate(this))
{

    d_func()->init();

    setImage(image);
}

QtMaterialImage::~QtMaterialImage() = default;

void QtMaterialImage::setUseThemeColors(bool value)
{
    Q_D(QtMaterialImage);

    if (d->useThemeColors == value) {
        return;
    }

    d->useThemeColors = value;
    update();
}

bool QtMaterialImage::useThemeColors() const
{
    Q_D(const QtMaterialImage);

    return d->useThemeColors;
}

void QtMaterialImage::setTextColor(const QColor &color)
{
    Q_D(QtMaterialImage);

    d->textColor = color;

    MATERIAL_DISABLE_THEME_COLORS
    update();
}

QColor QtMaterialImage::textColor() const
{
    Q_D(const QtMaterialImage);

    if (d->useThemeColors || !d->backgroundColor.isValid()) {
        return QtMaterialStyle::instance().themeColor("primary1");
    } else {
        return d->backgroundColor;
    }
}

void QtMaterialImage::setBackgroundColor(const QColor &color)
{
    Q_D(QtMaterialImage);

    d->backgroundColor = color;

    MATERIAL_DISABLE_THEME_COLORS
    update();
}

QColor QtMaterialImage::backgroundColor() const
{
    Q_D(const QtMaterialImage);

    if (d->useThemeColors || !d->backgroundColor.isValid()) {
        return QtMaterialStyle::instance().themeColor("primary1");
    } else {
        return d->backgroundColor;
    }
}

QSize QtMaterialImage::sizeHint() const
{
    Q_D(const QtMaterialImage);

    return QSize(d->size + 2, d->size + 2);
}

void QtMaterialImage::setSize(int size)
{
    Q_D(QtMaterialImage);

    d->size = size;

    if (!d->image.isNull()) {
        d->pixmap = QPixmap::fromImage(d->image.scaled(d->size, d->size,
                                                       Qt::IgnoreAspectRatio,
                                                       Qt::SmoothTransformation));
    }

    QFont f(font());
    f.setPointSizeF(size * 16 / 40);
    setFont(f);

    update();
}

int QtMaterialImage::size() const
{
    Q_D(const QtMaterialImage);

    return d->size;
}

void QtMaterialImage::setLetter(const QChar &letter)
{
    Q_D(QtMaterialImage);

    d->letter = letter;
    d->type = Material::LetterAvatar;

    update();
}

void QtMaterialImage::setImage(const QImage &image)
{
    Q_D(QtMaterialImage);

    d->image = image;
    d->type = Material::ImageAvatar;

    d->pixmap = QPixmap::fromImage(image.scaled(d->size + 2, d->size + 2,
                                                Qt::IgnoreAspectRatio,
                                                Qt::SmoothTransformation));

    update();
}

void QtMaterialImage::setIcon(const QIcon &icon)
{
    Q_D(QtMaterialImage);

    d->icon = icon;
    d->type = Material::IconAvatar;

    update();
}

Material::AvatarType QtMaterialImage::type() const
{
    Q_D(const QtMaterialImage);

    return d->type;
}

void QtMaterialImage::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    Q_D(QtMaterialImage);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QRect r = rect();
    const qreal hs = d->size / 2;

    if (!isEnabled())
    {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(QtMaterialStyle::instance().themeColor("disabled"));
        painter.setPen(Qt::NoPen);
        painter.setBrush(brush);
        painter.drawRoundedRect(QRectF((width() - d->size) / 2, (height() - d->size) / 2,
                                       d->size, d->size), 8, 8);
        return;
    }

    if (Material::ImageAvatar != d->type)
    {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::red);
        painter.setPen(Qt::NoPen);
        painter.setBrush(brush);
        painter.drawRoundedRect(QRectF((width() - d->size) / 2, (height() - d->size) / 2,
                                       d->size, d->size), 8, 8);
    }

    switch (d->type)
    {
        case Material::ImageAvatar:
        {
            QPainterPath path;
            path.addRoundedRect(QRectF((width() - d->size) / 2, (height() - d->size) / 2, d->size, d->size), 8, 8);
            painter.setClipPath(path);
            painter.setClipping(true);

            painter.drawPixmap(QRect(width() / 2 - hs, height() / 2 - hs, d->size, d->size),
                               d->pixmap);
            break;
        }
        case Material::IconAvatar:
        {
            QRect iconGeometry((width()-hs)/2, (height()-hs)/2, hs, hs);
            QPixmap pixmap = d->icon.pixmap(hs, hs);
            QPainter icon(&pixmap);
            icon.setCompositionMode(QPainter::CompositionMode_SourceIn);
            icon.fillRect(pixmap.rect(), textColor());
            painter.drawPixmap(iconGeometry, pixmap);
            break;
        }
        case Material::LetterAvatar:
        {
            painter.setPen(textColor());
            painter.setBrush(Qt::NoBrush);
            painter.drawText(r, Qt::AlignCenter, QString(d->letter));
            break;
        }
        default:
            break;
    }
}

QImage QtMaterialImage::image() const
{
    Q_D(const QtMaterialImage);

    if (d->image.isNull()) {
        return {};
    }

    return d->image;
}