#ifndef HPRODUCTCHOOSE_PRIVATE_H
#define HPRODUCTCHOOSE_PRIVATE_H

class HProductChoose;
class HProductChoosePrivate
{
    Q_DISABLE_COPY(HProductChoosePrivate)
    Q_DECLARE_PUBLIC(HProductChoose)

public:
    HProductChoosePrivate(HProductChoose *q);
    ~HProductChoosePrivate();

    void init();

    HProductChoose *const   q_ptr;
};

#endif
