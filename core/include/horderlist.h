#ifndef HORDERLIST_H
#define HORDERLIST_H

#include <QWidget>

class HOrderListPrivate;
class HOrderList : public QWidget
{
    Q_OBJECT

public:
    explicit HOrderList(QWidget *parent = nullptr);
    ~HOrderList();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    const QScopedPointer<HOrderListPrivate> d_ptr;

    virtual void paintBackground(QPainter *painter);
    virtual void paintForeground(QPainter *painter);

private:
    Q_DISABLE_COPY(HOrderList)
    Q_DECLARE_PRIVATE(HOrderList)
};

#endif
