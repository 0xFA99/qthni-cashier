#ifndef QTHNI_RESULTLIST_H
#define QTHNI_RESULTLIST_H

#include <QWidget>

#include "products/product.h"

class ResultListPrivate;
class ResultList : public QWidget
{
    Q_OBJECT

public:
    explicit ResultList(QWidget *parent = nullptr);
    ~ResultList();

    void addProductShow(Product *);
    void updateProductShow(int, Product *);

signals:
    void addToOrder(Product *);
    void updateToOrder(Product *);

protected:
    const QScopedPointer<ResultListPrivate> d_ptr;

private:
    Q_DISABLE_COPY(ResultList)
    Q_DECLARE_PRIVATE(ResultList)
};

#endif //QTHNI_RESULTLIST_H
