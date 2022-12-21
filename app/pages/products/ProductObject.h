#ifndef QTHNI_PRODUCTOBJECT_H
#define QTHNI_PRODUCTOBJECT_H

#include "interfaces/IObserver.h"
#include "interfaces/ISubject.h"
#include <QObject>

class ProductObjectPrivate;
class ProductObject : public QObject, public ISubject
{
public:
    explicit ProductObject(QObject *parent = nullptr);
    ~ProductObject();

    void editProduct(ProductObject*);

    void setImage(const QImage &image);
    [[nodiscard]] QImage image() const;

    void setName(const QString &name);
    [[nodiscard]] QString name() const;

    void setPrice(int price);
    [[nodiscard]] int price() const;

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
