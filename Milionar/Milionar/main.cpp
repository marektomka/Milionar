#include "Milionar.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Milionar w;
    w.show();
    return a.exec();
}
