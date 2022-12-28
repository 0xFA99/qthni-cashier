#ifndef QTHNI_SEARCHITEM_H
#define QTHNI_SEARCHITEM_H

#include "interfaces/IItem.h"
#include "interfaces/IObserver.h"

#include <QWidget>

class SearchItemPrivate;
class SearchItem : public QWidget, public IObserver, public IItem
{
    Q_OBJECT

public:
    explicit SearchItem(QWidget *parent = nullptr);
    ~SearchItem();

    void Update(const QImage&, const QString&, const QString&) override;

    void setImage(const QImage&) override;

    void setTitle(const QString&) override;
    void setTitleColor(const QColor&) override;

    void setSubTitle(const QString&) override;
    void setSubTitleColor(const QColor&) override;

    void setIndex(int);
    [[nodiscard]] int index() const;

    void changeStat();

signals:
    void addedToOrder(int);
    void deleteToOrder(int);

protected:
    const QScopedPointer<SearchItemPrivate> d_ptr;

private:
    Q_DISABLE_COPY(SearchItem)
    Q_DECLARE_PRIVATE(SearchItem)
};

#endif //QTHNI_SEARCHITEM_H
