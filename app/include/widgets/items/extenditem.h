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
    void extraItem(int) override;

    void setImage(const QImage&) override;

    void setTitle(const QString&) override;
    void setTitleColor(const QColor&) override;

    void setSubTitle(const QString&) override;
    void setSubTitleColor(const QColor&) override;

    void setPrice(int);
    [[nodiscard]] int price() const;

    void setStock(int);
    [[nodiscard]] int amount() const;

    void setIndex(int);
    [[nodiscard]] int index() const;

signals:
    void increasePrice(int);
    void decreasePrice(int);

protected:
    const QScopedPointer<ExtendItemPrivate> d_ptr;

private:
    Q_DISABLE_COPY(ExtendItem)
    Q_DECLARE_PRIVATE(ExtendItem)
};

#endif //QTHNI_EXTENDITEM_H
