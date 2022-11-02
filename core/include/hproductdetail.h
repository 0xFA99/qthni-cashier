#ifndef HPRODUCTDETAIL_H
#define HPRODUCTDETAIL_H

#include <QWidget>

class HProductDetailPrivate;
class HProductDetail : public QWidget
{
    Q_OBJECT

public:
    explicit HProductDetail(QWidget *parent = nullptr);
    ~HProductDetail();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    const QScopedPointer<HProductDetailPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HProductDetail)
    Q_DECLARE_PRIVATE(HProductDetail)

};

#endif
