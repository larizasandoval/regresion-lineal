#include "evaluarpuntodialog.h"
#include "ui_evaluarpuntodialog.h"


evaluarPuntoDialog::evaluarPuntoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::evaluarPuntoDialog)
{
    ui->setupUi(this);
}

evaluarPuntoDialog::~evaluarPuntoDialog()
{
    delete ui;
}

void evaluarPuntoDialog::recibirA(double a)
{
    A_=a;
}


void evaluarPuntoDialog::recibirB(double b)
{
    B_=b;
}


void evaluarPuntoDialog::on_EvaluarPushButton_clicked()
{
    double x = ui->puntoXDSB->value();

    ui->puntoYLineEdit->setText(QString::number(A_+B_*x));

}

