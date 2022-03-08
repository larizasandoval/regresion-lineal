#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    numeroPuntos_=0;
    minX_=-10;
    maxX_=10;
    minY_=-10;
    maxY_=10;
    minXDom_=-10;
    maxXDom_=10;
    paramA_=0;
    paramB_=0;
    numeroPartciones_=50;

    ui->graficaWidget->addGraph();
    ui->graficaWidget->addGraph();
    ui->graficaWidget->xAxis->setLabel("x");
    ui->graficaWidget->yAxis->setLabel("y");
    ui->graficaWidget->xAxis->setRange(minX_,maxX_);
    ui->graficaWidget->yAxis->setRange(minY_,maxY_);
    ui->graficaWidget->legend->setVisible(true);
    ui->graficaWidget->legend->setFont(QFont("Helvetica", 9));


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_PuntosSpinBox_valueChanged(int arg1)
{

    numeroPuntos_=arg1;
    ui->PuntosTableWidget->setRowCount(arg1);
    RL_.establecerNumeroPuntos(numeroPuntos_);
    for(int i=0; i<arg1; i++){
       for(int j=0;j<2;j++){
           ui->PuntosTableWidget->setItem(i,j,new QTableWidgetItem(""));
           //ui->PuntosTableWidget->setCellWidget(i,j,new QDoubleSpinBox);
       }
    }
    ui->rectaPushButton->setEnabled(false);
    ui->opcionesGraficaPushButton->setEnabled(false);
    ui->graficarPushButton->setEnabled(false);
    ui->EvaluarPushButton->setEnabled(false);
    ui->graficaWidget->graph(0)->data().data()->clear();
    ui->graficaWidget->graph(1)->data().data()->clear();
    ui->graficaWidget->replot();
}




void MainWindow::on_calcularRegresioPushButton_clicked()
{

   double coordenadaX;
   double coordenadaY;

   if(numeroPuntos_==1){
       QMessageBox::critical(this,"Error", "El numero de puntos tiene que ser mayor que 1");
   }else

   if(validarEntradas() && numeroPuntos_>1){

    for(int i=0;i<numeroPuntos_;i++){
            coordenadaX=ui->PuntosTableWidget->item(i,0)->text().trimmed().toDouble();
            coordenadaY=ui->PuntosTableWidget->item(i,1)->text().trimmed().toDouble();
            RL_.llenarPuntoDouble(i,coordenadaX,coordenadaY);
    }

    RL_.realizarSumatorias();
    RL_.matrizCoeficientes();
    RL_.matrizIndependiente();
    RL_.ResolverSistema();
    ui->parametroALineEdit->setText(QString::number(RL_.parametroA()));
    ui->parametroBLineEdit->setText(QString::number(RL_.parametroB()));
    ui->rectaPushButton->setEnabled(true);
    ui->graficarPushButton->setEnabled(true);
    ui->EvaluarPushButton->setEnabled(true);
    ui->opcionesGraficaPushButton->setEnabled(true);
   }else{
       QMessageBox::critical(this,"Error", "ELEMENTOS VACIOS O INVALIDOS");
   }
}


void MainWindow::on_graficarPushButton_clicked()
{

    QVector<double> x(RL_.obtenetNumeroPuntos()), y(RL_.obtenetNumeroPuntos());


    for(int i=0; i< numeroPuntos_; i++){
        x[i] = RL_.obtenerPuntoX(i);
        y[i] = RL_.obtenerPuntoY(i);

    }

    ui->graficaWidget->graph(0)->setName("Puntos dados");
    ui->graficaWidget->graph(0)->setData(x,y);
    ui->graficaWidget->graph(0)->setPen(QPen(Qt::green));
    ui->graficaWidget->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->graficaWidget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle,10));

    ui->graficaWidget->replot();

}


void MainWindow::on_opcionesGraficaPushButton_clicked()
{
    int res;
    res=OG.exec();

    if(res==1){
        minXDom_= OG.minXDom();
        maxXDom_=OG.maxXDom();
        minX_=OG.minX();
        maxX_=OG.maxX();
        minY_=OG.minY();
        maxY_=OG.maxY();
        numeroPartciones_=OG.numeroPuntos();
        interacciones_=OG.interacciones();


        ui->graficaWidget->xAxis->setRange(minX_,maxX_);
        ui->graficaWidget->yAxis->setRange(minY_,maxY_);
        if(interacciones_ == 2){
            ui->graficaWidget->setInteraction(QCP::iRangeDrag, true);
            ui->graficaWidget->setInteraction(QCP::iRangeZoom, true);
        }
        else{
            ui->graficaWidget->setInteraction(QCP::iRangeDrag, false);
            ui->graficaWidget->setInteraction(QCP::iRangeZoom, false);
        }
         ui->graficaWidget->replot();

    }

}


void MainWindow::on_rectaPushButton_clicked()
{

    double  h;

    QVector<double> xx(numeroPartciones_) ,yy(numeroPartciones_);


    h = (maxXDom_ - minXDom_) / numeroPartciones_;


    for(int i=0; i< numeroPartciones_; i++){
        xx[i]=minXDom_ + i*h;
        yy[i] =RL_.evaluarPunto(xx[i]);
    }

    ui->graficaWidget->graph(1)->setName("Recta a+bx");
    ui->graficaWidget->graph(1)->setData(xx, yy);
    ui->graficaWidget->graph(1)->setPen(QPen(Qt::red));
    ui->graficaWidget->replot();

}


void MainWindow::on_salirPushButton_clicked()
{
    close();
}


void MainWindow::on_limpiarPushButton_clicked()
{
    ui->PuntosSpinBox->setValue(0);
    ui->graficaWidget->graph(0)->data().data()->clear();
    ui->graficaWidget->graph(1)->data().data()->clear();
    ui->graficaWidget->replot();
    ui->parametroALineEdit->setText("");
    ui->parametroBLineEdit->setText("");
    ui->rectaPushButton->setEnabled(false);
    ui->opcionesGraficaPushButton->setEnabled(false);
    ui->graficarPushButton->setEnabled(false);
    ui->EvaluarPushButton->setEnabled(false);
}

bool MainWindow::validarEntradas()
{
    QString coordenadaX;
    QString coordenadaY;
    for(int i=0;i<numeroPuntos_;i++){
            coordenadaX=ui->PuntosTableWidget->item(i,0)->text().trimmed();
            coordenadaY=ui->PuntosTableWidget->item(i,1)->text().trimmed();


            if(     coordenadaX==""||
                    coordenadaY==""||
                    coordenadaX.count(QRegularExpression("[a-zA-Z\\\\~`!@#$%^&*()_+=:;,?><}{\\[\\]|/\'\"     ]"))>0||
                    coordenadaY.count(QRegularExpression("[a-zA-Z\\\\~`!@#$%^&*()_+=:;,?><}{\\[\\]|/\'\"     ]"))>0
              ){
              return false;
            }
    }

    return true;
}


void MainWindow::on_EvaluarPushButton_clicked()
{
    //int res;
    evaluarPunto.recibirA(RL_.parametroA());
    evaluarPunto.recibirB((RL_.parametroB()));
    evaluarPunto.exec();
}

