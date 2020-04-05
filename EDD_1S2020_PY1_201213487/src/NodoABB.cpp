#include "NodoABB.h"

NodoABB::NodoABB(std::string nombre)
{
    this->usuario = nombre;
    this->izquierdo = NULL;
    this->derecho = NULL;
}

//metodos get del nodo avl
    std::string NodoABB::getNombreUsuario(){
        return this->usuario;
    }
    NodoABB * NodoABB::getIzquierdo(){
        return this->izquierdo;
    }
    NodoABB * NodoABB::getDerecho(){
        return this->derecho;
    }


    //metodos set del nodo avl
    void NodoABB::setNombreUsuario(std::string nombre){
        this->usuario = nombre;
    }
    void NodoABB::setIzquierdo(NodoABB * nuevo){
        this->izquierdo = nuevo;
    }
    void NodoABB::setDerecho(NodoABB * nuevo){
        this->derecho = nuevo;
    }


