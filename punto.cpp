#include "punto.h"
#include <iostream>
using namespace std;

Punto::Punto()
{

}

Punto::Punto(double X, double Y)
{
    X_=X;
    Y_=Y;
}

void Punto::establecerX(double X)
{
    X_=X;
}

void Punto::establecerY(double Y)
{
    Y_=Y;
}

double Punto::obtenerX()
{
    return X_;
}

double Punto::obtenerY()
{
    return Y_;
}


