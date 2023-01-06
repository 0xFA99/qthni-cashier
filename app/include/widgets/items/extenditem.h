#ifndef QTHNI_EXTENDITEM_H
#define QTHNI_EXTENDITEM_H

#include "interfaces/IItem.h"
#include "interfaces/IObserver.h"
#include <QWidget>

class ExtendItemPrivate;
class ExtendItem : public QWidget, public IObserver, public IItem
{
    Q_OBJECT

public:
    explicit ExtendItem(QWidget *parent = nullptr);
    ~ExtendItem();

    void Update(const QImage&, const QString&, const QString&) override;
    void ExtraUpdate(const QUuid&, int, int, int, int) override;

    void setImage(const QImage&) override;

    void setTitle(const QString&) override;
    void setTitleColor(const QColor&) override;

    void setSubTitle(const QString&) override;
    void setSubTitleColor(const QColor&) override;

    void setMemberPrice(int);
    [[nodiscard]] int memberPrice() const;

    void setCustomerPrice(int);
    [[nodiscard]] int customerPrice() const;

    void setStock(int);

    void setUUID(const QUuid&);
    [[nodiscard]] QUuid uuid() const;

signals:
    // void changeSubPrice(int, int);
    void changeSubPrice(QUuid, int);
    void changeDiscount(QUuid, int);
    void updateAmount(int);

protected:
    const QScopedPointer<ExtendItemPrivate> d_ptr;

private:
    Q_DISABLE_COPY(ExtendItem)
    Q_DECLARE_PRIVATE(ExtendItem)
};

#endif //QTHNI_EXTENDITEM_H
