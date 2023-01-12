#include "analysic/components/chartwidget.h"
#include "analysic/components/chartwidget_p.h"

#include <QGridLayout>

ChartWidgetPrivate::ChartWidgetPrivate(ChartWidget *q)
    : q_ptr(q)
{
}

ChartWidgetPrivate::~ChartWidgetPrivate() = default;

void ChartWidgetPrivate::init()
{
    Q_Q(ChartWidget);

    m_layout    = new QGridLayout(q);
    m_chart     = new QtCharts::QChart;
    m_chartView = new QtCharts::QChartView(m_chart);
    m_chartLine = new QtCharts::QLineSeries;

    m_pointButton   = new QtMaterialFlatButton("Point", q);
    m_profitButton  = new QtMaterialFlatButton("Profit", q);

    m_pointButton->setRole(Material::Secondary);
    m_profitButton->setRole(Material::Primary);

    m_chartView->setRenderHint(QPainter::Antialiasing);

    m_chart->legend()->hide();
    m_chart->addSeries(m_chartLine);
    m_chart->createDefaultAxes();
    m_chart->setTitle("Grafik Penjualan HNI");

    /*
    m_chartLine->append(0.4, 0.6);
    m_chartLine->append(0.1, 0.5);
     */

    m_layout->addWidget(m_chartView, 0, 0, 1, 2);
    m_layout->addWidget(m_pointButton, 1, 0, 1, 1);
    m_layout->addWidget(m_profitButton, 1, 1, 1, 1);

    QObject::connect(m_pointButton, &QPushButton::clicked, [q]() {
        q->setToPoint();
    });

    QObject::connect(m_profitButton, &QPushButton::clicked, [q]() {
        q->setToCount();
    });
}

ChartWidget::ChartWidget(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new ChartWidgetPrivate(this))
{
    d_func()->init();
}

ChartWidget::~ChartWidget() = default;

void ChartWidget::setToPoint()
{
    Q_D(ChartWidget);

    d->m_chart->setTitle("Hasil Point dalam Seminggu");
}

void ChartWidget::setToCount()
{
    Q_D(ChartWidget);

    d->m_chart->setTitle("Jumlah Penjualan dalam Seminggu");
}
