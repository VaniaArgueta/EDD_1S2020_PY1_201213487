#include "ListaSimpleOrdenada.h"

ListaSimpleOrdenada::ListaSimpleOrdenada()
{
    primero = NULL;
    ultimo = NULL;
}
//Get y Set de primero y último
NodoSimple* ListaSimpleOrdenada::getPrimero()
{
  return primero;
}
NodoSimple* ListaSimpleOrdenada::getUltimo()
{
  return ultimo;
}
void ListaSimpleOrdenada::setPrimero(NodoSimple* primero_)
{
  primero = primero_;
}
void ListaSimpleOrdenada::setUltimo(NodoSimple* ultimo_)
{
  ultimo = ultimo_;
}

//Métodos
void ListaSimpleOrdenada::insertar(char* jugador_, int score_)
{
    NodoSimple* nuevo = new NodoSimple(jugador_, score_);
    if(this->getPrimero() == NULL){
        this->setPrimero(nuevo);
    }else{
        if(score_ > this->getPrimero()->getScore()){
            nuevo->setSiguiente(this->getPrimero());
            this->setPrimero(nuevo);
        }else{
            NodoSimple* aux = this->getPrimero();
            NodoSimple* previo = this->getPrimero();
            while(score_ <= aux->getScore() && aux->getSiguiente() != NULL){
                previo = aux;
                aux = previo->getSiguiente();
            }
            if(score_ <= aux->getScore()){
                aux->setSiguiente(nuevo);

            }else{
                nuevo->setSiguiente(aux);
                previo->setSiguiente(nuevo);
            }
        }
    }
    /*
    NodoSimple* nuevo = new NodoSimple(jugador_, score_);
    nuevo->setSiguiente(NULL);

    if(ListaSimpleOrdenada::getPrimero()==NULL){
        setPrimero(nuevo);
        setUltimo(nuevo);
    }else{
        NodoSimple* current = getPrimero();

        while(current->getSiguiente() != NULL){
        current = current->getSiguiente();
        }

        current->setSiguiente(nuevo);
        setUltimo(nuevo);
        current->getSiguiente()->setSiguiente(NULL);
    }*/
}
void ListaSimpleOrdenada::mostrar()
{

  NodoSimple* current = this->primero;
    while(current!= NULL){
      //printf("%d \n", current->getId());
      printf("Jugador: %s\nScore: %d\n\n", current->getJugador(), current->getScore());
      current = current->getSiguiente();
    }
}

void ListaSimpleOrdenada::graficarScoreboard(){

    int correlativo = 0;
    NodoSimple *nodo = this->primero;
    FILE *archivoS = fopen("scoreboard.dot", "w");
    fprintf(archivoS,"digraph Grafo{ rankdir= TB \n");
    fprintf(archivoS, "subgraph cluster2 {\n label=\" Lista Simple - Scoreboard\"; \n");
        if (nodo != NULL){
            NodoSimple * p = nodo;

            while(nodo != NULL)
            {;
                fprintf(archivoS,"node [label=\"Jugador: %s - %dpts \" \n  fillcolor=navajowhite3 \n style=filled \n shape=rect \n fontcolor=black  \ ] %d;\n",nodo->getJugador(),nodo->getScore(),correlativo); // correlativo 5000 para identificar el nodo en graphviz
                nodo = nodo->getSiguiente();
                correlativo++;
            }
            correlativo = 0;
            while (p->getSiguiente() != NULL)
            {
                int id_actual = correlativo;
                int id_siguiente = correlativo + 1;

                fprintf(archivoS,"%d->%d;\n",id_actual,id_siguiente);
                correlativo++;
                p = p->getSiguiente();
            }


        }else{
                fprintf(archivoS," node [label=\"lista Simple Vacia  \" \n  fillcolor=steelblue4 \n shape=egg \n fontcolor=white ]100000;");
        }

           fprintf(archivoS,"}}\n");
        fclose(archivoS);
        system("cd src/ " );
        system("dot -Tpng scoreboard.dot -o scoreboard.png \n xdg-open scoreboard.png" );
}

void ListaSimpleOrdenada::graficarScore(){
    int correlativo = 0;
    NodoSimple *nodo = this->primero;
    FILE *archivoS = fopen("score.dot", "w");
    fprintf(archivoS,"digraph Grafo{ rankdir= TB \n");
    fprintf(archivoS, "subgraph cluster2 {\n label=\" Lista Simple - Score de usuario\"; \n");
        if (nodo != NULL){
            NodoSimple * p = nodo;

            while(nodo != NULL)
            {;
                fprintf(archivoS,"node [label=\"%dpts \" \n  fillcolor=navajowhite3 \n style=filled \n shape=rect \n fontcolor=black  \ ] %d;\n",nodo->getScore(),correlativo); // correlativo 5000 para identificar el nodo en graphviz
                nodo = nodo->getSiguiente();
                correlativo++;
            }
            correlativo = 0;
            while (p->getSiguiente() != NULL)
            {
                int id_actual = correlativo;
                int id_siguiente = correlativo + 1;

                fprintf(archivoS,"%d->%d;\n",id_actual,id_siguiente);
                correlativo++;
                p = p->getSiguiente();
            }


        }else{
                fprintf(archivoS," node [label=\"lista Simple Vacia  \" \n  fillcolor=steelblue4 \n shape=egg \n fontcolor=white ]100000;");
        }

           fprintf(archivoS,"}}\n");
        fclose(archivoS);
        system("cd src/ " );
        system("dot -Tpng score.dot -o score.png \n xdg-open score.png" );
}
