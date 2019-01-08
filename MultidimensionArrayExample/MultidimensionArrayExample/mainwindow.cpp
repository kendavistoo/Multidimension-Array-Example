#include "mainwindow.h"

//---------- CONSTRUCTOR MainWindow ----------

MainWindow :: MainWindow(QWidget *parent) : QMainWindow(parent)
{
    introDialog = new IntroDialog(this);
    connect(introDialog, &IntroDialog::SIGNAL_ArrayDimensions, this, &MainWindow::SLOT_SetArrayDimensions);
    introDialog->setWindowTitle("Universe");
    gSizeAndCenterWidget (introDialog, 400, 300);
    introDialog->exec();

    textDisplay = new QTextEdit(this);
    textDisplay->setGeometry(0, 20, MW_WIDTH, MW_HEIGHT);
    textDisplay->setVisible(true);
}

//---------- DESTRUCTOR MainWindow ----------

MainWindow :: ~MainWindow(){

}

//---------- paintEvent ----------

void MainWindow :: paintEvent(QPaintEvent* e){

    if (doInit){
        InitTextAndArray();
        doInit = false;
    }//if
}

//---------- SLOT_SetArrayDimensions ----------

void MainWindow :: SLOT_SetArrayDimensions(int dx, int dy, int dz){

    qDebug()<<"SLOT_SetArrayDimensions   "<<dx<<"   "<<dy<<"   "<<dz;

    multiArray.dimensionTheArray(dx, dy, dz);
}

//---------- InitTextAndArray ----------

void MainWindow :: InitTextAndArray(){

    for (uint i=0; i<=multiArray.maxX; i++){

        QString istr = "\ni ";
        istr.append(QString::number(i));;
        textDisplay->append(istr);

        for (uint j=0; j<=multiArray.maxY; j++){
            QString jstr = "    j ";
            jstr.append(QString::number(j));
            textDisplay->append(jstr);

            QString kstr = "        k ";
            for (uint k=0; k<=multiArray.maxZ; k++){
                kstr.append("  ");
                kstr.append(QString::number(k));

                //----------

                NodeType* myNode = new NodeType();
                myNode->position = QVector3D((float)i, (float)j, (float)k);
                myNode->temperature = 42.0;
                multiArray.setNode(i, j, k, myNode);
            }//for k
            textDisplay->append(kstr);
            kstr.clear();

            jstr.clear();
        }//for j

        istr.clear();
    }//for i

    textDisplay->setReadOnly(true);
    textDisplay->setLineWrapMode(QTextEdit::NoWrap);
    update();
}

