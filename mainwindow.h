#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "regresionl.h"
#include <QMainWindow>
#include <qdebug.h>
#include "qcustomplot.h"
#include <opcionesgrafica.h>
#include <qmessagebox.h>
#include <evaluarpuntodialog.h>
//using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_PuntosSpinBox_valueChanged(int arg1);

    void on_calcularRegresioPushButton_clicked();

    void on_graficarPushButton_clicked();

    void on_opcionesGraficaPushButton_clicked();

    void on_rectaPushButton_clicked();

    void on_salirPushButton_clicked();

    void on_limpiarPushButton_clicked();

    void on_EvaluarPushButton_clicked();


private:
    Ui::MainWindow *ui;
    int numeroPuntos_;
    int interacciones_;
    int numeroPartciones_;
    double minXDom_;
    double maxXDom_;
    double minX_;
    double maxX_;
    double minY_;
    double maxY_;
    double paramA_;
    double paramB_;
    opcionesGrafica OG;
    evaluarPuntoDialog evaluarPunto;
    RegresionL RL_;

    QCPGraph *planoXY_;

    bool validarEntradas();

};
#endif // MAINWINDOW_H
