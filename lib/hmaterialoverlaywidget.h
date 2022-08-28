#ifndef HMATERIALOVERLAYWIDGET_H
#define HMATERIALOVERLAYWIDGET_H

#include <QtWidgets/QWidget>

class HMaterialOverlayWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HMaterialOverlayWidget(QWidget *parent = 0);
    ~HMaterialOverlayWidget();

protected:
    bool event(QEvent *event) Q_DECL_OVERRIDE;
    bool eventFilter(QObject *obj, QEvent *event) Q_DECL_OVERRIDE;

    virtual QRect overlayGeometry() const;

private:
    Q_DISABLE_COPY(HMaterialOverlayWidget)
};

#endif
