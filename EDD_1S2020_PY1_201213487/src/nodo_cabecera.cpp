#include "nodo_cabecera.h"

nodo_cabecera::nodo_cabecera(int pos)
{
    this->anterior = NULL;
    this->siguiente = NULL;
    this->nodoInterno = NULL;
    this->id_cabecera = pos;
}

nodo_cabecera * nodo_cabecera::getSiguiente(){
    return this->siguiente;
}
nodo_cabecera * nodo_cabecera::getAnterior(){
    return this->anterior;
}

nodo_internoMatriz * nodo_cabecera::getInterno(){
    return  this->nodoInterno;
}
int nodo_cabecera::getId(){
    return this->id_cabecera;
}

void nodo_cabecera::setSiguiente(nodo_cabecera * nuevo){
    this->siguiente = nuevo;
}
void nodo_cabecera::setAnterior(nodo_cabecera * nuevo){
    this->anterior = nuevo;
}
void nodo_cabecera::setNodoInterno(nodo_internoMatriz * nuevo){
    this->nodoInterno = nuevo;
}
void nodo_cabecera::setId(int num){
    this->id_cabecera = num;
}
