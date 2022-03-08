#ifndef OPCIONESGRAFICA_H
#define OPCIONESGRAFICA_H

#include <QDialog>

namespace Ui {
class opcionesGrafica;
}

class opcionesGrafica : public QDialog
{
    Q_OBJECT

public:
    explicit opcionesGrafica(QWidget *parent = nullptr);
    ~opcionesGrafica();
    int numeroPuntos();
    double minXDom();
    double maxXDom();

    double minX();
    double maxX();
    double minY();
    double maxY();

    int interacciones();

    double parametroA();
    double parametroB();

    //Set para mantenerlos


private slots:

    void on_aceptarPushButton_clicked();

private:
    Ui::opcionesGrafica *ui;
};

#endif // OPCIONESGRAFICA_H
