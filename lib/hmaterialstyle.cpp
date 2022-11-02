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

    QFontDatabase::addApplicationFont(":/fonts/Roboto-Regular");
    QFontDatabase::addApplicationFont(":/fonts/Roboto-Medium");
    QFontDatabase::addApplicationFont(":/fonts/Roboto-Bold");
    QFontDatabase::addApplicationFont(":/fonts/Roboto-Light");
    QFontDatabase::addApplicationFont(":/fonts/Roboto-Thin");
    QFontDatabase::addApplicationFont(":/fonts/iconfont");

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

