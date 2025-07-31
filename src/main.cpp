#include "leg.h"

#include <QApplication>

void debugEspeak()
{
    system("espeak-ng --version > espeak.log 2>&1");
    system("dir espeak-ng-data >> espeak.log 2>&1");
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LEG w;
    w.show();
    debugEspeak();
    return a.exec();
}
