#ifndef HCONSTRUCTORPAGE_H
#define HCONSTRUCTORPAGE_H

#include <QWidget>

class HConstructorPage : public QWidget
{
public:
    explicit HConstructorPage(QWidget *parent = nullptr);
    ~HConstructorPage();

protected:
    void paintEvent(QPaintEvent *event);
    virtual void paintForeground(QPainter *painter);
    virtual void paintBackground(QPainter *painter);
};

#endif
