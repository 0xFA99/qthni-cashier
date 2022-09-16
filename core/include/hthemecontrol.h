#ifndef HTHEMECONTROL_H
#define HTHEMECONTROL_H

#include <QVector>

#include "hmaterialflatbutton.h"
#include "hinterfacewidget.h"

enum ThemeMode { Dark, Light };

class HThemeControl : public HMaterialFlatButton
{
    Q_OBJECT

public:
    HThemeControl(HThemeControl &other) = delete;
    void operator=(const HThemeControl &) = delete;

    static HThemeControl *getThemeControl();

    void addControlWidget(HInterfaceWidget *widget);
    void changeTheme();

    ThemeMode m_theme;

protected:
    HThemeControl(QIcon icon, QWidget *parent = nullptr);

    static HThemeControl *m_themeControl;

    QVector<HInterfaceWidget *> m_widgetList;

private:
    void changeColor();
};

#endif
