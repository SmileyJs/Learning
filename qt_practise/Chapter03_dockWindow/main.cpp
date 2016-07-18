#include "dockwindow.h"
#include <QApplication>

#include <QDockWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DockWindow w;
    w.show();

    return a.exec();
}
