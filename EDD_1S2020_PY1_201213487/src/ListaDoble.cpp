#include "ListaDoble.h"

ListaDoble::ListaDoble()
{
    primero = NULL;
    ultimo = NULL;
}

//Get y Set de primero y último
NodoDoble* ListaDoble::getPrimero()
{
  return primero;
}
NodoDoble* ListaDoble::getUltimo()
{
  return ultimo;
}
void ListaDoble::setPrimero(NodoDoble* primero_)
{
  primero = primero_;
}
void ListaDoble::setUltimo(NodoDoble* ultimo_)
{
  ultimo = ultimo_;
}

//Métodos
void ListaDoble::insertar(char ficha_)
{
  NodoDoble* nuevo = new NodoDoble(ficha_);
  nuevo->setSiguiente(NULL);

  if(ListaDoble::getPrimero()==NULL){
    setPrimero(nuevo);
    setUltimo(nuevo);
  }else{
    NodoDoble* current = getPrimero();

    while(current->getSiguiente() != NULL){
      current = current->getSiguiente();
    }

    current->setSiguiente(nuevo);
    setUltimo(nuevo);
    nuevo->setAnterior(current);
    current->getSiguiente()->setSiguiente(NULL);
  }
}
void ListaDoble::mostrar(NodoDoble* primero)
{
  NodoDoble* current = primero;
    while(current!= NULL){
      printf("%d \n", current->ficha);
      printf("%c \n", current->ficha);
      current = current->getSiguiente();
    }
}

void ListaDoble::graficaLista(){

     int correlativo = 0;
    NodoDoble *nodo = this->primero;
    FILE *archivoS = fopen("ListaDobleFichas.dot", "w");
    fprintf(archivoS,"digraph Grafo{ rankdir= LR \n");
    fprintf(archivoS, "subgraph cluster2 {\n label=\" Lista Doble - Fichas Jugador \"; \n");
        if (nodo != NULL){
            NodoDoble * p = nodo;

            while(nodo != NULL)
            {;
                fprintf(archivoS,"node [label=\"%c\"fillcolor=azure3 style=filled  shape=rect fontcolor=black  \ ] %d;\n",nodo->ficha,correlativo);
                nodo = nodo->getSiguiente();
                correlativo++;
            }
            correlativo = 0;
            int id_actual = correlativo;
            int id_siguiente, id_anterior;
            while (p->getSiguiente() != NULL)
            {
                id_actual = correlativo;
                id_siguiente = correlativo + 1;
                id_anterior = correlativo -1;

                fprintf(archivoS,"%d->%d;\n",id_actual,id_siguiente);
                if(id_anterior != -1){
                    fprintf(archivoS,"%d->%d;\n",id_actual,id_anterior);
                }                
                correlativo++;
                p = p->getSiguiente();
            }
            fprintf(archivoS,"%d->%d;\n",id_actual+1,id_anterior+1);
            //fprintf(archivoS,"%d->%d;\n",id_actual,id_anterior);


        }else{
                fprintf(archivoS," node [label=\"lista Doble Vacia  \" \n  fillcolor=azure3 \n shape=egg \n fontcolor=white ]100000;");
        }

           fprintf(archivoS,"}}\n");
        fclose(archivoS);
        system("cd src/ " );
        system("dot -Tpng ListaDobleFichas.dot -o ListaDobleFichas.png \n xdg-open ListaDobleFichas.png" );

}
