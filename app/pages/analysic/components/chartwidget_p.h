#ifndef QTHNI_CHARTWIDGET_P_H
#define QTHNI_CHARTWIDGET_P_H

#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

#include "qtmaterial/components/qtmaterialflatbutton.h"

class QGridLayout;

class ChartWidget;
class ChartWidgetPrivate
{
    Q_DISABLE_COPY(ChartWidgetPrivate)
    Q_DECLARE_PUBLIC(ChartWidget)

public:
    explicit ChartWidgetPrivate(ChartWidget *q);
    ~ChartWidgetPrivate();

    void init();

    ChartWidget *const      q_ptr;
    QGridLayout             *m_layout;
    QtCharts::QChart        *m_chart;
    QtCharts::QChartView    *m_chartView;
    QtCharts::QLineSeries   *m_chartLine;

    QtMaterialFlatButton    *m_pointButton;
    QtMaterialFlatButton    *m_profitButton;
};

#endif //QTHNI_CHARTWIDGET_P_H
