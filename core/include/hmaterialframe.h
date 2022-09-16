#ifndef HMATERIALFRAME_H
#define HMATERIALFRAME_H

#include <QList>
#include <QColor>
#include <QWidget>

#include "hinterfacewidget.h"

enum LevelColor { Level1, Level2, Level3, Level4 };

class HMaterialFrame : public QWidget, public HInterfaceWidget
{
    Q_OBJECT

public:
    HMaterialFrame(QWidget *parent = nullptr);
    HMaterialFrame(LevelColor level, QWidget *parent = nullptr);
    ~HMaterialFrame();

    void setDarkTheme() override;
    void setLightTheme() override;

    void setLevelColor(LevelColor level);
    void setCornerRadius(qreal radius);

protected:
    void paintEvent(QPaintEvent *event);

private:
    QColor m_backgroundColor;
    qreal m_roundCorner;

    LevelColor m_level;

    QList<QColor> m_darkColors;
    QList<QColor> m_lightColors;
};

#endif
