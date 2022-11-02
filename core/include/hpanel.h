#ifndef HPANEL_H
#define HPANEL_H

#include <QWidget>

class HPanelItem;
class HPanelPrivate;
class HPanel : public QWidget
{
    Q_OBJECT

public:
    explicit HPanel(QWidget *parent = nullptr);
    ~HPanel();

    void setTextColor(const QColor &color);
    QColor textColor() const;

    void addStretch();
    void addItem(const QString &text);
    void addLogo();

    void setCurrentItem(HPanelItem *item);
    void setCurrentItem(int index);

    int currentIndex() const;

signals:
    void currentChanged(int);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void setActiveItem(int index, bool active = true);
    void updateItems();

    const QScopedPointer<HPanelPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HPanel)
    Q_DECLARE_PRIVATE(HPanel)
};

#endif
