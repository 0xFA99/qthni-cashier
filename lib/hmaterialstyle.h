#ifndef HMATERIALSTYLE_H
#define HMATERIALSTYLE_H

#include <QtWidgets/QCommonStyle>

#include "hmaterialstyle_p.h"

#define MATERIAL_DISABLE_THEME_COLORS \
    if (d->useThemeColors == true) { d->useThemeColors = false; }

class HMaterialTheme;

class HMaterialStyle : public QCommonStyle
{
    Q_OBJECT

public:
    inline static HMaterialStyle &instance();

    void setTheme(HMaterialTheme *theme);
    QColor themeColor(const QString &key) const;

protected:
    const QScopedPointer<HMaterialStylePrivate> d_ptr;

private:
    Q_DECLARE_PRIVATE(HMaterialStyle)

    HMaterialStyle();

    HMaterialStyle(HMaterialStyle const &);
    void operator=(HMaterialStyle const &);
};

inline HMaterialStyle &HMaterialStyle::instance()
{
    static HMaterialStyle instance;
    return instance;
}

#endif
