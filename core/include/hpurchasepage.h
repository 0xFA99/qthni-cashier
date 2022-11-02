#ifndef HPURCHASEPAGE_H
#define HPURCHASEPAGE_H

#include <QWidget>

class HPurchasePagePrivate;
class HPurchasePage : public QWidget
{
    Q_OBJECT

public:
    explicit HPurchasePage(QWidget *parent = nullptr);
    ~HPurchasePage();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    const QScopedPointer<HPurchasePagePrivate> d_ptr;

private:
    Q_DISABLE_COPY(HPurchasePage)
    Q_DECLARE_PRIVATE(HPurchasePage)
};

#endif
