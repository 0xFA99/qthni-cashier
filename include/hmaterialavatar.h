#ifndef HMATERIALAVATAR_H
#define HMATERIALAVATAR_H

#include <QWidget>

#include "hmaterialtheme.h"

class HMaterialAvatarPrivate;

class HMaterialAvatar : public QWidget
{
    Q_OBJECT

public:
    explicit HMaterialAvatar(QWidget *parent = nullptr);
    explicit HMaterialAvatar(const QIcon &icon, QWidget *parent = nullptr);
    explicit HMaterialAvatar(const QChar &letter, QWidget *parent = nullptr);
    explicit HMaterialAvatar(const QImage &image, QWidget *parent = nullptr);
    ~HMaterialAvatar();

    void setUseThemeColors(bool value);
    bool useThemeColors() const;

    void setTextColor(const QColor &color);
    QColor textColor() const;

    void setBackgroundColor(const QColor &color);
    QColor backgroundColor() const;

    QSize sizeHint() const Q_DECL_OVERRIDE;

    void setSize(int size);
    int size() const;

    void setLetter(const QChar &letter);
    void setIcon(const QIcon &icon);
    void setImage(const QImage &image);
    QImage getImage() const;

    HMaterial::AvatarType type() const;

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

    const QScopedPointer<HMaterialAvatarPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HMaterialAvatar)
    Q_DECLARE_PRIVATE(HMaterialAvatar)
};

#endif
