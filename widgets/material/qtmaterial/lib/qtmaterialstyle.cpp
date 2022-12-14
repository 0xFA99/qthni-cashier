#include "qtmaterial/lib/qtmaterialstyle.h"
#include "qtmaterial/lib/qtmaterialstyle_p.h"
#include <QFontDatabase>
#include "qtmaterial/lib/qtmaterialtheme.h"

/*!
 *  \class QtMaterialStylePrivate
 *  \internal
 */

QtMaterialStylePrivate::QtMaterialStylePrivate(QtMaterialStyle *q)
    : q_ptr(q)
{
}

QtMaterialStylePrivate::~QtMaterialStylePrivate()
{
}

void QtMaterialStylePrivate::init()
{
    Q_Q(QtMaterialStyle);

    QFontDatabase::addApplicationFont(":/fonts/roboto_regular");
    QFontDatabase::addApplicationFont(":/fonts/roboto_medium");
    QFontDatabase::addApplicationFont(":/fonts/roboto_bold");
    QFontDatabase::addApplicationFont(":/fonts/iconfont");

    q->setTheme(new QtMaterialTheme);
}

/*!
 *  \class QtMaterialStyle
 *  \internal
 */

void QtMaterialStyle::setTheme(QtMaterialTheme *theme)
{
    Q_D(QtMaterialStyle);

    d->theme = theme;
    theme->setParent(this);
}

QColor QtMaterialStyle::themeColor(const QString &key) const
{
    Q_D(const QtMaterialStyle);

    Q_ASSERT(d->theme);

    return d->theme->getColor(key);
}

QtMaterialStyle::QtMaterialStyle()
    : QCommonStyle(),
      d_ptr(new QtMaterialStylePrivate(this))
{
    d_func()->init();
}
