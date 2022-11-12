#ifndef HMATERIALFAB_P_H
#define HMATERIALFAB_P_H

#include "hmaterialraisedbutton_p.h"

class HMaterialFloatingActionButton;

class HMaterialFloatingActionButtonPrivate : public HMaterialRaisedButtonPrivate
{
    Q_DISABLE_COPY(HMaterialFloatingActionButtonPrivate)
    Q_DECLARE_PUBLIC(HMaterialFloatingActionButton)

public:
    enum {
        DefaultDiameter = 56,
        MiniDiameter = 40
    };

    enum {
        DefaultIconSize = 24,
        MiniIconSize = 18
    };

    HMaterialFloatingActionButtonPrivate(HMaterialFloatingActionButton *q);
    ~HMaterialFloatingActionButtonPrivate();

    void init();
    QRect fabGeometry() const;
    void setupProperties();

    inline int diameter() const;
    inline int iconSize() const;

    Qt::Corner corner;
    bool       mini;
    int        offsX;
    int        offsY;
};

inline int HMaterialFloatingActionButtonPrivate::diameter() const
{
    return mini ? MiniDiameter : DefaultDiameter;
}

inline int HMaterialFloatingActionButtonPrivate::iconSize() const
{
    return mini ? MiniIconSize : DefaultIconSize;
}

#endif // HMATERIALFAB_P_H
