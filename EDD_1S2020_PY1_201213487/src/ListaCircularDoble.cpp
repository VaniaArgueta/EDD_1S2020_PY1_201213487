#include "ListaCircularDoble.h"

ListaCircularDoble::ListaCircularDoble()
{
    this->setPrimero(NULL);
    this->setUltimo(NULL);
    this->size = 0;
    this->correlativo = 0;
}

//Métodos get
NodoDoble * ListaCircularDoble::getPrimero(){
    return this->primero;
}
NodoDoble * ListaCircularDoble::getUltimo(){
    return this->ultimo;
}
int ListaCircularDoble::getSize(){
    return this->size;
}

//Métodos set
void ListaCircularDoble::setPrimero(NodoDoble * nuevo){
    this->primero = nuevo;
}
void ListaCircularDoble::setUltimo(NodoDoble *  nuevo){
    this->ultimo = nuevo;
}
void ListaCircularDoble::setSize(){
    this->size++;
}

//Otros métodos
NodoDoble * ListaCircularDoble::crearNodo(char* valor_, int correlativo_){
    NodoDoble* nuevo = new NodoDoble(valor_, correlativo_);
    nuevo->setSiguiente(NULL);
    nuevo->setAnterior(NULL);
    return nuevo;
}

void ListaCircularDoble::insertar(char* valor_){
    NodoDoble* nuevoNodo = crearNodo(valor_, this->correlativo);
    if(this->getPrimero() == NULL){
        this->setPrimero(nuevoNodo);
        this->setUltimo(nuevoNodo);
        nuevoNodo->setAnterior(nuevoNodo);
        nuevoNodo->setSiguiente(nuevoNodo);
    }else{
        NodoDoble *aux = this->getUltimo();
        nuevoNodo->setAnterior(aux);
        aux->setSiguiente(nuevoNodo);
        this->primero->anterior = nuevoNodo;
        nuevoNodo->setSiguiente(this->getPrimero());
        this->setUltimo(nuevoNodo);
    }
    correlativo++;
}

void ListaCircularDoble::mostrar(){

    NodoDoble* current = this->primero;
    do{
        //cout << current->getPalabra() << endl;
      printf("Palabra: [%s], Id: %d  \n", current->getPalabra(), current->id);
      current = current->getSiguiente();
    }while(current!= this->primero);
}

void ListaCircularDoble::graficar(){

    NodoDoble *pivote = getPrimero();
    FILE * archivo = fopen("Diccionario.dot","w");
    fprintf(archivo,"digraph Grafo{ rankdir= LR \n");
    fprintf(archivo, "subgraph cluster4 {\n fontname=Arial label=\" Lista Circular Doble - Diccionario\"; \n");
        if (pivote != NULL){
            NodoDoble* first = pivote;

            while(pivote->getSiguiente() != first){
                fprintf(archivo,"node [fillcolor=peachpuff2 fontname=Arial style=filled label=\"%s\" \ ] %d;\n" ,pivote->palabra,pivote->id);
                pivote = pivote->getSiguiente();
            }
            fprintf(archivo,"node [fillcolor=peachpuff2 fontname=Arial style=filled label=\"%s\" \ ] %d;\n" ,pivote->palabra,pivote->id);

                pivote = first;
            do{
                fprintf(archivo,"%d->%d;\n",pivote->id,pivote->getSiguiente()->id);
                fprintf(archivo,"%d->%d;\n",pivote->id,pivote->getAnterior()->id);
                pivote = pivote->getSiguiente();
            }while(pivote!= first);

        }else{
            fprintf(archivo," node [label=\"lista doble circular vacia  \" \n   shape=underline]400000;");
        }

        fprintf(archivo,"}\n}");
        fclose(archivo);
        system("cd src/ " );
        system("dot -Tpng Diccionario.dot -o Diccionario.png \n xdg-open Diccionario.png" );
}

NodoDoble * ListaCircularDoble::buscar(int id_buscar){
    if(this->getPrimero()!=NULL){
        NodoDoble * pivote = this->getPrimero();

    do{
        if(pivote->id == id_buscar){
            return pivote;
        }else{
            pivote = pivote->getSiguiente();
        }

    }while(pivote != this->getPrimero());
    }
    return NULL;
}

