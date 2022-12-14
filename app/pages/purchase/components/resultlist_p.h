#ifndef QTHNI_RESULTLIST_P_H
#define QTHNI_RESULTLIST_P_H

#include <QtCore>

class FlowLayout;

class ResultList;
class ResultListPrivate
{
    Q_DISABLE_COPY(ResultListPrivate)
    Q_DECLARE_PUBLIC(ResultList)

public:
    explicit ResultListPrivate(ResultList *q);
    ~ResultListPrivate();

    void init();

    ResultList *const   q_ptr;
    FlowLayout          *m_layout;
};

#endif //QTHNI_RESULTLIST_P_H
