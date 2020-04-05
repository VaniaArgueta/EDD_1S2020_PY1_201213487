#ifndef LISTASIMPLEORDENADA_H
#define LISTASIMPLEORDENADA_H
#include "NodoSimple.h"
#include<stdlib.h>
#include <iostream>

class ListaSimpleOrdenada
{
    public:
        ListaSimpleOrdenada();
        void insertar(char* jugador_, int score_);
        void mostrar();
        //
        NodoSimple *primero;
        NodoSimple *ultimo;
        NodoSimple *getPrimero();
        void setPrimero(NodoSimple *nuevo_);
        NodoSimple *getUltimo();
        void setUltimo(NodoSimple *ultimo_);
        void graficarScoreboard();
        void graficarScore();

    protected:

    private:
};

#endif // LISTASIMPLEORDENADA_H
