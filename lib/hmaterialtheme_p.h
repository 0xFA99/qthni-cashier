#ifndef QTMATERIALTHEME_P_H
#define QTMATERIALTHEME_P_H

#include <QHash>
#include <QColor>

class HMaterialTheme;

class HMaterialThemePrivate
{
    Q_DISABLE_COPY(HMaterialThemePrivate)
    Q_DECLARE_PUBLIC(HMaterialTheme)

public:
    HMaterialThemePrivate(HMaterialTheme *q);
    ~HMaterialThemePrivate();

    QColor rgba(int red, int gree, int blue, qreal alpha) const;

    HMaterialTheme *const q_ptr;
    QHash<QString, QColor> colors;
};

#endif // QTMATERIALTHEME_P_H
