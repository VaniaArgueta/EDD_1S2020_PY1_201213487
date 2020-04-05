#include "NodoDiccionario.h"

NodoDiccionario::NodoDiccionario(std::string palabra_, int id_)
{
    this->siguiente = NULL;
    this->anterior = NULL;
    this->palabra= palabra_;
    this->id = id_;
}

NodoDiccionario::~NodoDiccionario()
{
    //dtor
}

//Métodos get del nodo
NodoDiccionario * NodoDiccionario::getSiguiente(){
    return this->siguiente;
}
NodoDiccionario * NodoDiccionario::getAnterior(){
    return  this->anterior;
}
std::string NodoDiccionario::getPalabra(){
    return this->palabra;
}

//Métodos set del nodo
void NodoDiccionario::setSiguiente(NodoDiccionario * nuevo){
    this->siguiente= nuevo;
}
void NodoDiccionario::setAnterior(NodoDiccionario * nuevo){
    this->anterior = nuevo;
}
void NodoDiccionario::setPalabra(std::string palabra_){
    this->palabra = palabra_;
}
