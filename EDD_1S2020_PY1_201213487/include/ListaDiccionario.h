#ifndef LISTADICCIONARIO_H
#define LISTADICCIONARIO_H
#include "NodoDiccionario.h"
#include <stdlib.h>
#include <string>
#include <string.h>
#include <stdio.h>

class ListaDiccionario
{
    public:
        ListaDiccionario();
        virtual ~ListaDiccionario();
        NodoDiccionario * primero;
        NodoDiccionario * ultimo;
        int size;
        int correlativo;

        //Métodos get
        NodoDiccionario * getPrimero();
        NodoDiccionario * getUltimo();
        int getSize();

        //Métodos set
        void setPrimero(NodoDiccionario * nuevo);
        void setUltimo(NodoDiccionario *  nuevo);
        void setSize();

        //Otros métodos
        NodoDiccionario * crearNodo(std::string valor_, int correlativo_);
        void insertar(std::string valor_);
        void mostrar();
        NodoDiccionario * buscar(int id_buscar);
        void graficar();

    protected:

    private:
};

#endif // LISTADICCIONARIO_H
