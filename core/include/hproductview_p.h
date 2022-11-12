#ifndef HPRODUCTVIEW_PRIVATE_H
#define HPRODUCTVIEW_PRIVATE_H

#include <QtCore>

class QVBoxLayout;

class HProductView;
class HProductViewPrivate
{
    Q_DISABLE_COPY(HProductViewPrivate)
    Q_DECLARE_PUBLIC(HProductView)

public:
    HProductViewPrivate(HProductView *q);
    ~HProductViewPrivate();

    void init();

    HProductView *const q_ptr;
    QVBoxLayout         *m_layout;
};

#endif