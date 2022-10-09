#include <QPainter>
#include <QPainterPath>

#include "hmaterialavatar.h"
#include "hmaterialavatar_p.h"

#include "hmaterialstyle.h"

HMaterialAvatarPrivate::HMaterialAvatarPrivate(HMaterialAvatar *q)
    : q_ptr(q)
{
}

HMaterialAvatarPrivate::~HMaterialAvatarPrivate()
{
}

void HMaterialAvatarPrivate::init()
{
    Q_Q(HMaterialAvatar);
    
    size            = 40;
    type            = HMaterial::LetterAvatar;
    useThemeColors  = true;

    QFont font(q->font());
    font.setPointSizeF(16);
    q->setFont(font);

    QSizePolicy policy( QSizePolicy::MinimumExpanding,
                        QSizePolicy::MinimumExpanding);
    q->setSizePolicy(policy);
}

HMaterialAvatar::HMaterialAvatar(QWidget *parent)
    : QWidget(parent),
      d_ptr(new HMaterialAvatarPrivate(this))
{
    d_func()->init();
}

HMaterialAvatar::HMaterialAvatar(const QIcon &icon, QWidget *parent)
    : QWidget(parent),
      d_ptr(new HMaterialAvatarPrivate(this))
{
    d_func()->init();

    setIcon(icon);
}

HMaterialAvatar::HMaterialAvatar(const QChar &letter, QWidget *parent)
    : QWidget(parent),
      d_ptr(new HMaterialAvatarPrivate(this))
{
    d_func()->init();

    setLetter(letter);
}

HMaterialAvatar::HMaterialAvatar(const QImage &image, QWidget *parent)
    : QWidget(parent),
      d_ptr(new HMaterialAvatarPrivate(this))
{
    d_func()->init();

    setImage(image);
}

HMaterialAvatar::~HMaterialAvatar()
{
}

void HMaterialAvatar::setUseThemeColors(bool value)
{
    Q_D(HMaterialAvatar);

    if (d->useThemeColors == value)
        return;

    d->useThemeColors = value;
    update();
}

bool HMaterialAvatar::useThemeColors() const
{
    Q_D(const HMaterialAvatar);

    return d->useThemeColors;
}

void HMaterialAvatar::setTextColor(const QColor &color)
{
    Q_D(HMaterialAvatar);

    d->textColor = color;

    MATERIAL_DISABLE_THEME_COLORS
    update();
}

QColor HMaterialAvatar::textColor() const
{
    Q_D(const HMaterialAvatar);

    if (d->useThemeColors || !d->textColor.isValid()) {
        return HMaterialStyle::instance().themeColor("canvas");
    } else {
        return d->textColor;
    }
}

void HMaterialAvatar::setBackgroundColor(const QColor &color)
{
    Q_D(HMaterialAvatar);

    d->backgroundColor = color;

    MATERIAL_DISABLE_THEME_COLORS
    update();
}

QColor HMaterialAvatar::backgroundColor() const
{
    Q_D(const HMaterialAvatar);

    if (d->useThemeColors || !d->backgroundColor.isValid()) {
        return HMaterialStyle::instance().themeColor("primary1");
    } else {
        return d->backgroundColor;
    }
}

QSize HMaterialAvatar::sizeHint() const
{
    Q_D(const HMaterialAvatar);

    return QSize(d->size + 2, d->size + 2);
}

void HMaterialAvatar::setSize(int size)
{
    Q_D(HMaterialAvatar);

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

int HMaterialAvatar::size() const
{
    Q_D(const HMaterialAvatar);

    return d->size;
}

void HMaterialAvatar::setLetter(const QChar &letter)
{
    Q_D(HMaterialAvatar);

    d->letter = letter;
    d->type = HMaterial::LetterAvatar;
    update();
}

void HMaterialAvatar::setImage(const QImage &image)
{
    Q_D(HMaterialAvatar);

    d->image = image;
    d->type = HMaterial::ImageAvatar;

    d->pixmap = QPixmap::fromImage(image.scaled(d->size, d->size,
                Qt::IgnoreAspectRatio,
                Qt::SmoothTransformation));
    update();
}

void HMaterialAvatar::setIcon(const QIcon &icon)
{
    Q_D(HMaterialAvatar);

    d->icon = icon;
    d->type = HMaterial::IconAvatar;
    update();
}

HMaterial::AvatarType HMaterialAvatar::type() const 
{
    Q_D(const HMaterialAvatar);

    return d->type;
}

void HMaterialAvatar::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    Q_D(HMaterialAvatar);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QRect r = rect();
    const qreal hs = d->size / 2;

    if (!isEnabled()) {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(HMaterialStyle::instance().themeColor("disabled"));
        painter.setPen(Qt::NoPen);
        painter.setBrush(brush);
        painter.drawEllipse(QRectF((width() - d->size) / 2, (height() - d->size) / 2,
                    d->size, d->size));

        return ;
    }

    if (HMaterial::ImageAvatar != d->type) {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(backgroundColor());
        painter.setPen(Qt::NoPen);
        painter.setBrush(brush);
        painter.drawEllipse(QRectF((width() - d->size) / 2, (height() - d->size) / 2,
                    d->size, d->size));
    }

    switch (d->type) {
        case HMaterial::ImageAvatar: {
            QPainterPath path;
            path.addEllipse(width() / 2 - hs, height() / 2 - hs, d->size, d->size);
            painter.setClipPath(path);

            painter.drawPixmap(QRect(width() / 2 - hs, height() / 2 - hs, d->size, d->size),
                    d->pixmap);

            break;
        }
        case HMaterial::LetterAvatar: {
            painter.setPen(textColor());
            painter.setBrush(Qt::NoBrush);
            painter.drawText(r, Qt::AlignCenter, QString(d->letter));
            break;
        }
        default:
            break;
    }
}

