#ifndef INTRODIALOG_H
#define INTRODIALOG_H

#ifndef GLOBALS_H
#include "globals.h"
#endif


class IntroDialog : public QDialog
{
    Q_OBJECT

public:
    IntroDialog(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::Dialog);
    ~IntroDialog();

private:
    QSpinBox    *spinX;
    QSpinBox    *spinY;
    QSpinBox    *spinZ;

    QPushButton *okButt;

    QGroupBox       *groupBox;

protected:
    void    closeEvent(QCloseEvent *e) override;

private slots:
    void SLOT_DoClose();

signals:
    void SIGNAL_ArrayDimensions(int dx, int dy, int dz);

};

#endif // INTRODIALOG_H
