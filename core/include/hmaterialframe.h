#ifndef HMATERIALFRAME_H
#define HMATERIALFRAME_H

#include <QList>
#include <QColor>
#include <QWidget>

enum ThemeColors { Dark, Light };
enum LevelColors { Level1, Level2, Level3, Level4 };

class HMaterialFrame : public QWidget
{
    Q_OBJECT

public:
    HMaterialFrame(ThemeColors theme, LevelColors level, QWidget *parent = nullptr);
    ~HMaterialFrame();
    
    void changeMode();
    void setCorner(qreal corner);

protected:
    void paintEvent(QPaintEvent *event);

private:
    QColor m_backgroundColor;
    qreal m_roundCorner;

    ThemeColors m_theme;
    LevelColors m_level;

    QList<QColor> m_darkColors;
    QList<QColor> m_lightColors;
};

#endif
