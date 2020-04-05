#include "NodoCola.h"

NodoCola::NodoCola(int puntaje_, char letra_)
{
    this->puntaje = puntaje_;
    this->letra = letra_;
    //this->cantidad = cantidad_;
}
int NodoCola::getPuntaje()
{
  return this->puntaje;
}
void NodoCola::setPuntaje(int puntaje_)
{
  this->puntaje = puntaje_;
}
char NodoCola::getLetra()
{
  return this->letra;
}
void NodoCola::setLetra(char letra_)
{
  this->letra = letra_;
}
int NodoCola::getCantidad()
{
  return this->cantidad;
}
void NodoCola::setCantidad(int cantidad_)
{
  this->cantidad = cantidad_;
}


NodoCola* NodoCola::getSiguiente()
{
  return siguiente;
}
void NodoCola::setSiguiente(NodoCola* siguiente_)
{
  this->siguiente = siguiente_;
}
