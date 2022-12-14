#ifndef QTHNI_CHARTWIDGET_H
#define QTHNI_CHARTWIDGET_H

#include <QWidget>

class ChartWidgetPrivate;
class ChartWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChartWidget(QWidget *parent = nullptr);
    ~ChartWidget();

    void setToPoint();
    void setToCount();


protected:
    const QScopedPointer<ChartWidgetPrivate> d_ptr;

private:
    Q_DISABLE_COPY(ChartWidget)
    Q_DECLARE_PRIVATE(ChartWidget)
};

#endif //QTHNI_CHARTWIDGET_H
