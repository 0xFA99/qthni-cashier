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

    void deleteItemPrice(QUuid);

signals:
    void s_submitButton();
    void updateSubTotal(const QString&);
    void updateDiscount(const QString&);
    // void updateTotal(const QString&);

public slots:
    // void changeSubTotal(int,int);
    void changeSubTotal(QUuid, int);
    void changeDiscount(QUuid, int);
    void memberChoosen(bool);

protected:
    const QScopedPointer<PriceWidgetPrivate> d_ptr;

private:
    void updateTotal();

    Q_DISABLE_COPY(PriceWidget)
    Q_DECLARE_PRIVATE(PriceWidget)
};

#endif //QTHNI_PRICEWIDGETS_H
