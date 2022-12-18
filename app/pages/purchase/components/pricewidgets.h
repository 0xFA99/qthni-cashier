#ifndef QTHNI_PRICEWIDGETS_H
#define QTHNI_PRICEWIDGETS_H

#include <QWidget>

class PriceWidgetPrivate;
class PriceWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PriceWidget(QWidget *parent = nullptr);
    ~PriceWidget();

protected:
    const QScopedPointer<PriceWidgetPrivate> d_ptr;

private:
    Q_DISABLE_COPY(PriceWidget)
    Q_DECLARE_PRIVATE(PriceWidget)
};

#endif //QTHNI_PRICEWIDGETS_H
