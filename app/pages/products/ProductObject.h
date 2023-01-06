#ifndef QTHNI_PRODUCTOBJECT_H
#define QTHNI_PRODUCTOBJECT_H

#include "interfaces/IObserver.h"
#include "interfaces/ISubject.h"

#include <QObject>
#include <QUuid>

#include "products/product_tag.h"

class ProductObjectPrivate;
class ProductObject : public QObject, public ISubject
{
public:
    explicit ProductObject(QObject *parent = nullptr);
    ~ProductObject();

    void editProduct(ProductObject&);

    void setUUID(QUuid);
    [[nodiscard]] QUuid uuid() const;

    void setImage(const QImage &image);
    [[nodiscard]] QImage image() const;

    void setName(const QString &name);
    [[nodiscard]] QString name() const;

    void setTagUUID(const QUuid &uuid);
    [[nodiscard]] QUuid tagUUID() const;

    void setStatus(const QString &status);
    QString status() const;

    void setMemberPrice(int);
    [[nodiscard]] int memberPrice() const;

    void setCustomerPrice(int);
    [[nodiscard]] int customerPrice() const;

    void setPoint(int point);
    [[nodiscard]] int point() const;

    void setStock(int stock);
    [[nodiscard]] int stock() const;

    void Attach(IObserver *) override;
    void Detach(IObserver *) override;
    void Update() override;

protected:
    const QScopedPointer<ProductObjectPrivate> d_ptr;

private:
    Q_DISABLE_COPY(ProductObject)
    Q_DECLARE_PRIVATE(ProductObject)
};

#endif //QTHNI_PRODUCTOBJECT_H
