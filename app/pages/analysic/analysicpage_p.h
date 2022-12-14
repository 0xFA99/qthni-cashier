#ifndef QTHNI_ANALYSICPAGE_P_H
#define QTHNI_ANALYSICPAGE_P_H

#include "widgets/frametitle.h"
#include "analysic/components/lastpurchase.h"
#include "analysic/components/remainingstock.h"
#include "analysic/components/chartwidget.h"

#include <QScrollArea>

class QHBoxLayout;

class AnalysicPage;
class AnalysicPagePrivate
{
    Q_DISABLE_COPY(AnalysicPagePrivate)
    Q_DECLARE_PUBLIC(AnalysicPage)

public:
    explicit AnalysicPagePrivate(AnalysicPage *q);
    ~AnalysicPagePrivate();

    void init();

    AnalysicPage *const     q_ptr;
    QHBoxLayout             *m_layout;

    FrameTitle              *m_chartFrame;
    ChartWidget             *m_chartWidget;

    FrameTitle              *m_stockFrame;
    QScrollArea             *m_stockScroll;
    RemainingStock          *m_remainingStockWidget;

    FrameTitle              *m_lastPurchaseFrame;
    QScrollArea             *m_lastPurchaseScroll;
    LastPurchase            *m_lastPurchaseWidget;
};

#endif //QTHNI_ANALYSICPAGE_P_H
