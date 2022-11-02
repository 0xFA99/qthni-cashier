#ifndef HMATERIALIMAGE_PRIVATE_H
#define HMATERIALIMAGE_PRIVATE_H

#include <QtGlobal>
#include <QChar>
#include <QImage>
#include <QIcon>
#include <QPixmap>
#include <QColor>

#include "hmaterialimage.h"

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
    int                     m_size;
    HMaterial::AvatarType   m_type;
    QChar                   m_letter;
    QImage                  m_image;
    QIcon                   m_icon;
    QPixmap                 m_pixmap;
    QColor                  m_textColor;
    QColor                  m_backgroundColor;
};

#endif
