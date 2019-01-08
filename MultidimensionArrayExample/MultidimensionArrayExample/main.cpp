#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    gSizeAndCenterWidget (&w, MW_WIDTH, MW_HEIGHT);
    w.show();

    return a.exec();
}
