#ifndef HPRODUCTNORMALVIEW_H
#define HPRODUCTNORMALVIEW_H

#include <QWidget>

class HProductNormalViewPrivate;
class HProductNormalView : public QWidget
{
    Q_OBJECT

public:
    HProductNormalView(QWidget *parent = nullptr);
    ~HProductNormalView();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    const QScopedPointer<HProductNormalViewPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HProductNormalView)
    Q_DECLARE_PRIVATE(HProductNormalView)
};

#endif
