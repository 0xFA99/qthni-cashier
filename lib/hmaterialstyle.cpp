#include <QFontDatabase>

#include "hmaterialstyle.h"
#include "hmaterialtheme.h"

HMaterialStylePrivate::HMaterialStylePrivate(HMaterialStyle *q)
    : q_ptr(q)
{
}

HMaterialStylePrivate::~HMaterialStylePrivate()
{
}

void HMaterialStylePrivate::init()
{
    Q_Q(HMaterialStyle);

    QFontDatabase::addApplicationFont(":/fonts/ProductSans-Regular");
    QFontDatabase::addApplicationFont(":/fonts/ProductSans-Medium");
    QFontDatabase::addApplicationFont(":/fonts/ProductSans-Bold");
    // QFontDatabase::addApplicationFont(":/fonts/ProductSans-Light");

    q->setTheme(new HMaterialTheme);
}

void HMaterialStyle::setTheme(HMaterialTheme *theme)
{
    Q_D(HMaterialStyle);

    d->theme = theme;
    theme->setParent(this);
}

QColor HMaterialStyle::themeColor(const QString &key) const
{
    Q_D(const HMaterialStyle);

    Q_ASSERT(d->theme);

    return d->theme->getColor(key);
}

HMaterialStyle::HMaterialStyle()
    : QCommonStyle(),
      d_ptr(new HMaterialStylePrivate(this))
{
    d_func()->init();
}

