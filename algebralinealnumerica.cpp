#include "algebralinealnumerica.h"
#include <iostream>
using namespace std;

AlgebraLinealNumerica::AlgebraLinealNumerica()
{

}

void AlgebraLinealNumerica::ReglaCramer(Matriz *A, Matriz *b, Matriz *sol)
{

    Matriz *aux;
    double orden = A->columnas(); //o A->filas();
    aux = new Matriz(orden,orden);
    double detAux;
    double detA = A->determinante();
    if(detA!=0){
     for(int k=0;k<orden;k++){
         for(int i=0;i< orden;i++){
             for(int j=0;j<orden;j++){

                 if(k==j){
                     aux->llenarElemento(i,j,b->obtenerElemento(i,0));
                 }else{
                     aux->llenarElemento(i,j,A->obtenerElemento(i,j));
                 }
             }
         }
         detAux = aux->determinante();
         sol->llenarElemento(k,0, detAux/detA);
        }
    }
    delete aux;
}

AlgebraLinealNumerica::~AlgebraLinealNumerica()
{

}
