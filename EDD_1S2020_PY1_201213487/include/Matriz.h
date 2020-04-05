#ifndef MATRIZ_H
#define MATRIZ_H
#include "nodo_cabecera.h"

class Lista_Cabeceras{
    public:
    nodo_cabecera * primero;
    nodo_cabecera * ultimo;
    int tam_lista;

    Lista_Cabeceras();
    void insertar_nodoCabecera(nodo_cabecera * nuevo);
    nodo_cabecera * buscar(int dato_buscar);
    void imprimir_cabeceras();
    //metodos get de las listas de cabecera
    nodo_cabecera * getPrimero_lisctaCabeceras();
    nodo_cabecera * getUltimo_listaCabeceras();
    int getSize();
    //metodos set de la lista de cabeceras
    void setPrimero(nodo_cabecera * nuevo);
    void setUltimo(nodo_cabecera * nuevo);
    void setSize(int size); // el tamaño sera la de 0 a la dimencion maxima que tenga el ultimo nodo de la cabecera
};

class Matriz
{
    public:
    Lista_Cabeceras * filas;
    Lista_Cabeceras * columnas;
    int num_capa;

        Matriz();
        void insertar_matriz(int pos_x , int pos_y,nodo_internoMatriz * nuevo);
        void graficar_logico();
        void generar_imagen();

};

#endif // MATRIZ_H
