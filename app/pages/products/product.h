#ifndef QTHNI_PRODUCT_H
#define QTHNI_PRODUCT_H

#include <QObject>

class ProductPrivate;
class Product : public QObject
{
public:
    explicit Product(QObject *parent = nullptr);
    ~Product();

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

protected:
    const QScopedPointer<ProductPrivate> d_ptr;

private:
    Q_DISABLE_COPY(Product)
    Q_DECLARE_PRIVATE(Product)
};

#endif //QTHNI_PRODUCT_H
