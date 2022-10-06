#ifndef HMATERIALSMALLPRODUCT_H
#define HMATERIALSMALLPRODUCT_H

#include "hmaterialframe.h"

class HMaterialSmallProductPrivate;

class HMaterialSmallProduct : public HMaterialFrame
{
    Q_OBJECT

public:
    HMaterialSmallProduct(QWidget *parent = nullptr);
    HMaterialSmallProduct(const QString &image, const QString &title, int price, QWidget *parent); 
    ~HMaterialSmallProduct();

    void setImage(const QString &image);
    QPixmap image() const;

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
