#ifndef QTHNI_PURCHASEPAGE_H
#define QTHNI_PURCHASEPAGE_H

#include <QWidget>

class PurchasePagePrivate;
class PurchasePage : public QWidget
{
    Q_OBJECT

public:
    explicit PurchasePage(QWidget *parent = nullptr);
    ~PurchasePage();

protected:
    const QScopedPointer<PurchasePagePrivate> d_ptr;

private:
    Q_DISABLE_COPY(PurchasePage)
    Q_DECLARE_PRIVATE(PurchasePage)
};

#endif //QTHNI_PURCHASEPAGE_H
