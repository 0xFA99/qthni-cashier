#ifndef HMATERIALFAB_H
#define HMATERIALFAB_H

#include "hmaterialraisedbutton.h"

class HMaterialFloatingActionButtonPrivate;

class HMaterialFloatingActionButton : public HMaterialRaisedButton
{
    Q_OBJECT

public:
    explicit HMaterialFloatingActionButton(const QIcon &icon, QWidget *parent = 0);
    ~HMaterialFloatingActionButton();

    QSize sizeHint() const Q_DECL_OVERRIDE;

    void setMini(bool state);
    bool isMini() const;

    void setCorner(Qt::Corner corner);
    Qt::Corner corner() const;

    void setOffset(int x, int y);
    QSize offset() const;

    void setXOffset(int x);
    int xOffset() const;

    void setYOffset(int y);
    int yOffset() const;

protected:
    bool event(QEvent *event) Q_DECL_OVERRIDE;
    bool eventFilter(QObject *obj, QEvent *event) Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

    void updateClipPath() Q_DECL_OVERRIDE;

private:
    Q_DISABLE_COPY(HMaterialFloatingActionButton)
    Q_DECLARE_PRIVATE(HMaterialFloatingActionButton)

};

#endif // HMATERIALFAB_H
