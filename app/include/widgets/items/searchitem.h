#ifndef QTHNI_SEARCHITEM_H
#define QTHNI_SEARCHITEM_H

#include <QWidget>

class SearchItemPrivate;
class SearchItem : public QWidget
{
    Q_OBJECT

public:
    explicit SearchItem(QWidget *parent = nullptr);
    ~SearchItem();

    void changeStat();

protected:
    const QScopedPointer<SearchItemPrivate> d_ptr;

private:
    Q_DISABLE_COPY(SearchItem)
    Q_DECLARE_PRIVATE(SearchItem)
};

#endif //QTHNI_SEARCHITEM_H