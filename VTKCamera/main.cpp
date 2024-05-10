#include "myVTKCamera.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VTKCamera w;
    w.show();
    return a.exec();
}
