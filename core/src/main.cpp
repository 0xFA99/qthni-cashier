#include <QtWidgets/QApplication>

#include "hmainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Q_INIT_RESOURCE(hni_sources);

    HMainWindow window;
    window.show();

    return app.exec();
}
