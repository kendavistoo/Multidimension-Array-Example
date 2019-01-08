
//This example is based upon a posting by OldPeculier on StackOverflow in 2015

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#ifndef GLOBALS_H
#include "globals.h"
#endif

#ifndef MULTIARRAY_H
#include "multiarray.h"
#endif

#ifndef INTRODIALOG_H
#include "introdialog.h"
#endif

static const int    MW_WIDTH    = 600;
static const int    MW_HEIGHT   = 400;

//---------- class MainWindow ----------

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    MultiArray multiArray;

private:
    IntroDialog* introDialog;
    QTextEdit*   textDisplay;

    bool doInit = true;

    void InitTextAndArray();

    void SLOT_SetArrayDimensions(int dx, int dy, int dz);

protected:
    void paintEvent(QPaintEvent*);
};

#endif // MAINWINDOW_H
