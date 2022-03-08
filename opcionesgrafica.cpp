#include "opcionesgrafica.h"
#include "ui_opcionesgrafica.h"

opcionesGrafica::opcionesGrafica(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::opcionesGrafica)
{
    ui->setupUi(this);

}

opcionesGrafica::~opcionesGrafica()
{
    delete ui;
}

int opcionesGrafica::numeroPuntos()
{
    return ui->numeroPuntosSB->value();
}

double opcionesGrafica::minXDom()
{
    return ui->minXDomDSB->value();
}

double opcionesGrafica::maxXDom()
{
    return ui->maxXDomDSB->value();
}

double opcionesGrafica::minX()
{
    return ui->minXPlanoDSB->value();
}

double opcionesGrafica::maxX()
{
    return ui->maxXPlanoDSB->value();
}

double opcionesGrafica::minY()
{
    return ui->minYPlanoDSB->value();
}

double opcionesGrafica::maxY()
{
    return ui->maxYPlanoDSB->value();
}

int opcionesGrafica::interacciones()
{
    return ui->interaccionesCheckBox->checkState();
}

double opcionesGrafica::parametroA()
{
    return ui->paramADSB->value();
}

double opcionesGrafica::parametroB()
{
    return ui->paramBDSB->value();;
}


void opcionesGrafica::on_aceptarPushButton_clicked()
{
    accept();
}

