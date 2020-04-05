#ifndef LISTARECORRIDO_H
#define LISTARECORRIDO_H
#include "NodoRecorrido.h"
#include <stdlib.h>
#include <string>
#include <string.h>
#include <stdio.h>

class ListaRecorrido
{
    public:
        ListaRecorrido();
        void insertar(std::string usuario_);
        void mostrar();
        //
        NodoRecorrido *primero;
        NodoRecorrido *ultimo;
        void graficar();


    protected:

    private:
};

#endif // LISTARECORRIDO_H
