#include "firstwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    firstwindow w;
    w.show();
    return a.exec();
}
