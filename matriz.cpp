#include "matriz.h"
#include "math.h"

void Matriz::reservaMemoria()
{
    elementos_ = new double*[filas_];

    for(int i=0; i<filas_; i++)
        elementos_[i] = new double[columnas_];
}

Matriz::Matriz()
{
    filas_ = 0;
    columnas_ = 0;
}

Matriz::Matriz(int filas, int columnas)
{
    filas_ = filas;
    columnas_ = columnas;

    reservaMemoria();
}

Matriz::~Matriz()
{
    delete[] elementos_;
}

void Matriz::establecerFilas(int filas)
{
    filas_ = filas;
}

void Matriz::establecerColumnas(int columnas)
{
    columnas_ = columnas;
}

int Matriz::filas()
{
    return filas_;
}

int Matriz::columnas()
{
    return columnas_;
}

void Matriz::llenarElemento(int fila, int columna, double valor)
{
    elementos_[fila][columna] = valor;
}

/*void Matriz::ver()
{
    for(int i=0; i<filas_; i++){
        for(int j=0; j<columnas_; j++){
            cout << elementos_[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}*/

double Matriz::obtenerElemento(int fila, int columna)
{
    return elementos_[fila][columna];
}


double Matriz::determinante()
{
    int orden = filas_;
    if(orden == 1){
        return elementos_[0][0];
    }
    else{
        double det = 0.0;
        for(int i=0; i<orden; i++){
            Matriz *cofactor;
            cofactor = new Matriz(orden-1, orden-1);

            int fila = 0, columna = 0;
            for(int j=1; j <orden; j++){
                for(int k=0; k<orden; k++){
                    if(i != k){
                        cofactor->llenarElemento(fila, columna, elementos_[j][k]);
                        columna++;
                    }

                }
                fila++;
                columna = 0;

            }
            det += pow(-1, i)*elementos_[0][i]*cofactor->determinante();
            delete cofactor;
        }
        return det;
    }
}




