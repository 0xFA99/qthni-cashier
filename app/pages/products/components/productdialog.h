#ifndef QTHNI_PRODUCTDIALOG_H
#define QTHNI_PRODUCTDIALOG_H

#include <QWidget>

class Product;

class ProductDialogPrivate;
class ProductDialog : public QWidget
{
    Q_OBJECT

public:
    explicit ProductDialog(QWidget *parent = nullptr);
    ~ProductDialog();

    enum Mode { Edit, Add };
    void setMode(Mode mode);

    void setNameField(const QString &name);
    void setPriceField(int price);
    void setStockField(int stock);
    void setPointField(int point);
    void setIndex(int index);

signals:
    void closedProductDialog();
    void addedProduct(Product *);
    void editedProduct(int, Product *);

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
