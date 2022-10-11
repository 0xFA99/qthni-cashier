#ifndef HMATERIALDIALOG_H
#define HMATERIALDIALOG_H

#include <QScopedPointer>
#include "hmaterialoverlaywidget.h"

class QLayout;
class HMaterialDialogPrivate;

class HMaterialDialog : public HMaterialOverlayWidget
{
    Q_OBJECT

public:
    explicit HMaterialDialog(QWidget *parent = nullptr);
    ~HMaterialDialog();

    QLayout *windowLayout() const;
    void setWindowLayout(QLayout *layout);

public slots:
    void showDialog();
    void hideDialog();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    const QScopedPointer<HMaterialDialogPrivate> d_ptr;

private:
    Q_DISABLE_COPY(HMaterialDialog)
    Q_DECLARE_PRIVATE(HMaterialDialog)
};

#endif
