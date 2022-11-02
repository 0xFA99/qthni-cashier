#ifndef HPRODUCTDETAIL_PRIVATE_H
#define HPRODUCTDETAIL_PRIVATE_H

class HProductDetail;
class HProductDetailPrivate
{
    Q_DISABLE_COPY(HProductDetailPrivate)
    Q_DECLARE_PUBLIC(HProductDetail)

public:
    HProductDetailPrivate(HProductDetail *q);
    ~HProductDetailPrivate();

    void init();

    HProductDetail *const   q_ptr;
};

#endif
