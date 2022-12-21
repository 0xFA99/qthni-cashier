#ifndef QTHNI_RESULTLIST_H
#define QTHNI_RESULTLIST_H

#include <QWidget>

class ProductObject;

class ResultListPrivate;
class ResultList : public QWidget
{
    Q_OBJECT

public:
    explicit ResultList(QWidget *parent = nullptr);
    ~ResultList();

    void addProductObjectShow(ProductObject *);
    void updateProductObjectShow(int, ProductObject *);

signals:
    void addToOrder(ProductObject *);
    void updateToOrder(ProductObject *);

protected:
    const QScopedPointer<ResultListPrivate> d_ptr;

private:
    Q_DISABLE_COPY(ResultList)
    Q_DECLARE_PRIVATE(ResultList)
};

#endif //QTHNI_RESULTLIST_H
