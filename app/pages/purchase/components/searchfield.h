#ifndef QTHNI_SEARCHFIELD_H
#define QTHNI_SEARCHFIELD_H

#include <QWidget>

class SearchFieldPrivate;
class SearchField : public QWidget
{
    Q_OBJECT

public:
    explicit SearchField(QWidget *parent = nullptr);
    ~SearchField();

protected:
    const QScopedPointer<SearchFieldPrivate> d_ptr;
    void paintEvent(QPaintEvent *event);

private:
    Q_DISABLE_COPY(SearchField)
    Q_DECLARE_PRIVATE(SearchField)
};

#endif //QTHNI_SEARCHFIELD_H
