#ifndef HORDERPRICE_H
#define HORDERPRICE_H

#include <QWidget>

class HOrderPricePrivate;
class HOrderPrice : public QWidget
{
    Q_OBJECT

public:
    explicit HOrderPrice(QWidget *parent = nullptr);
    ~HOrderPrice();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    const QScopedPointer<HOrderPricePrivate> d_ptr;

private:
    Q_DISABLE_COPY(HOrderPrice)
    Q_DECLARE_PRIVATE(HOrderPrice)
};

#endif
