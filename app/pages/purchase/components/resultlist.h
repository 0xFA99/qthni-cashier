#ifndef QTHNI_RESULTLIST_H
#define QTHNI_RESULTLIST_H

#include <QWidget>

class ResultListPrivate;
class ResultList : public QWidget
{
    Q_OBJECT

public:
    explicit ResultList(QWidget *parent = nullptr);
    ~ResultList();

protected:
    const QScopedPointer<ResultListPrivate> d_ptr;

private:
    Q_DISABLE_COPY(ResultList)
    Q_DECLARE_PRIVATE(ResultList)
};

#endif //QTHNI_RESULTLIST_H
