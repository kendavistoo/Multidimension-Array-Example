
#ifndef GLOBALS_H
#include "globals.h"
#endif

//---------- gSizeAndCenterWidget ---------

void gSizeAndCenterWidget (QWidget* widget, int width, int height) {
    int x,y;
    int screenWidth;
    int screenHeight;

    QDesktopWidget* desktop = QApplication::desktop();

    screenWidth = desktop->width();
    screenHeight = desktop->height();

    x = (screenWidth - width)/2;
    y = (screenHeight - height)/2;

    widget->setGeometry (x, y, width, height);
}//gSizeAndCenterWidget
