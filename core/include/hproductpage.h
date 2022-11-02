#ifndef HPRODUCTPAGE_H
#define HPRODUCTPAGE_H

#include <QWidget>

class HProductPagePrivate;
class HProductPage : public QWidget
{
    Q_OBJECT

public:
    explicit HProductPage(QWidget *parent = nullptr);
    ~HProductPage();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    const QScopedPointer<HProductPagePrivate> d_ptr;

private:
    Q_DISABLE_COPY(HProductPage)
    Q_DECLARE_PRIVATE(HProductPage)
};

#endif
