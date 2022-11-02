#ifndef HPRODUCTCHOOSE_H
#define HPRODUCTCHOOSE_H

#include <QWidget>

class HProductChoosePrivate;
class HProductChoose : public QWidget
{
    Q_OBJECT

public:
    explicit HProductChoose(QWidget *parent = nullptr);
    ~HProductChoose();

protected:
    void paintEvent(QPaintEvent *event);
    const QScopedPointer<HProductChoosePrivate> d_ptr;

private:
    Q_DISABLE_COPY(HProductChoose)
    Q_DECLARE_PRIVATE(HProductChoose)
};

#endif
