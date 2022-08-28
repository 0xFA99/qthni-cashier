#ifndef HMATERIALICONBUTTON_H
#define HMATERIALICONBUTTON_H

#include <QAbstractButton>

class HMaterialIconButtonPrivate;

class HMaterialIconButton : public QAbstractButton
{
    Q_OBJECT

public:
    explicit HMaterialIconButton(const QIcon &icon, QWidget *parent = nullptr);
    ~HMaterialIconButton();

    QSize sizeHint() const Q_DECL_OVERRIDE;

    void setUseThemeColors(bool value);
    bool useThemeColors() const;

    void setColor(const QColor &color);
    QColor color() const;

    void setDisabledColor(const QColor &color);
    QColor disabledColor() const;

protected:
    HMaterialIconButton(HMaterialIconButtonPrivate &d, QWidget *parent = nullptr);

    bool event(QEvent *event) Q_DECL_OVERRIDE;
    bool eventFilter(QObject *obj, QEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

    const QScopedPointer<HMaterialIconButtonPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HMaterialIconButton);
    Q_DECLARE_PRIVATE(HMaterialIconButton);
};

#endif
