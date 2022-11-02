#ifndef HPRODUCTRESULT_H
#define HPRODUCTRESULT_H

#include <QWidget>

class HProductResultPrivate;
class HProductResult : public QWidget
{
    Q_OBJECT

public:
    explicit HProductResult(QWidget *parent = nullptr);
    ~HProductResult();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    virtual void paintBackground(QPainter *painter);
    virtual void paintForeground(QPainter *painter);
    const QScopedPointer<HProductResultPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HProductResult)
    Q_DECLARE_PRIVATE(HProductResult)
};

#endif
