#ifndef HPRODUCTRESULT_PRIVATE_H
#define HPRODUCTRESULT_PRIVATE_H

#include <QScrollArea>

class QGridLayout;

class HProductResult;
class HProductResultPrivate
{
    Q_DISABLE_COPY(HProductResultPrivate)
    Q_DECLARE_PUBLIC(HProductResult)

public:
    HProductResultPrivate(HProductResult *q);
    ~HProductResultPrivate();

    void init();

    HProductResult *const   q_ptr;
    QGridLayout             *m_layout;
    QScrollArea             *m_scroll;
};

#endif
