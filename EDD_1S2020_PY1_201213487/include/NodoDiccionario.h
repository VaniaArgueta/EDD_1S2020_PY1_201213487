#ifndef NODODICCIONARIO_H
#define NODODICCIONARIO_H
#include <stdlib.h>
#include <string>
#include <string.h>
#include <stdio.h>

class NodoDiccionario
{
    public:
        NodoDiccionario(std::string palabra_, int id_);
        virtual ~NodoDiccionario();
        std::string palabra;
        int id;

        NodoDiccionario * siguiente;
        NodoDiccionario * anterior;

        //Métodos get
        NodoDiccionario * getSiguiente();
        NodoDiccionario * getAnterior();
        std::string getPalabra();
        //Métodos set
        void setSiguiente(NodoDiccionario * nuevo);
        void setAnterior(NodoDiccionario * nuevo);
        void setPalabra(std::string palabra_);


    protected:

    private:
};

#endif // NODODICCIONARIO_H
