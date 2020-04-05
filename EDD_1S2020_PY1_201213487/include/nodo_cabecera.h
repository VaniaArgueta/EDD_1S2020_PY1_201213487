#ifndef NODO_CABECERA_H
#define NODO_CABECERA_H
#include "nodo_internoMatriz.h"

class nodo_cabecera
{
    public:
        int id_cabecera;
        nodo_cabecera * siguiente;
        nodo_cabecera * anterior;
        nodo_internoMatriz * nodoInterno;

        nodo_cabecera(int pos);
        //metodos del nodo cabecera
        nodo_cabecera * getSiguiente();
        nodo_cabecera * getAnterior();
        nodo_internoMatriz * getInterno();
        int getId();

        void setSiguiente(nodo_cabecera * nuevo);
        void setAnterior(nodo_cabecera * nuevo);
        void setNodoInterno(nodo_internoMatriz * nuevo);
        void setId(int num);
};

#endif // NODO_CABECERA_H
