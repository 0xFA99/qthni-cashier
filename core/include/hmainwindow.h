#ifndef HMAINWINDOW_H
#define HMAINWINDOW_H

#include <QtWidgets/QMainWindow>

#include "hmaterialframe.h"

class HMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HMainWindow(QWidget *parent = nullptr);
    ~HMainWindow();
public slots:
    void test(int);
private:
    HMaterialFrame *m_centralWidget;
};

#endif
