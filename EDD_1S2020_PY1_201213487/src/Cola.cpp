#include "Cola.h"

Cola::Cola()
{
    raiz = NULL;
    fondo = NULL;
}
NodoCola* Cola::getRaiz()
{
  return raiz;
}
void Cola::setRaiz(NodoCola* raiz_)
{
  raiz = raiz_;
}
NodoCola* Cola::getFondo()
{
  return fondo;
}
void Cola::setFondo(NodoCola* fondo_)
{
  fondo = fondo_;
}
bool Cola::verificarVacia()
{
    if (raiz == NULL)
        return true;
    else
        return false;
}
//MÉTODOS QUEUE Y DEQUE
void Cola::queue_(char letra_){
    int puntaje_ = obtenerPuntaje(toupper(letra_));
    NodoCola *nuevoNodoCola = new NodoCola(puntaje_,toupper(letra_));
    nuevoNodoCola->setSiguiente(NULL);
    if(verificarVacia()== true){
        raiz = nuevoNodoCola;
        fondo = nuevoNodoCola;
    }else{
        fondo->setSiguiente(nuevoNodoCola);
        fondo = nuevoNodoCola;
    }
}

int Cola::obtenerPuntaje(char letra_){
    switch (letra_)
    {
    case 'A':
        return 1;
        break;
    case 'E':
        return 1;
        break;
    case 'O':
        return 1;
        break;
    case 'I':
        return 1;
        break;
    case 'S':
        return 1;
        break;
    case 'N':
        return 1;
        break;
    case 'L':
        return 1;
        break;
    case 'R':
        return 1;
        break;
    case 'U':
        return 1;
        break;
    case 'T':
        return 1;
        break;
    case 'D':
        return 2;
        break;
    case 'G':
        return 2;
        break;
    case 'C':
        return 3;
        break;
    case 'B':
        return 3;
        break;
    case 'M':
        return 3;
        break;
    case 'P':
        return 3;
        break;
    case 'H':
        return 4;
        break;
    case 'F':
        return 4;
        break;
    case 'V':
        return 4;
        break;
    case 'Y':
        return 4;
        break;
    case 'Q':
        return 5;
        break;
    case 'J':
        return 8;
        break;
    /*case 'Ñ':
        return 8;
        break;*/
    case 'X':
        return 8;
        break;
    case 'Z':
        return 10;
        break;
    case 'W': //
        return 1;
        break;
    default:
        break;
    }
}
char Cola::deque_(){
    if(verificarVacia() == false){
        char valorNodoCola = raiz->getLetra();
        NodoCola *auxiliar = raiz;
        if (raiz == fondo){
            raiz = NULL;
            fondo = NULL;
        }
        else{
            raiz = raiz->getSiguiente();
        }
        delete auxiliar;
        return valorNodoCola;
    }
    else{
        return NULL;
    }
}

void Cola::mostrar(){
    NodoCola *c = raiz;
    printf("Cola \n");
    while(c != NULL){
        printf(" %c X %d\n", c->getLetra(),c->getPuntaje());
        c = c->siguiente;
    }
}

void Cola::graficar(){
    int correlativo = 0;
    FILE * archivo = fopen("Fichas.dot","w");
    fprintf(archivo,"digraph Grafo{ rankdir= LR \n");
    fprintf(archivo, "subgraph cluster4 {\n fontname=Arial label=\" Cola - Fichas\"; \n");
        if(this->getRaiz() != NULL){
            NodoCola * temp = this->getRaiz();
            while(temp != NULL){
                fprintf(archivo,"node [shape = box fillcolor=azure2 fontname=Arial style=filled label=\"%c X %d\" \ ]%d;\n",temp->getLetra(),temp->getPuntaje(),correlativo);
                temp = temp->getSiguiente();
                correlativo++;
            }

            temp = this->getRaiz();

            /*while(temp->getSiguiente()!=NULL){
                fprintf(archivo,"%d->%d;\n",temp->getCliente()+8000 ,temp->getSiguiente()->getCliente()+8000);
                 temp = temp->getSiguiente();
            }*/
        }else{
            fprintf(archivo," node [label=\"Cola vacía  \" \n   shape=underline]400000;");
        }

        fprintf(archivo,"}\n}");
        fclose(archivo);
        system("cd src/ " );
        system("dot -Tpng Fichas.dot -o Fichas.png \n xdg-open Fichas.png" );


}

void Cola::vaciarCola(){
    NodoCola* aux;
    while(this->getRaiz() != NULL){
        aux = this->getRaiz();
        this->setRaiz(aux->getSiguiente());
        delete [] aux;
    }
    this->setRaiz(NULL);
    this->setFondo(NULL);
}
