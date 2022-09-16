#ifndef HMATERIALBADGE_H
#define HMATERIALBADGE_H

#include "hmaterialoverlaywidget.h"

class HMaterialBadgePrivate;

class HMaterialBadge : public HMaterialOverlayWidget
{
    Q_OBJECT

    Q_PROPERTY(QColor textColor WRITE setTextColor READ textColor)
    Q_PROPERTY(QColor backgroundColor WRITE setBackgroundColor READ backgroundColor)
    Q_PROPERTY(QPointF relativePosition WRITE setRelativePosition READ relativePosition)

public:
    explicit HMaterialBadge(QWidget *parent = nullptr);
    explicit HMaterialBadge(const QIcon icon, QWidget *parent = nullptr);
    explicit HMaterialBadge(const QString &text, QWidget *parent = nullptr);
    ~HMaterialBadge();

    void setUseThemeColors(bool value);
    bool useThemeColors() const;

    void setTextColor(const QColor &color);
    QColor textColor() const;

    void setBackgroundColor(const QColor &color);
    QColor backgroundColor() const;

    void setRelativePosition(const QPointF &pos);
    void setRelativePosition(qreal x, qreal y);
    QPointF relativePosition() const;

    void setRelativeXPosition(qreal x);
    qreal relativeXPosition() const;

    void setRelativeYPosition(qreal y);
    qreal relativeYPosition() const;

    QSize sizeHint() const Q_DECL_OVERRIDE;

    void setIcon(const QIcon &icon);
    QIcon icon() const;

    void setText(const QString &text);
    QString text() const;

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

    int getDiameter() const;

    const QScopedPointer<HMaterialBadgePrivate> d_ptr;

private:
    Q_DISABLE_COPY(HMaterialBadge);
    Q_DECLARE_PRIVATE(HMaterialBadge);

};

#endif