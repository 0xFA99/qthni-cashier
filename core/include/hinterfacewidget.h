#ifndef HINTERFACEWIDGET_H
#define HINTERFACEWIDGET_H

class HInterfaceWidget
{
public:
    virtual ~HInterfaceWidget() {}

    virtual void setLightTheme() = 0;
    virtual void setDarkTheme() = 0;
};

#endif
