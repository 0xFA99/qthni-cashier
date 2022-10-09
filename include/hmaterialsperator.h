#ifndef HMATERIALSPERATOR_H
#define HMATERIALSPERATOR_H

#include <QWidget>

#include "hinterfacewidget.h"

class HMaterialSperatorPrivate;
class HMaterialSperator : public QWidget, public HInterfaceWidget
{
public:
    HMaterialSperator(QWidget *parent = nullptr);
    ~HMaterialSperator();

    void setDarkTheme() override;
    void setLightTheme() override;

    void setSperatorWidth(int value);
    int speratorWidth() const;

    void setSperatorColor(const QColor &color);
    QColor speratorColor() const;

    void setSperatorStyle(Qt::PenStyle style);
    Qt::PenStyle speratorStyle() const;

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    const QScopedPointer<HMaterialSperatorPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HMaterialSperator)
    Q_DECLARE_PRIVATE(HMaterialSperator)
};

#endif
