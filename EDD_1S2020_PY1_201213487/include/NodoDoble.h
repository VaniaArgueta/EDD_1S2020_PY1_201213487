#ifndef NODODOBLE_H
#define NODODOBLE_H
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class NodoDoble
{
    public:
        NodoDoble(char* palabra_, int id_);
        NodoDoble(char ficha_);
        char* palabra;
        int id;
        char ficha;

        NodoDoble * siguiente;
        NodoDoble * anterior;

        //Métodos get
        NodoDoble * getSiguiente();
        NodoDoble * getAnterior();
        char* getPalabra();
        //Métodos set
        void setSiguiente(NodoDoble * nuevo);
        void setAnterior(NodoDoble * nuevo);
        void setPalabra(char* palabra_);


    protected:

    private:
};

#endif // NODODOBLE_H
