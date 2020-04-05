#ifndef NODOLISTACIRCULARDOBLE_H
#define NODOLISTACIRCULARDOBLE_H
#include<iostream>

class NodoListaCircularDoble
{
    public:
        int id_imagen;
        nodo_listaImagen * siguiente;
        nodo_listaImagen * anterior;
        lista_capas * listaCapas;
        nodo_listaImagen(int id);

        //metodos get del nodo  lista de imagenes
        nodo_listaImagen * getSiguiente();
        nodo_listaImagen * getAnterior();
        lista_capas * getListaCapas();
        int getId_imagen();
        //metodos set del nodo Lista de imagenes
        void setSiguiente(nodo_listaImagen * nuevo);
        void setAnterior(nodo_listaImagen * nuevo);
        void setId_imagen(int id);

         void insertar_Capas(nodo_listaCapas * nueva_capa);
};

#endif // NODOLISTACIRCULARDOBLE_H
