#ifndef LISTACIRCULARDOBLE_H
#define LISTACIRCULARDOBLE_H
#include "NodoDoble.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

class ListaCircularDoble
{
    public:
        ListaCircularDoble();
        NodoDoble * primero;
        NodoDoble * ultimo;
        int size;
        int correlativo;

        //Métodos get
        NodoDoble * getPrimero();
        NodoDoble * getUltimo();
        int getSize();

        //Métodos set
        void setPrimero(NodoDoble * nuevo);
        void setUltimo(NodoDoble *  nuevo);
        void setSize();

        //Otros métodos
        NodoDoble * crearNodo(char* valor_, int correlativo_);
        void insertar(char* valor_);
        void mostrar();
        NodoDoble * buscar(int id_buscar);
        void graficar();
};

#endif // LISTACIRCULARDOBLE_H
