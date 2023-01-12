#ifndef QTHNI_QTMATERIALIMAGE_P_H
#define QTHNI_QTMATERIALIMAGE_P_H

#include <QtGlobal>
#include <QChar>
#include <QImage>
#include <QIcon>
#include <QPixmap>
#include <QColor>
#include "qtmaterial/lib/qtmaterialtheme.h"

class QtMaterialImage;

class QtMaterialImagePrivate
{
    Q_DISABLE_COPY(QtMaterialImagePrivate)
    Q_DECLARE_PUBLIC(QtMaterialImage)

public:
    QtMaterialImagePrivate(QtMaterialImage *q);
    ~QtMaterialImagePrivate();

    void init();

    QtMaterialImage *const  q_ptr;
    int                     size;
    Material::AvatarType    type;
    QChar                   letter;
    QImage                  image;
    QIcon                   icon;
    QPixmap                 pixmap;
    bool                    useThemeColors;
    QColor                  textColor;
    QColor                  backgroundColor;

};

#endif //QTHNI_QTMATERIALIMAGE_P_H
