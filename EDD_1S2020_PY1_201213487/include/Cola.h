#ifndef COLA_H
#define COLA_H
#include "NodoCola.h"
#include <iostream>
#include<bits/stdc++.h>

class Cola
{
    public:
        Cola();
        NodoCola *raiz;
        NodoCola *fondo;
        NodoCola *getRaiz();
        void setRaiz(NodoCola* raiz_);
        NodoCola *getFondo();
        void setFondo(NodoCola* fondo_);
        void queue_(char letra_);
        char deque_();
        void mostrar();
        bool verificarVacia();
        int obtenerPuntaje(char letra_);
        void graficar();

    protected:

    private:
};

#endif // COLA_H
