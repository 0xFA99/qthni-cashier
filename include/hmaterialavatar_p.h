#ifndef HMATERIALAVATAR_P_H
#define HMATERIALAVATAR_P_H

#include <QtGlobal>
#include <QChar>
#include <QImage>
#include <QIcon>
#include <QPixmap>
#include <QColor>

#include "hmaterialtheme.h"

class HMaterialAvatar;

class HMaterialAvatarPrivate
{
    Q_DISABLE_COPY(HMaterialAvatarPrivate)
    Q_DECLARE_PUBLIC(HMaterialAvatar)

public:
    HMaterialAvatarPrivate(HMaterialAvatar *q);
    ~HMaterialAvatarPrivate();

    void init();

    HMaterialAvatar *const  q_ptr;
    int                     size;
    HMaterial::AvatarType   type;
    QChar                   letter;
    QImage                  image;
    QIcon                   icon;
    QPixmap                 pixmap;
    bool                    useThemeColors;
    QColor                  textColor;
    QColor                  backgroundColor;
};

#endif
