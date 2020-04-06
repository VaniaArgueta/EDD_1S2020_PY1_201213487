#include "NodoDoble.h"

NodoDoble::NodoDoble(char* palabra_, int id_)
{
    this->siguiente = NULL;
    this->anterior = NULL;
    this->palabra= palabra_;
    this->id = id_;
}
NodoDoble::NodoDoble(char ficha_){
    this->ficha = ficha_;

}

//Métodos get del nodo
NodoDoble * NodoDoble::getSiguiente(){
    return this->siguiente;
}
NodoDoble * NodoDoble::getAnterior(){
    return  this->anterior;
}
char* NodoDoble::getPalabra(){
    return this->palabra;
}

//Métodos set del nodo
void NodoDoble::setSiguiente(NodoDoble * nuevo){
    this->siguiente= nuevo;
}
void NodoDoble::setAnterior(NodoDoble * nuevo){
    this->anterior = nuevo;
}
void NodoDoble::setPalabra(char* palabra_){
    this->palabra = palabra_;
}
