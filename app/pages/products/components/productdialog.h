#ifndef QTHNI_PRODUCTDIALOG_H
#define QTHNI_PRODUCTDIALOG_H

#include <QWidget>

class ProductObject;
class ProductObjectManager;

class ProductDialogPrivate;
class ProductDialog : public QWidget
{
    Q_OBJECT

public:
    explicit ProductDialog(QWidget *parent = nullptr);
    ~ProductDialog();

    enum Mode { Edit, Add };
    void setMode(Mode mode);

    void setProductFromUUID(QUuid);
    void addProductManager(ProductObjectManager*);

signals:
    void closedProductDialog();
    void addedProduct(ProductObject&);
    void editedProduct(QUuid, ProductObject&);

protected:
    const QScopedPointer<ProductDialogPrivate> d_ptr;

private:
    void clearField();
    void addMode();
    void editMode();
    void chooseImage();

    Q_DISABLE_COPY(ProductDialog)
    Q_DECLARE_PRIVATE(ProductDialog)

private slots:
    void addSlot();
    void editSlot();
};

#endif //QTHNI_PRODUCTDIALOG_H
