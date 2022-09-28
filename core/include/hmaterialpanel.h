#ifndef HMATERIALPANEL_H
#define HMATERIALPANEL_H

#include "hmaterialframe.h"

#include "hmaterialtheme.h"

class HMaterialPanelPrivate;
class HMaterialPanelItem;

class HMaterialPanel : public HMaterialFrame
{
    Q_OBJECT

public:
    explicit HMaterialPanel(QWidget *parent = nullptr);
    ~HMaterialPanel();

    void setRippleStyle(HMaterial::RippleStyle style);
    HMaterial::RippleStyle rippleStyle() const;

    void addStretch(int value);
    void addThemeControl();

    void setBackgroundColor(const QColor &color);
    QColor backgroundColor() const;

    void setTextColor(const QColor &color);
    QColor textColor() const;

    void addItem(const QIcon &icon = QIcon(), const QString &text = "");
    void setCurrentItem(HMaterialPanelItem *item);
    void setCurrentItem(int index);

    int currentIndex() const;

signals:
    void currentChanged(int);

protected:
    void setItemActive(int index, bool active = true);
    void updateItems();

    const QScopedPointer<HMaterialPanelPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HMaterialPanel)
    Q_DECLARE_PRIVATE(HMaterialPanel)
};

#endif
