#ifndef HMATERIALIMAGE_PRIVATE_H
#define HMATERIALIMAGE_PRIVATE_H

#include <QImage>
#include <QPixmap>

class HMaterialImage;

class HMaterialImagePrivate
{
    Q_DISABLE_COPY(HMaterialImagePrivate)
    Q_DECLARE_PUBLIC(HMaterialImage)

public:
    HMaterialImagePrivate(HMaterialImage *q);
    ~HMaterialImagePrivate();

    void init();

    HMaterialImage *const   q_ptr;
    QImage                  m_image;
    QPixmap                 m_pixmap;
    int                     m_width;
    int                     m_height;
};

#endif
