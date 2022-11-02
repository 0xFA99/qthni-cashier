#ifndef HMAINWINDOW_H
#define HMAINWINDOW_H

#include <QtWidgets/QMainWindow>

class QWidget;
class HMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HMainWindow(QWidget *parent = nullptr);
    ~HMainWindow();
private:
    QWidget *m_centralWidget;
};

#endif
