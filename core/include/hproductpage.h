#ifndef HPRODUCTPAGE_H
#define HPRODUCTPAGE_H

#include "hmaterialframe.h"

class HProductPagePrivate;
class HProductPage : public HMaterialFrame
{
    Q_OBJECT

public:
    HProductPage(QWidget *parent = nullptr);
    ~HProductPage();

protected:
    const QScopedPointer<HProductPage> d_ptr;

private:
    Q_DISABLE_COPY(HProductPage)
    Q_DECLARE_PRIVATE(HProductPage)
};

#endif
