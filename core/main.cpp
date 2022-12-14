#include <QApplication>

#include "widgets/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow window;
    window.setMinimumHeight(500);
    window.show();

    return QApplication::exec();
}