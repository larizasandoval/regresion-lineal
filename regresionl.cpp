#include "regresionl.h"
#include <iostream>
using namespace std;

RegresionL::RegresionL()
{
    numeroPuntos=0;
}

RegresionL::RegresionL(int numeroPunto)
{
    numeroPuntos=numeroPunto;
}

void RegresionL::establecerNumeroPuntos(int n)
{

    numeroPuntos=n;
    Puntos_ = new Punto[numeroPuntos];

}

int RegresionL::obtenetNumeroPuntos()
{
    return numeroPuntos;
}

Punto* RegresionL::obtenerPuntos()
{
    return Puntos_;
}

Punto RegresionL::obtenerPunto(int indice)
{
    return Puntos_[indice];
}

double RegresionL::obtenerPuntoX(int indice)
{
    return Puntos_[indice].obtenerX();
}

double RegresionL::obtenerPuntoY(int indice)
{
    return Puntos_[indice].obtenerY();
}
void RegresionL::llenarPunto(int indice, Punto punto)
{
    Puntos_[indice]=punto;
}

void RegresionL::llenarPuntoDouble(int indice, double x, double y)
{
    Puntos_[indice].establecerX(x);
    Puntos_[indice].establecerY(y);
}

/*void RegresionL::llenarPuntos()
{
    for(int i=0;i<numeroPuntos;i++){
        double x,y;
        cout << "Ingrese la coordenada x"<<i+1<<": ";
        cin>>x;
        cout << "Ingrese la coordenada y"<<i+1<<": ";
        cin>>y;
        Puntos_[i].establecerX(x);
        Puntos_[i].establecerY(y);
    }
}*/

void RegresionL::realizarSumatorias()
{
    sumXi_=0;
    sumXi2_=0;
    sumXiYi_=0;
    sumYi_=0;
    for(int i=0;i<numeroPuntos;i++){
        sumXi_ = sumXi_ + Puntos_[i].obtenerX();
        sumYi_ = sumYi_ + Puntos_[i].obtenerY();
        sumXi2_ = sumXi2_ + (Puntos_[i].obtenerX()*Puntos_[i].obtenerX());
        sumXiYi_ = sumXiYi_ + (Puntos_[i].obtenerX()*Puntos_[i].obtenerY());
    }
    sumatoria[0]=sumXi_;
    sumatoria[1]=sumYi_;
    sumatoria[2]=sumXi2_;
    sumatoria[3]=sumXiYi_;

}

double *RegresionL::obtenerSumatorias()
{
    return sumatoria;
}

void RegresionL::imprimirSumatorias(){

   cout << "Xi: "<< sumatoria[0]<<endl;
   cout << "Yi: "<< sumatoria[1]<<endl;
   cout << "Xi2: "<< sumatoria[2]<<endl;
   cout << "XiYi: "<< sumatoria[3]<<endl;

}

/*void RegresionL::imprimirPuntos()
{
    if(numeroPuntos>0){

        cout<<"Los "<<obtenetNumeroPuntos()<<" punto ingresados son: "<<endl;

        for(int i=0;i<numeroPuntos;i++){

            cout << "La coordenada x"<<i+1<<" es: "<<Puntos_[i].obtenerX()<<endl;
            cout << "La coordenada y"<<i+1<<" es: "<<Puntos_[i].obtenerY()<<endl;
        }
    }else{
        cout<<"No hay puntos ingresados"<<endl;
    }
}*/

/*void RegresionL::imprimirRecta()
{
    if(numeroPuntos>0){
        cout<<"La recta 'y = a + bx' encontrada con la regresion lineal es: "<<solucion->obtenerElemento(0,0)<<" +"<<solucion->obtenerElemento(1,0)<<"x"<<endl;
    }else{
        cout<<"No se puede mostrar la ecuacion, porque no se han ingresado puntos"<<endl;
    }
}*/

void RegresionL::matrizCoeficientes()
{

    coeficientes = new Matriz(2,2);

    coeficientes->llenarElemento(0,0,numeroPuntos);
    coeficientes->llenarElemento(0,1,sumXi_);
    coeficientes->llenarElemento(1,0,sumXi_);
    coeficientes->llenarElemento(1,1,sumXi2_);

}

/*void RegresionL::verMatrizCoeficientes()
{
    coeficientes->ver();
}*/

void RegresionL::matrizIndependiente()
{
   independientes = new Matriz(2,1);
    independientes->llenarElemento(0,0,sumYi_);
    independientes->llenarElemento(1,0,sumXiYi_);

}

/*void RegresionL::verMatrizIndependiente()
{
    independientes->ver();
}*/

void RegresionL::ResolverSistema()
{

    ALN = new AlgebraLinealNumerica();
    solucion = new Matriz(coeficientes->filas(),1);
    ALN->ReglaCramer(coeficientes,independientes,solucion);


}

/*void RegresionL::verSolucionesEncontrados()
{
    cout<<"Los parametros a y b encontrados para la recta 'y=a+bx' son: "<<endl;
    cout<<"a: "<< solucion->obtenerElemento(0,0)<<endl;
    cout<<"b: "<< solucion->obtenerElemento(1,0)<<endl;
}*/

double RegresionL::parametroA()
{
    return solucion->obtenerElemento(0,0);
}

double RegresionL::parametroB()
{
    return solucion->obtenerElemento(1,0);
}

double RegresionL::evaluarPunto(double x)
{
    double Y;

    Y = solucion->obtenerElemento(0,0)+solucion->obtenerElemento(1,0)*x;

    return Y;
}


RegresionL::~RegresionL()
{
    delete Puntos_;
    delete [] coeficientes;
    delete [] independientes;
    delete [] solucion;
}
