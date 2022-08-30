#ifndef HMATERIALTABS_H
#define HMATERIALTABS_H

#include <QWidget>
#include <QIcon>

#include "hmaterialtheme.h"

class HMaterialTabsPrivate;
class HMaterialTabsTab;

class HMaterialTabs : public QWidget
{
    Q_OBJECT

public:
    explicit HMaterialTabs(QWidget *parent = nullptr);
    ~HMaterialTabs();

    void setUseThemeColors(bool value);
    bool useThemeColors() const;

    void setHaloVisible(bool value);
    bool isHaloVisible() const;

    void setRippleStyle(HMaterial::RippleStyle style);
    HMaterial::RippleStyle rippleStyle() const;

    void setInkColor(const QColor &color);
    QColor inkColor() const;

    void setBackgroundColor(const QColor &color);
    QColor backgroundColor() const;

    void setTextColor(const QColor &color);
    QColor textColor() const;

    void addTab(const QString &text, const QIcon &icon = QIcon());
    void setCurrentTab(HMaterialTab *tab);
    void setCurrentTab(int index);

    int currentIndex() const;

signals:
    void currentChanged(int);

protected:
    void setTabActive(int index, bool active = true);
    void updateTabs();

    const QScopedPointer<HMaterialTabsPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HMaterialTabs);
    Q_DECLARE_PRIVATE(HMaterialTabs);
};

#endif
