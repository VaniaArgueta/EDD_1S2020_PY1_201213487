#include "ListaDiccionario.h"

ListaDiccionario::ListaDiccionario()
{
    //ctor
    this->setPrimero(NULL);
    this->setUltimo(NULL);
    this->size = 0;
    this->correlativo = 0;
}

ListaDiccionario::~ListaDiccionario()
{
    //dtor
}

//Métodos get
NodoDiccionario * ListaDiccionario::getPrimero(){
    return this->primero;
}
NodoDiccionario * ListaDiccionario::getUltimo(){
    return this->ultimo;
}
int ListaDiccionario::getSize(){
    return this->size;
}

//Métodos set
void ListaDiccionario::setPrimero(NodoDiccionario * nuevo){
    this->primero = nuevo;
}
void ListaDiccionario::setUltimo(NodoDiccionario *  nuevo){
    this->ultimo = nuevo;
}
void ListaDiccionario::setSize(){
    this->size++;
}

//Otros métodos
NodoDiccionario * ListaDiccionario::crearNodo(std::string valor_, int correlativo_){
    NodoDiccionario* nuevo = new NodoDiccionario(valor_, correlativo_);
    nuevo->setSiguiente(NULL);
    nuevo->setAnterior(NULL);
    return nuevo;
}

void ListaDiccionario::insertar(std::string valor_){
    NodoDiccionario* nuevoNodo = crearNodo(valor_, this->correlativo);
    if(this->getPrimero() == NULL){
        this->setPrimero(nuevoNodo);
        this->setUltimo(nuevoNodo);
        nuevoNodo->setAnterior(nuevoNodo);
        nuevoNodo->setSiguiente(nuevoNodo);
    }else{
        NodoDiccionario *aux = this->getUltimo();
        nuevoNodo->setAnterior(aux);
        aux->setSiguiente(nuevoNodo);
        this->primero->anterior = nuevoNodo;
        nuevoNodo->setSiguiente(this->getPrimero());
        this->setUltimo(nuevoNodo);
    }
    correlativo++;
}

void ListaDiccionario::mostrar(){

    NodoDiccionario* current = this->primero;
    do{
        //cout << current->getPalabra() << endl;
      printf("Palabra: [%s], Id: %d  \n", current->getPalabra(), current->id);
      current = current->getSiguiente();
    }while(current!= this->primero);
}

void ListaDiccionario::graficar(){

    NodoDiccionario *pivote = getPrimero();
    FILE * archivo = fopen("Diccionario.dot","w");
    fprintf(archivo,"digraph Grafo{ rankdir= LR \n");
    fprintf(archivo, "subgraph cluster4 {\n fontname=Arial label=\" Lista Circular Doble - Diccionario\"; \n");
        if (pivote != NULL){
            NodoDiccionario* first = pivote;

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

NodoDiccionario * ListaDiccionario::buscar(int id_buscar){
    if(this->getPrimero()!=NULL){
        NodoDiccionario * pivote = this->getPrimero();

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
