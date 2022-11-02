#ifndef HORDERLIST_PRIVATE_H
#define HORDERLIST_PRIVATE_H

#include "hmateriallabel.h"
#include <QWidget>

class QVBoxLayout;

class HOrderList;
class HOrderListPrivate
{
    Q_DISABLE_COPY(HOrderListPrivate)
    Q_DECLARE_PUBLIC(HOrderList)

public:
    HOrderListPrivate(HOrderList *q);
    ~HOrderListPrivate();

    void init();

    HOrderList *const   q_ptr;
    QVBoxLayout         *m_layout;
    HMaterialLabel      *m_title;
    QWidget             *m_orderWorkspace;
    QVBoxLayout         *m_orderLayout;
};

#endif
