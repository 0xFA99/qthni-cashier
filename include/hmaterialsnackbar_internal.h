#ifndef HMATERIALSNACKBAR_INTERNAL_H
#define HMATERIALSNACKBAR_INTERNAL_H

#include <QStateMachine>
#include <QTimer>

class HMaterialSnackbar;

class HMaterialSnackbarStateMachine : public QStateMachine
{
    Q_OBJECT

    Q_PROPERTY(qreal offset WRITE setOffset READ offset);

public:
    HMaterialSnackbarStateMachine(HMaterialSnackbar *parent);
    ~HMaterialSnackbarStateMachine();

    void setOffset(qreal offset);
    inline qreal offset() const;

public slots:
    void progress();

protected:
    bool eventFilter(QObject *watched, QEvent *event) Q_DECL_OVERRIDE;

protected slots:
    void snackbarShown();

private:
    Q_DISABLE_COPY(HMaterialSnackbarStateMachine);

    HMaterialSnackbar   *const  m_snackbar;
    QTimer                      m_timer;
    qreal                       m_offset;
};

inline qreal HMaterialSnackbarStateMachine::offset() const
{
    return m_offset;
}

#endif
