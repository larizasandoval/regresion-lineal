#ifndef REGRESIONL_H
#define REGRESIONL_H
#include "punto.h"
#include "matriz.h"
#include "algebralinealnumerica.h"
//using namespace std;

class RegresionL
{
private:
    int numeroPuntos; //numero de puntos para realizar la regresion
    Punto *Puntos_; //arreglo de todos los puntos para realizar la regresion
    double sumXi_; // sumatoria de las coordenadas x de los puntos
    double sumYi_;// sumatoria de las coordenadas y de los puntos
    double sumXi2_; //sumatoria de las coordenadas x cuadrada de los puntos
    double sumXiYi_;//sumatoria de las coordenadas x*y de los puntos
    double sumatoria[4];//arreglo para guardar las sumatorias anteriores

    Matriz *coeficientes; //Matriz de coeficientes
    Matriz *independientes; // Matriz de terminos idependientes
    Matriz *solucion;
    AlgebraLinealNumerica *ALN;

public:

    RegresionL(); //Constructor por defecto

    RegresionL(int numeroPunto); //construtor que recibe el numero de puntos que tendra la regresion lineal

    //funciones set
    void establecerNumeroPuntos(int n);

    //funciones get
    int obtenetNumeroPuntos();
    Punto* obtenerPuntos();
    Punto obtenerPunto(int indice);
    double obtenerPuntoX(int indice);
    double obtenerPuntoY(int indice);

    //Otras funciones
    void llenarPunto(int indice,Punto punto);
    void llenarPuntoDouble(int indice, double x,double y);
    void llenarPuntos();

    void realizarSumatorias();

    double * obtenerSumatorias();

    void imprimirSumatorias();

    void imprimirPuntos();

    void imprimirRecta();

    void matrizCoeficientes();

    void verMatrizCoeficientes();

    void matrizIndependiente();

    void verMatrizIndependiente();

    void ResolverSistema();

    void verSolucionesEncontrados();

    double parametroA();
    double parametroB();

    double evaluarPunto(double x);

    ~RegresionL();

};

#endif // REGRESIONL_H
