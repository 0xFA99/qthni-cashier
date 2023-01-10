#ifndef QTHNI_FINALWIDGET_P_H
#define QTHNI_FINALWIDGET_P_H

#include "qtmaterial/components/qtmaterialimage.h"

#include <QUuid>
#include <QLocale>

class QHBoxLayout;
class QLabel;

class FinalWidget;
class FinalWidgetPrivate
{
    Q_DISABLE_COPY(FinalWidgetPrivate)
    Q_DECLARE_PUBLIC(FinalWidget)

public:
    explicit FinalWidgetPrivate(FinalWidget *q);
    ~FinalWidgetPrivate();

    void init();

    FinalWidget *const q_ptr;

    QHBoxLayout                 *m_layout;
    QtMaterialImage             *m_avatar;
    QLabel                      *m_name;
    QLabel                      *m_price;
    QLabel                      *m_discount;
    QLabel                      *m_quantity;
    QLabel                      *m_total;
    QLocale                     m_locale;
    QUuid                       m_uuid;
};

#endif //QTHNI_FINALWIDGET_P_H
