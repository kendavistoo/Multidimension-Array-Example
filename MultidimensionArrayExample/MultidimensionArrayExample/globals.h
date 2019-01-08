#ifndef GLOBALS_H
#define GLOBALS_H

#include <QDebug>
#include <QMainWindow>
#include <QVector3D>
#include <QObject>
#include <QDialog>
#include <QSpinBox>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QDesktopWidget>
#include <QPushButton>
#include <QApplication>
#include <QTextEdit>
#include <QMessageBox>

static const int    G_MAX_ARRAY_DIMENSION = 10;

typedef struct NodeType
{
    QVector3D   position;
    float       temperature;
}NodeType;

void gSizeAndCenterWidget (QWidget* widget, int width, int height);


#endif // GLOBALS_H
