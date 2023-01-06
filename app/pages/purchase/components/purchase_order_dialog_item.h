#ifndef QTHNI_PURCHASE_ORDER_DIALOG_ITEM_H
#define QTHNI_PURCHASE_ORDER_DIALOG_ITEM_H

#include "qtmaterial/components/qtmaterialavatar.h"

#include <QLocale>
#include <QWidget>
#include <QLabel>
#include <QUuid>

class QHBoxLayout;

class PurchaseOrderDialogItem : public QWidget
{
public:
    explicit PurchaseOrderDialogItem(QWidget *parent = nullptr);
    ~PurchaseOrderDialogItem();

    void setImage(const QImage &image);
    void setName(const QString &name);
    void setPrice(int);
    void setDiscount(int);
    void setQuantity(int);

    void setUUID(const QUuid&);
    [[nodiscard]] QUuid uuid() const;

public slots:
    void updateQuantity(int);

protected:
    void paintEvent(QPaintEvent *painter) Q_DECL_OVERRIDE;

private:
    QHBoxLayout         *m_layout;
    QtMaterialAvatar    *m_avatar;
    QLabel              *m_name;
    QLabel              *m_price;
    QLabel              *m_discount;
    QLabel              *m_quantity;
    QLabel              *m_total;
    QLocale             m_locale;
    QUuid               m_uuid;
};
#endif //QTHNI_PURCHASE_ORDER_DIALOG_ITEM_H
