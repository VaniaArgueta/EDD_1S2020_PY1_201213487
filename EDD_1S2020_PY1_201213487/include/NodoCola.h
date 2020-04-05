#ifndef NODOCOLA_H
#define NODOCOLA_H
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

class NodoCola
{
    public:
        NodoCola(int puntaje_, char letra_);
        int puntaje;
        char letra;
        int cantidad;
        NodoCola * siguiente;

        //Métodos get
        NodoCola * getSiguiente();
        int getPuntaje();
        char getLetra();
        int getCantidad();
        //Métodos set
        void setSiguiente(NodoCola * nuevo);
        void setPuntaje(int puntaje_);
        void setLetra(char letra_);
        void setCantidad(int cantidad_);
};

#endif // NODOCOLA_H
