#ifndef HPRODUCTDETAIL_H
#define HPRODUCTDETAIL_H

#include "hmaterialframe.h"

class HProductDetailPrivate;
class HProductDetail : public HMaterialFrame
{
    Q_OBJECT

public:
    HProductDetail(QWidget *parent = nullptr);
    ~HProductDetail();

protected:
    const QScopedPointer<HProductDetailPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HProductDetail)
    Q_DECLARE_PRIVATE(HProductDetail)
};

#endif
