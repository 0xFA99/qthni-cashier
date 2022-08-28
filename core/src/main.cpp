#include <QtWidgets/QApplication>

#include "hmainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    HMainWindow window;
    window.show();

    return app.exec();
}
