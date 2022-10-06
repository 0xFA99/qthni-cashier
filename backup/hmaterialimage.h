#ifndef HMATERIALIMAGE_H
#define HMATERIALIMAGE_H

#include <QWidget>

class HMaterialImagePrivate;

class HMaterialImage : public QWidget
{
public:
    HMaterialImage(QWidget *parent = nullptr);
    HMaterialImage(const QImage &image, QSize size, QWidget *parent = nullptr);
    ~HMaterialImage();

    void setImage(const QImage &image, QSize size);
    QImage getImage() const;

    void setImageSize(QSize size);
    QSize imageSize() const;

    void setImageWidth(int width);
    int imageWidth() const;

    void setImageHeight(int height);
    int imageHeight() const;

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    const QScopedPointer<HMaterialImagePrivate> d_ptr;

private:
    Q_DISABLE_COPY(HMaterialImage)
    Q_DECLARE_PRIVATE(HMaterialImage)
};

#endif
