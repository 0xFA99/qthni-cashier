#ifndef HMATERIALIMAGE_H
#define HMATERIALIMAGE_H

#include <QWidget>

class HMaterialImagePrivate;

class HMaterialImage : public QWidget
{
    Q_OBJECT

public:
    explicit HMaterialImage(QWidget *parent = nullptr);
    explicit HMaterialImage(const QImage &image, QWidget *parent = nullptr);
    ~HMaterialImage();

    void setImage(const QImage &image);

    void setSize(int size);
    int size() const;

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    const QScopedPointer<HMaterialImagePrivate> d_ptr;

private:
    Q_DISABLE_COPY(HMaterialImage)
    Q_DECLARE_PRIVATE(HMaterialImage)
};

#endif
