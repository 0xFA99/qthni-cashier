#ifndef HNILIB_HPRODUCT_P_H
#define HNILIB_HPRODUCT_P_H

#include <QImage>

class HProduct;
class HProductPrivate
{
    Q_DISABLE_COPY(HProductPrivate);
    Q_DECLARE_PUBLIC(HProduct);

public:
    HProductPrivate(HProduct *q);
    ~HProductPrivate();

    void init();

    HProduct *const     q_ptr;

    QImage              m_image;
    QString             m_name;
    int                 m_price;
    int                 m_stock;
};

#endif
