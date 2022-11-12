#ifndef HNILIB_HPRODUCTITEM_H
#define HNILIB_HPRODUCTITEM_H

#include <QWidget>

#include "hproduct.h"

class HProductItemPrivate;
class HProductItem : public QWidget
{
    Q_OBJECT

public:
    explicit HProductItem(HProduct *product, QWidget *parent = nullptr);
    ~HProductItem();

    void setProductObject(HProduct *product);

    QString name() const;

public slots:
    void editSlot();
    void removeSlot();

    void updateProduct(HProduct *);

signals:
    void editItem(HProduct *);
    void removeItem(const QString &name);

protected:
    const QScopedPointer<HProductItemPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HProductItem)
    Q_DECLARE_PRIVATE(HProductItem)
};

#endif