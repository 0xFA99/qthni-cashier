#ifndef HMATERIALFLATBUTTON_H
#define HMATERIALFLATBUTTON_H

#include <QtWidgets/QPushButton>
#include <QScopedPointer>

#include "../lib/hmaterialtheme.h"

class HMaterialFlatButtonPrivate;

class HMaterialFlatButton : public QPushButton
{
    Q_OBJECT

    Q_PROPERTY(QColor foregroundColor WRITE setForegroundColor READ foregroundColor)
    Q_PROPERTY(QColor backgroundColor WRITE setBackgroundColor READ backgroundColor)
    Q_PROPERTY(QColor overlayColor WRITE setOverlayColor READ overlayColor)
    Q_PROPERTY(QColor disabledForegroundColor WRITE setDisabledForegroundColor READ disabledForegroundColor)
    Q_PROPERTY(QColor disabledBackgroundColor WRITE setDisabledBackgroundColor READ disabledBackgroundColor)
    Q_PROPERTY(qreal fontSize WRITE setFontSize READ fontSize)

public:
    explicit HMaterialFlatButton(QWidget *parent = nullptr, HMaterial::ButtonPreset preset = HMaterial::FlatPreset);
    explicit HMaterialFlatButton(const QString &text, QWidget *parent = nullptr, HMaterial::ButtonPreset preset = HMaterial::FlatPreset);
    HMaterialFlatButton(const QString &text, HMaterial::Role role, QWidget *parent = nullptr, HMaterial::ButtonPreset preset = HMaterial::FlatPreset);
    ~HMaterialFlatButton();

    void applyPreset(HMaterial::ButtonPreset preset);

    void setUseThemeColors(bool value);
    bool useThemeColors() const;

    void setRole(HMaterial::Role role);
    HMaterial::Role role() const;

    void setForegroundColor(const QColor &color);
    QColor foregroundColor() const;

    void setBackgroundColor(const QColor &color);
    QColor backgroundColor() const;

    void setOverlayColor(const QColor &color);
    QColor overlayColor() const;

    void setDisabledForegroundColor(const QColor &color);
    QColor disabledForegroundColor() const;

    void setDisabledBackgroundColor(const QColor &color);
    QColor disabledBackgroundColor() const;

    void setFontSize(qreal size);
    qreal fontSize() const;

    void setHaloVisible(bool visible);
    bool isHaloVisible() const;

    void setOverlayStyle(HMaterial::OverlayStyle syle);
    HMaterial::OverlayStyle overlayStyle() const;

    void setRippleStyle(HMaterial::RippleStyle style);
    HMaterial::RippleStyle rippleStyle() const;

    void setIconPlacement(HMaterial::ButtonIconPlacement placement);
    HMaterial::ButtonIconPlacement iconPlacement() const;

    void setCornerRadius(qreal radius);
    qreal cornerRadius() const;

    void setBackgroundMode(Qt::BGMode mode);
    Qt::BGMode backgroundMode() const;

    void setBaseOpacity(qreal opacity);
    qreal baseOpacity() const;

    void setCheckable(bool value);

    void setHasFixedRippleRadius(bool value);
    bool hasFixedRippleRadius() const;

    void setFixedRippleRadius(qreal radius);

    void setTextAlignment(Qt::Alignment alignment);
    Qt::Alignment textAlignment() const;

    QSize sizeHint() const Q_DECL_OVERRIDE;

protected:
    enum {
        IconPadding = 12
    };

    HMaterialFlatButton(HMaterialFlatButtonPrivate &d, QWidget *parent = nullptr, HMaterial::ButtonPreset preset = HMaterial::FlatPreset);

    void checkStateSet() Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

    virtual void paintBackground(QPainter *painter);
    virtual void paintHalo(QPainter *painter);
    virtual void paintForeground(QPainter *painter);

    virtual void updateClipPath();

    const QScopedPointer<HMaterialFlatButtonPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HMaterialFlatButton)
    Q_DECLARE_PRIVATE(HMaterialFlatButton)
};

#endif
