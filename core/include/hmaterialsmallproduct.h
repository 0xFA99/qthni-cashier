#ifndef HMATERIALSMALLPRODUCT_H
#define HMATERIALSMALLPRODUCT_H

#include "hmaterialframe.h"

class HMaterialSmallProductPrivate;

class HMaterialSmallProduct : public HMaterialFrame
{
    Q_OBJECT

public:
    explicit HMaterialSmallProduct(QWidget *parent = nullptr);
    explicit HMaterialSmallProduct(const QString &title, QWidget *parent = nullptr);
    ~HMaterialSmallProduct();

    void setImage(const QImage &image);

    void setTitle(const QString &text);
    QString title() const;

    void setPrice(int price);
    int price() const;

    void increaseAmount();
    void decreaseAmount();
    int amount() const;

protected:
    const QScopedPointer<HMaterialSmallProductPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HMaterialSmallProduct)
    Q_DECLARE_PRIVATE(HMaterialSmallProduct)
};

#endif
