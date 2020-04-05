#ifndef NODORECORRIDO_H
#define NODORECORRIDO_H
#include <stdlib.h>
#include <string>
#include <string.h>
#include <stdio.h>

class NodoRecorrido
{
    public:
        NodoRecorrido(std::string usuario_);
        std::string usuario;
        NodoRecorrido* siguiente;


    protected:

    private:
};

#endif // NODORECORRIDO_H
