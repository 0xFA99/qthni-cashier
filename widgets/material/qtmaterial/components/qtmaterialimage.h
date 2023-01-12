#ifndef QTHNI_QTMATERIALIMAGE_H
#define QTHNI_QTMATERIALIMAGE_H

#include <QWidget>
#include "qtmaterial/lib/qtmaterialtheme.h"

class QtMaterialImagePrivate;

class QtMaterialImage : public QWidget
{
    Q_OBJECT

public:
    explicit QtMaterialImage(QWidget *parent = 0);
    explicit QtMaterialImage(const QIcon &icon, QWidget *parent = 0);
    explicit QtMaterialImage(const QChar &letter, QWidget *parent = 0);
    explicit QtMaterialImage(const QImage &image, QWidget *parent = 0);
    ~QtMaterialImage();

    void setUseThemeColors(bool value);
    bool useThemeColors() const;

    void setTextColor(const QColor &color);
    QColor textColor() const;

    void setBackgroundColor(const QColor &color);
    QColor backgroundColor() const;

    QSize sizeHint() const Q_DECL_OVERRIDE;

    void setSize(int size);
    int size() const;

    void setImage(const QImage &image);
    QImage image() const;

    void setLetter(const QChar &letter);
    void setIcon(const QIcon &icon);

    Material::AvatarType type() const;

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

    const  QScopedPointer<QtMaterialImagePrivate> d_ptr;

private:
    Q_DISABLE_COPY(QtMaterialImage)
    Q_DECLARE_PRIVATE(QtMaterialImage)
};

#endif //QTHNI_QTMATERIALIMAGE_H
