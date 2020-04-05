#ifndef ABB_H
#define ABB_H
#include "NodoABB.h"
#include <stdlib.h>
#include <string>
#include <string.h>
#include <stdio.h>
#include "ListaRecorrido.h"

class ABB
{
    public:
        NodoABB * raiz;
        ABB();

        //metodo set
        void setRaiz(NodoABB * nuevo);
        //metodos get
        NodoABB * getRaiz();

        // otros metodos
        std::string PreOrden_ABB(NodoABB * raiz_acutual);
        std::string InOrden_ABB(NodoABB * raiz_acutual);
        std::string PostOrden_ABB(NodoABB * raiz_acutual);

        void insertarABB(NodoABB * raiz_actual, NodoABB * nuevo);
        NodoABB * insertar_nuevo(NodoABB * raiz_actual, NodoABB * nuevo);

        NodoABB * buscar(std::string dato ,NodoABB * raiz_actual);

        //metodos para graficar
        void graficar_ABB();
        std::string graficarRecorridoPreorden(NodoABB * raiz_actual);
        std::string graficarRecorridoInOrden(NodoABB * raiz_actual);
        std::string graficarRecorridoPostOrden(NodoABB * raiz_actual);

        std::string graficarRecorridoPreorden2(NodoABB * raiz_actual);
        std::string graficarRecorridoInOrden2(NodoABB * raiz_actual);
        std::string graficarRecorridoPostOrden2(NodoABB * raiz_actual);

        std::string preOrdenFlechas(NodoABB * raiz_actual);
        std::string inOrdenFlechas(NodoABB * raiz_actual);
        std::string postOrdenFlechas(NodoABB * raiz_actual);

        void graficarPreOrden();
        void graficarInOrden();
        void graficarPostOrden();




};

#endif // ABB_H

