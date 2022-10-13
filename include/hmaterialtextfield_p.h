#ifndef HMATERIALTEXTFIELD_P_H
#define HMATERIALTEXTFIELD_P_H

#include <QtGlobal>
#include <QColor>

class HMaterialTextField;
class HMaterialTextFieldStateMachine;
class HMaterialTextFieldLabel;

class HMaterialTextFieldPrivate
{
    Q_DISABLE_COPY(HMaterialTextFieldPrivate)
    Q_DECLARE_PUBLIC(HMaterialTextField)

public:
    HMaterialTextFieldPrivate(HMaterialTextField *q);
    virtual ~HMaterialTextFieldPrivate();

    void init();

    HMaterialTextField              *const q_ptr;
    HMaterialTextFieldStateMachine  *stateMachine;
    HMaterialTextFieldLabel         *label;
    QColor                          textColor;
    QColor                          labelColor;
    QColor                          inkColor;
    QColor                          inputLineColor;
    QString                         labelString;
    qreal                           labelFontSize;
    bool                            showLabel;
    bool                            showInputLine;
    bool                            useThemeColors;
    bool                            currencyFormat;
};

#endif
