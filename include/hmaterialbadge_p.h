#ifndef HMATERIALBADGE_P_H
#define HMATERIALBADGE_P_H

#include <QtGlobal>
#include <QSize>
#include <QIcon>
#include <QColor>

class HMaterialBadge;

class HMaterialBadgePrivate
{
    Q_DISABLE_COPY(HMaterialBadgePrivate);
    Q_DECLARE_PUBLIC(HMaterialBadge);

public:
    HMaterialBadgePrivate(HMaterialBadge *q);
    ~HMaterialBadgePrivate();

    void init();

    HMaterialBadge  *const  q_ptr;
    QString                 text;
    QColor                  textColor;
    QColor                  backgroundColor;
    QSize                   size;
    QIcon                   icon;
    qreal                   x;
    qreal                   y;
    int                     padding;
    bool                    useThemeColors;
};

#endif
