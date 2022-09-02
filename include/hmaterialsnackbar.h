#ifndef HMATERIALSNACKBAR_H
#define HMATERIALSNACKBAR_H

#include "hmaterialoverlaywidget.h"

class HMaterialSnackbarPrivate;

class HMaterialSnackbar : public HMaterialOverlayWidget
{
    Q_OBJECT

public:
    explicit HMaterialSnackbar(QWidget *parent = nullptr);
    ~HMaterialSnackbar();

    void setAutoHideDuration(int duration);
    int autoHideDuration() const;

    void setUseThemeColors(bool value);
    bool useThemeColors() const;

    void setBackgroundColor(const QColor &color);
    QColor backgroundColor() const;

    void setBackgroundOpacity(qreal opacity);
    qreal backgroundOpacity() const;

    void setTextColor(const QColor &color);
    QColor textColor() const;

    void setFontSize(qreal size);
    qreal fontSize() const;

    void setBoxWidth(int width);
    int boxWidth() const;

    void setClickToDismissMode(bool value);
    bool clickToDismissMode() const;

public slots:
    void addMessage(const QString &message);
    void addInstantMessage(const QString &message);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

    const QScopedPointer<HMaterialSnackbarPrivate> d_ptr;

protected slots:
    void dequeue();

private:
    Q_DISABLE_COPY(HMaterialSnackbar);
    Q_DECLARE_PRIVATE(HMaterialSnackbar);
};

#endif
