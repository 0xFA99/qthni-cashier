#ifndef QTHNI_PRODUCTOBJECT_P_H
#define QTHNI_PRODUCTOBJECT_P_H

#include <QImage>
#include <QVector>
#include <QLocale>

class ProductObject;
class ProductObjectPrivate
{
    Q_DISABLE_COPY(ProductObjectPrivate)
    Q_DECLARE_PUBLIC(ProductObject)

public:
    explicit ProductObjectPrivate(ProductObject *q);
    ~ProductObjectPrivate();

    void init();

    ProductObject *const    q_ptr;
    QImage                  m_image;
    QString                 m_name;
    int                     m_price;
    int                     m_point;
    int                     m_stock;

    QLocale                 m_locale;
    QVector<IObserver *>    m_observerList;
};

#endif //QTHNI_PRODUCTOBJECT_P_H
