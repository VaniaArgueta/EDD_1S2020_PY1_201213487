#include "nodo_internoMatriz.h"
nodo_internoMatriz::nodo_internoMatriz(int posX, int posY,std::string new_letra)
{
    this->x = posX;
    this->y = posY;
    this->Letra = new_letra;
    this->score = 1;
    this->izqueirda = NULL;
    this->derecha = NULL;
    this->abajo =NULL;
    this->arriba = NULL;
}


nodo_internoMatriz::nodo_internoMatriz(int posX, int posY,int score_)
{
    this->x = posX;
    this->y = posY;
    this->Letra = "";
    this->score = score_;
    this->izqueirda = NULL;
    this->derecha = NULL;
    this->abajo =NULL;
    this->arriba = NULL;
}


//metodos get del nodo
nodo_internoMatriz * nodo_internoMatriz::getIzquierdo(){
    return this->izqueirda;
}
nodo_internoMatriz * nodo_internoMatriz::getDerecho(){
    return this->derecha;
}
nodo_internoMatriz * nodo_internoMatriz::getArriba(){
    return this->arriba;
}
nodo_internoMatriz * nodo_internoMatriz::getAbajo(){
    return this->abajo;
}
int nodo_internoMatriz::getX(){
    return this->x;
}
int nodo_internoMatriz::getY(){
    return this->y;
}
std::string nodo_internoMatriz::getLetra(){
    return this->Letra;
}
        //metodos set del nodo
void nodo_internoMatriz::setIzquierdo(nodo_internoMatriz * nuevo){
    this->izqueirda = nuevo;
}
void nodo_internoMatriz::setDerecho(nodo_internoMatriz * nuevo){
    this->derecha = nuevo;
}
void nodo_internoMatriz::setArriba(nodo_internoMatriz * nuevo){
    this->arriba = nuevo;
}
void nodo_internoMatriz::setAbajo(nodo_internoMatriz * nuevo){
    this->abajo = nuevo;
}
void nodo_internoMatriz::setX(int num){
    this->x = num;
}
void nodo_internoMatriz::setY(int num){
    this->y = num;
}
