#include <QEvent>

#include "hmaterialoverlaywidget.h"

HMaterialOverlayWidget::HMaterialOverlayWidget(QWidget *parent)
    : QWidget(parent)
{
    if (parent) {
        parent->installEventFilter(this);
    }
}

HMaterialOverlayWidget::~HMaterialOverlayWidget()
{
}

bool HMaterialOverlayWidget::event(QEvent *event)
{
    if (!parent()) {
        return QWidget::event(event);
    }
    switch (event->type())
    {
    case QEvent::ParentChange:
    {
        parent()->installEventFilter(this);
        setGeometry(overlayGeometry());
        break;
    }
    case QEvent::ParentAboutToChange:
    {
        parent()->removeEventFilter(this);
        break;
    }
    default:
        break;
    }
    return QWidget::event(event);
}

bool HMaterialOverlayWidget::eventFilter(QObject *obj, QEvent *event)
{
    switch (event->type())
    {
    case QEvent::Move:
    case QEvent::Resize:
        setGeometry(overlayGeometry());
        break;
    default:
        break;
    }
    return QWidget::eventFilter(obj, event);
}

QRect HMaterialOverlayWidget::overlayGeometry() const
{
    QWidget *widget = parentWidget();
    if (!widget) {
        return QRect();
    }
    return widget->rect();
}
