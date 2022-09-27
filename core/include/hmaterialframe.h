#ifndef HMATERIALFRAME_H
#define HMATERIALFRAME_H

#include <QList>
#include <QWidget>

#include "hinterfacewidget.h"

class HMaterialFramePrivate;

class HMaterialFrame : public QWidget, HInterfaceWidget
{
    Q_OBJECT

public:
    explicit HMaterialFrame(QWidget *parent = nullptr);
    explicit HMaterialFrame(int level = 1, QWidget *parent = nullptr);
    ~HMaterialFrame();

    void setDarkTheme() override;
    void setLightTheme() override;

    void setLevelColor(int level);
    int getLevelColor() const;

    void setCornerRadius(qreal radius);
    qreal getCornerRadius() const;

    void paintBackground(QPainter *painter);
    QColor getBackground() const;

    void setFollowTheme(bool value);
    bool isFollowTheme() const;

    void setBackgroundColor(const QColor &color);
    QColor backgroundColor() const;

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    const QScopedPointer<HMaterialFramePrivate> d_ptr;

private:
    Q_DISABLE_COPY(HMaterialFrame);
    Q_DECLARE_PRIVATE(HMaterialFrame);
};

#endif
