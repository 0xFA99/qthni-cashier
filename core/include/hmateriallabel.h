#ifndef HMATERIALLABEL_H
#define HMATERIALLABEL_H

#include <QLabel>

#include "hinterfacewidget.h"

enum LabelStyle { Heading, Subheading, Body, Caption };
enum LabelColor { Color1, Color2 };

class HMaterialLabel : public QLabel, public HInterfaceWidget
{
public:
    HMaterialLabel(LabelStyle style = LabelStyle::Body, QWidget *parent = nullptr);
    HMaterialLabel(const QString &text, LabelStyle style = LabelStyle::Body, QWidget *parent = nullptr);
    ~HMaterialLabel();

    void setDarkTheme() override;
    void setLightTheme() override;

    void setStyle(LabelStyle style);
    void setColor(LabelColor color);

private:
    LabelStyle m_style;
    LabelColor m_color;
};

#endif
