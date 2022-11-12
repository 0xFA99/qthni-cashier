#ifndef HNILIB_HPRODUCTLIST_H
#define HNILIB_HPRODUCTLIST_H

#include <QWidget>

class HProduct;
class HProductItem;
class HProductListPrivate;
class HProductList : public QWidget
{
    Q_OBJECT

public:
    explicit HProductList(QWidget *parent = nullptr);
    ~HProductList();

    void syncProductDB();
    void performConnection();

public slots:
    void addProduct(const QImage &, const QString &, int, int);
    void editProduct(HProduct *);
    void removeProduct(const QString &);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    const QScopedPointer<HProductListPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HProductList)
    Q_DECLARE_PRIVATE(HProductList)
};

#endif
