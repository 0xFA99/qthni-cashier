#ifndef HPRODUCTVIEW_H
#define HPRODUCTVIEW_H

#include <QWidget>

class HProduct;
class HProductItem;
class HProductViewPrivate;
class HProductView : public QWidget
{
    Q_OBJECT

public:
    explicit HProductView(QWidget *parent = nullptr);
    ~HProductView();

public slots:
    void addItem(HProductItem *);
    void removeItem(const QString &name);

protected:
    const QScopedPointer<HProductViewPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HProductView)
    Q_DECLARE_PRIVATE(HProductView)
};

#endif