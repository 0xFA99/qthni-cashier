#ifndef HMATERIALSNACKBAR_P_H
#define HMATERIALSNACKBAR_P_H

#include <QObject>
#include <QColor>

class HMaterialSnackbar;
class HMaterialSnackbarStateMachine;

class HMaterialSnackbarPrivate
{
    Q_DISABLE_COPY(HMaterialSnackbarPrivate);
    Q_DECLARE_PUBLIC(HMaterialSnackbar);

public:
    HMaterialSnackbarPrivate(HMaterialSnackbar *q);
    ~HMaterialSnackbarPrivate();

    void init();

    HMaterialSnackbar               *const q_ptr;
    HMaterialSnackbarStateMachine   *stateMachine;
    QColor                          textColor;
    QColor                          backgroundColor;
    qreal                           bgOpacity;
    QList<QString>                  messages;
    int                             duration;
    int                             boxWidth;
    bool                            clickDismiss;
    bool                            useThemeColors;
};

#endif
