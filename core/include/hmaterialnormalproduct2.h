#ifndef HMATERIALNORMALPRODUCT_H
#define HMATERIALNORMALPRODUCT_H

#include "hmaterialframe.h"

class HMaterialNormalProductPrivate;
class HMaterialNormalProduct : public HMaterialFrame
{
    Q_OBJECT

public:
    HMaterialNormalProduct(QWidget *parent = nullptr);
    ~HMaterialNormalProduct();

    void setImage(const QImage &image);
    QImage image() const;

    void setTitle(const QString &text);
    QString title() const;

    void setPrice(int price);
    int price() const;

    void setAmount(int amount);
    int amount() const;

protected:
    const QScopedPointer<HMaterialNormalProductPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HMaterialNormalProduct)
    Q_DECLARE_PRIVATE(HMaterialNormalProduct)
};

#endif
