#ifndef HPRODUCTSMALLVIEW_H
#define HPRODUCTSMALLVIEW_H

#include <QWidget>

class HProductSmallViewPrivate;
class HProductSmallView : public QWidget
{
    Q_OBJECT

public:
    HProductSmallView(QWidget *parent = nullptr);
    ~HProductSmallView();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    const QScopedPointer<HProductSmallViewPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HProductSmallView)
    Q_DECLARE_PRIVATE(HProductSmallView)
};

#endif
