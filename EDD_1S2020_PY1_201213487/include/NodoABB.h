#ifndef NODOABB_H
#define NODOABB_H
#include "ListaSimpleOrdenada.h"
#include <stdlib.h>
#include <string>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include "ListaSimpleOrdenada.h"
#include "ListaDoble.h"

class NodoABB
{
public:
    std::string usuario;
    NodoABB * izquierdo;
    NodoABB * derecho;
    ListaSimpleOrdenada * lista_score;
    ListaDoble * lista_fichas;

    NodoABB(std::string nombre);

    //metodos get
    std::string getNombreUsuario();
    NodoABB * getIzquierdo();
    NodoABB * getDerecho();


    //metodos set
    void setNombreUsuario(std::string nombre);
    void setIzquierdo(NodoABB * nuevo);
    void setDerecho(NodoABB * nuevo);


};

#endif // NODOABB_H
