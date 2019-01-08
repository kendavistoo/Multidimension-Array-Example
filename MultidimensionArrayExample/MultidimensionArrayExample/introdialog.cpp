#include "introdialog.h"



//---------- CONSTRUCTOR    IntroDialog ----------

IntroDialog :: IntroDialog(QWidget *parent, Qt::WindowFlags f) : QDialog(parent, f)
{
    qDebug()<<"CONSTRUCTOR   IntroDialog";

    spinX   = new QSpinBox(this);
    spinY   = new QSpinBox(this);
    spinZ   = new QSpinBox(this);

    spinX->setPrefix(" X:  ");
    spinY->setPrefix(" Y:  ");
    spinZ->setPrefix(" Z:  ");

    spinX->setRange(1, G_MAX_ARRAY_DIMENSION);
    spinY->setRange(1, G_MAX_ARRAY_DIMENSION);
    spinZ->setRange(1, G_MAX_ARRAY_DIMENSION);

    okButt = new QPushButton("OK", this);
    connect(okButt, &QPushButton::clicked, this, &IntroDialog::SLOT_DoClose);

    groupBox = new QGroupBox("Input Array Dimensions", this);
    groupBox->setGeometry(100, 40, 140, 200);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(spinX);
    vbox->addWidget(spinY);
    vbox->addWidget(spinZ);
    vbox->addStretch(1);
    vbox->addWidget(okButt);
    vbox->setSpacing(20);
    groupBox->setLayout(vbox);

    groupBox->setVisible(true);
}

//---------- DESTRUCTOR   ~IntroDialog ----------

IntroDialog :: ~IntroDialog(){

    qDebug()<<"DESTRUCTOR   ~IntroDialog";
}

//---------- closeEvent ----------

void   IntroDialog :: closeEvent(QCloseEvent *e) {

    qDebug()<<"IntroDialog       closeEvent ";

    int xxx = spinX->value();
    int yyy = spinY->value();
    int zzz = spinZ->value();

    emit SIGNAL_ArrayDimensions(xxx, yyy, zzz);
}

//---------- SLOT_DoClose ----------

void IntroDialog :: SLOT_DoClose(){
    close();
}
