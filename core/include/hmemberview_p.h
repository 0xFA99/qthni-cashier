#ifndef HMEMBERVIEW_PRIVATE_H
#define HMEMBERVIEW_PRIVATE_H

#include <QtCore>

class QVBoxLayout;

class HMemberView;
class HMemberViewPrivate
{
    Q_DISABLE_COPY(HMemberViewPrivate)
    Q_DECLARE_PUBLIC(HMemberView)

public:
    HMemberViewPrivate(HMemberView *q);
    ~HMemberViewPrivate();

    void init();

    HMemberView *const  q_ptr;
    QVBoxLayout         *m_layout;
};

#endif
