#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include "NodoDoble.h"
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class ListaDoble
{
    public:
        ListaDoble();
        void insertar(char letra);
        void mostrar();
        void graficaLista();
        //
        NodoDoble* primero;
        NodoDoble* ultimo;
        NodoDoble* getPrimero();
        void setPrimero(NodoDoble* nuevo_);
        NodoDoble* getUltimo();
        void setUltimo(NodoDoble* ultimo_);
        void eliminarNodo(char letraEliminar);
        void vaciarLista();

    protected:

    private:
};

#endif // LISTADOBLE_H
