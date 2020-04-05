#include "ListaRecorrido.h"

ListaRecorrido::ListaRecorrido()
{
    primero = NULL;
    ultimo = NULL;
}

void ListaRecorrido::insertar(std::string usuario_){
    NodoRecorrido* nuevo = new NodoRecorrido(usuario_);
    nuevo->siguiente =NULL;

    if(ListaRecorrido::primero ==NULL){
            this->primero = nuevo;
            this->ultimo = nuevo;
    }else{
        NodoRecorrido* current = primero;

        while(current->siguiente != NULL){
        current = current->siguiente;
        }

        current->siguiente =nuevo;
        ultimo = nuevo;
        current->siguiente->siguiente = NULL;
    }
}

void ListaRecorrido::graficar(){
    int correlativo = 0;
    NodoRecorrido *nodo = this->primero;
    FILE *archivoS = fopen("recorrido.dot", "w");
    fprintf(archivoS,"digraph Grafo{ rankdir= TB \n");
    fprintf(archivoS, "subgraph cluster2 {\n label=\" RECORRIDO\"; \n");
        if (nodo != NULL){
            NodoRecorrido * p = nodo;

            while(nodo != NULL)
            {;
                fprintf(archivoS,"node [label=\"%s\" \n  fillcolor=navajowhite3 \n style=filled \n shape=rect \n fontcolor=black  \ ] %d;\n",nodo->usuario,correlativo);
                nodo = nodo->siguiente;
                correlativo++;
            }
            correlativo = 0;
            while (p->siguiente != NULL)
            {
                int id_actual = correlativo;
                int id_siguiente = correlativo + 1;

                fprintf(archivoS,"%d->%d;\n",id_actual,id_siguiente);
                correlativo++;
                p = p->siguiente;
            }


        }else{
                fprintf(archivoS," node [label=\"Arbol vacio-No se muestra recorrido \" \n  fillcolor=steelblue4 \n shape=egg \n fontcolor=white ]100000;");
        }

           fprintf(archivoS,"}}\n");
        fclose(archivoS);
        system("cd src/ " );
        system("dot -Tpng recorrido.dot -o recorrido.png \n xdg-open recorrido.png" );
}

