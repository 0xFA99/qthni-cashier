#ifndef HMATERIALIMAGE_H
#define HMATERIALIMAGE_H

#include <QWidget>

#include "hmaterialtheme.h"

class HMaterialImagePrivate;
class HMaterialImage : public QWidget
{
    Q_OBJECT

public:
    explicit HMaterialImage(QWidget *parent = nullptr);
    explicit HMaterialImage(const QIcon &icon, QWidget *parent = nullptr);
    explicit HMaterialImage(const QImage &image, QWidget *parent = nullptr);
    explicit HMaterialImage(const QChar &letter, QWidget *parent = nullptr);
    ~HMaterialImage();

    void setTextColor(const QColor &color);
    QColor textColor() const;

    void setBackgroundColor(const QColor &color);
    QColor backgroundColor() const;

    QSize sizeHint() const Q_DECL_OVERRIDE;

    void setSize(int size);
    int size() const;

    void setLetter(const QChar &letter);
    void setImage(const QImage &image);
    void setIcon(const QIcon &icon);

    QImage image() const;

    HMaterial::AvatarType type() const;

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    const QScopedPointer<HMaterialImagePrivate> d_ptr;

private:
    Q_DISABLE_COPY(HMaterialImage)
    Q_DECLARE_PRIVATE(HMaterialImage)
};

#endif
