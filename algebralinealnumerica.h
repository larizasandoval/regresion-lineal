#ifndef ALGEBRALINEALNUMERICA_H
#define ALGEBRALINEALNUMERICA_H
#include "matriz.h"


class AlgebraLinealNumerica
{
public:
    AlgebraLinealNumerica();

    void ReglaCramer(Matriz *A, Matriz *b, Matriz *sol);

    ~AlgebraLinealNumerica();
};

#endif // ALGEBRALINEALNUMERICA_H
