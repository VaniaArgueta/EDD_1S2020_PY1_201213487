#include "NodoSimple.h"

NodoSimple::NodoSimple()
{
    //ctor
}
NodoSimple::NodoSimple(char* jugador_, int score_)
{
  this->jugador = jugador_;
  this->score = score_;
}
char* NodoSimple::getJugador(){
    return this->jugador;
}
int NodoSimple::getScore()
{
  return this->score;
}
void NodoSimple::setJugador(char* jugador_)
{
    this->jugador = jugador_;
}
void NodoSimple::setScore(int score_)
{
    this->score = score_;
}
NodoSimple* NodoSimple::getSiguiente()
{
  return siguiente;
}
void NodoSimple::setSiguiente(NodoSimple* siguiente_)
{
  siguiente = siguiente_;
}
