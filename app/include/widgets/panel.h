#ifndef QTHNI_PANEL_H
#define QTHNI_PANEL_H

#include <QWidget>
#include <QIcon>

#include "qtmaterial/lib/qtmaterialtheme.h"

class PanelPrivate;
class PanelTab;

class Panel : public QWidget
{
    Q_OBJECT

public:
    explicit Panel(QWidget *parent = nullptr);
    ~Panel();

    void setUseThemeColors(bool value);
    [[nodiscard]] bool useThemeColors() const;

    void setHaloVisible(bool value);
    [[nodiscard]] bool isHaloVisible() const;

    void setRippleStyle(Material::RippleStyle style);
    [[nodiscard]] Material::RippleStyle rippleStyle() const;

    void setInkColor(const QColor &color);
    [[nodiscard]] QColor inkColor() const;

    void setBackgroundColor(const QColor &color);
    [[nodiscard]] QColor backgroundColor() const;

    void setTextColor(const QColor &color);
    [[nodiscard]] QColor textColor() const;

    void addTab(const QString &text, const QIcon &icon = QIcon());
    void addStretch();

    void setCurrentTab(PanelTab *tab);
    void setCurrentTab(int index);

    [[nodiscard]] int currentIndex() const;

signals:
    void currentChanged(int);

protected:
    void setTabActive(int index, bool active = true);
    void updateTabs();

    const QScopedPointer<PanelPrivate> d_ptr;
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    Q_DISABLE_COPY(Panel)
    Q_DECLARE_PRIVATE(Panel)
};

#endif // QTHNI_PANEL_H
