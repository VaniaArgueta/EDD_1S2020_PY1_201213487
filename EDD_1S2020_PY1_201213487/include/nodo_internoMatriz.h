#ifndef NODO_INTERNOMATRIZ_H
#define NODO_INTERNOMATRIZ_H
#include <iostream>

class nodo_internoMatriz
{
    public:
    int x;
    int y;
    std::string Letra;
    int score;
    //punteros del nodo interno
    nodo_internoMatriz * izqueirda;
    nodo_internoMatriz * derecha;
    nodo_internoMatriz * arriba;
    nodo_internoMatriz * abajo;

        nodo_internoMatriz(int posX, int posY,std::string new_letra);
        nodo_internoMatriz(int posX, int posY,int score);

        //metodos get del nodo
        nodo_internoMatriz * getIzquierdo();
        nodo_internoMatriz * getDerecho();
        nodo_internoMatriz * getArriba();
        nodo_internoMatriz * getAbajo();
        int getX();
        int getY();
        std::string getLetra();
        //metodos set del nodo
        void setIzquierdo(nodo_internoMatriz * nuevo);
        void setDerecho(nodo_internoMatriz * nuevo);
        void setArriba(nodo_internoMatriz * nuevo);
        void setAbajo(nodo_internoMatriz * nuevo);
        void setX(int num);
        void setY(int num);

};

#endif // NODO_INTERNOMATRIZ_H
