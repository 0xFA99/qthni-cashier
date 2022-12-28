#ifndef QTHNI_MINIMALITEM_H
#define QTHNI_MINIMALITEM_H

#include "interfaces/IItem.h"
#include "interfaces/IObserver.h"
#include <QWidget>

class MinimalItemPrivate;
class MinimalItem : public QWidget, public IObserver, public IItem
{
    Q_OBJECT

public:
    explicit MinimalItem(QWidget *parent = nullptr);
    ~MinimalItem();

    void Update(const QImage&, const QString&, const QString&) override;
    void extraItem(int) override;

    void setImage(const QImage&) override;

    void setTitle(const QString&) override;
    void setTitleColor(const QColor&) override;

    void setSubTitle(const QString&) override;
    void setSubTitleColor(const QColor&) override;

    void setIndex(int);
    [[nodiscard]] int index() const;

protected:
    const QScopedPointer<MinimalItemPrivate> d_ptr;

private:
    Q_DISABLE_COPY(MinimalItem)
    Q_DECLARE_PRIVATE(MinimalItem)
};

#endif //QTHNI_MINIMALITEM_H
