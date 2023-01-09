#ifndef QTHNI_PURCHASE_ORDER_DIALOG_H
#define QTHNI_PURCHASE_ORDER_DIALOG_H

#include "widgets/items/finalwidget.h"
#include <QWidget>

class ProductObject;
class PurchaseOrderDialogPrivate;
class PurchaseOrderDialog : public QWidget
{
    Q_OBJECT

public:
    explicit PurchaseOrderDialog(QWidget *parent = nullptr);
    ~PurchaseOrderDialog();

    void addItem(FinalWidget*);

public slots:
    void updateSubTotal(const QString&);
    void deleteItem(QUuid);
    // void updateDiscount(const QString&);
    // void updateTotal(const QString &);

signals:
    void hideDialog();

protected:
    const QScopedPointer<PurchaseOrderDialogPrivate> d_ptr;

private:
    Q_DISABLE_COPY(PurchaseOrderDialog)
    Q_DECLARE_PRIVATE(PurchaseOrderDialog)
};


#endif //QTHNI_PURCHASE_ORDER_DIALOG_H
