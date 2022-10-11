#ifndef HMATERIALDIALOG_INTERNAL_H
#define HMATERIALDIALOG_INTERNAL_H

#include <QWidget>

class QStackedLayout;
class HMaterialDialog;
class HMaterialDialogWindow;

class HMaterialDialogProxy : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(qreal opacity WRITE setOpacity READ opacity)

    enum TransparencyMode {
        Transparent,
        SemiTransparent,
        Opaque
    };

public:
    HMaterialDialogProxy(HMaterialDialogWindow *source,
                         QStackedLayout *layout,
                         HMaterialDialog *dialog,
                         QWidget *parent = nullptr);
    ~HMaterialDialogProxy();

    void setOpacity(qreal opacity);
    inline qreal opacity() const;

protected:
    bool event(QEvent *event) Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

protected slots:
    void makeOpaque();
    void makeTransparent();

    QSize sizeHint() const Q_DECL_OVERRIDE;

private:
    Q_DISABLE_COPY(HMaterialDialogProxy)

    HMaterialDialogWindow *const    m_source;
    QStackedLayout        *const    m_layout;
    HMaterialDialog       *const    m_dialog;
    qreal                           m_opacity;
    TransparencyMode                m_mode;
};

inline qreal HMaterialDialogProxy::opacity() const
{
    return m_opacity;
}

class HMaterialDialogWindow : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(int offset WRITE setOffset READ offset)

public:
    explicit HMaterialDialogWindow(HMaterialDialog *dialog, QWidget *parent = nullptr);
    ~HMaterialDialogWindow();

    void setOffset(int offset);
    int offset() const;

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    Q_DISABLE_COPY(HMaterialDialogWindow);

    HMaterialDialog *const  m_dialog;
};

#endif
