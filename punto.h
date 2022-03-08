#ifndef PUNTO_H
#define PUNTO_H
//using namespace std;


class Punto
{
private:
    double X_;
    double Y_;
public:
    Punto();
    Punto(double X, double Y);

    void establecerX(double X);
    void establecerY(double Y);

    double obtenerX();
    double obtenerY();

};

#endif // PUNTO_H
