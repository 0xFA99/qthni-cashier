#ifndef HMATERIALFRAME_H
#define HMATERIALFRAME_H

#include <QList>
#include <QWidget>

#include "hmaterialtheme.h"
#include "hinterfacewidget.h"

class HMaterialFramePrivate;

class HMaterialFrame : public QWidget, public HInterfaceWidget
{
    Q_OBJECT

public:
    explicit HMaterialFrame(QWidget *parent = nullptr);
    explicit HMaterialFrame(HMaterial::FrameStyle style, QWidget *parent = nullptr);
    ~HMaterialFrame();

    void setDarkTheme() override;
    void setLightTheme() override;

    void setCornerRadius(qreal radius);
    qreal getCornerRadius() const;

    void paintBackground(QPainter *painter);
    QColor getBackground() const;

    void setFollowTheme(bool value);
    bool isFollowTheme() const;

    void setBackgroundColor(const QColor &color);
    QColor backgroundColor() const;

    void setFrameStyle(HMaterial::FrameStyle style);
    HMaterial::FrameStyle frameStyle() const;

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    const QScopedPointer<HMaterialFramePrivate> d_ptr;

private:
    Q_DISABLE_COPY(HMaterialFrame);
    Q_DECLARE_PRIVATE(HMaterialFrame);
};

#endif
