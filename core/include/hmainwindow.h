#ifndef HMAINWINDOW_H
#define HMAINWINDOW_H

#include <QtWidgets/QMainWindow>

class HMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HMainWindow(HMainWindow *parent = nullptr);
    ~HMainWindow();
};

#endif