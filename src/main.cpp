#include "leg.h"

#include <QApplication>
#include "processingCards.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LEG w;
    w.show();
    return a.exec();
}
