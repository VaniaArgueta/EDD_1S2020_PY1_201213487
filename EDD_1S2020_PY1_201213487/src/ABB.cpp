#include "ABB.h"

ABB::ABB()
{
    this->raiz=NULL;
}

//metodo set
void ABB::setRaiz(NodoABB * nuevo){
    this->raiz = nuevo;
}
//metodos get
NodoABB * ABB::getRaiz(){
    return this->raiz;
}

// otros metodos
NodoABB * ABB::insertar_nuevo(NodoABB * raiz_actual, NodoABB * nuevo){
    NodoABB * padre = raiz_actual;

    if(raiz_actual->getNombreUsuario().compare(nuevo->getNombreUsuario()) > 0){
             if(raiz_actual->getIzquierdo() != NULL){
                 raiz_actual->setIzquierdo(insertar_nuevo(raiz_actual->getIzquierdo(), nuevo));
              }else{
                    raiz_actual->setIzquierdo(nuevo);
              }
           }else if(raiz_actual->getNombreUsuario().compare(nuevo->getNombreUsuario()) <0) {
                if(raiz_actual->getDerecho() !=NULL){
                    raiz_actual->setDerecho(insertar_nuevo(raiz_actual->getDerecho(),nuevo));
                }else{
                    raiz_actual->setDerecho(nuevo);
                }
           }else {
                std::cout << "-----------ya se inserto un USUARIO con el id-> "<< nuevo->getNombreUsuario() << std::endl;
         }
         return padre;
}
void ABB::insertarABB(NodoABB * raiz_actual, NodoABB * nuevo){
    if(this->raiz==NULL){
             this->setRaiz(nuevo);
    }else{
        this->raiz = insertar_nuevo(raiz_actual , nuevo);
    }
}


std::string ABB::PreOrden_ABB(NodoABB * raiz_acutual){ // raiz - izquierda - derecha
    if(this->getRaiz() == NULL){
        std::cout << "-------------ABB vacío----------------" << std::endl;
        return  NULL;
    }
    std::string retorno = "";
    if(raiz_acutual != NULL){

        retorno += (raiz_acutual->getNombreUsuario()) +", ";
        //listaPre->insertar(raiz_acutual->getNombreUsuario());
        retorno += PreOrden_ABB(raiz_acutual->getIzquierdo());
        retorno += PreOrden_ABB(raiz_acutual->getDerecho());
    }
    //listaPre->graficar();

    return retorno;
}
std::string ABB::InOrden_ABB(NodoABB * raiz_acutual){ //  izquierda -raiz- derecha
    if(this->getRaiz() == NULL){
        std::cout << "-------------el arbol esta vacio----------------" << std::endl;
        return  NULL;
    }
    std::string retorno = "";
    if(raiz_acutual != NULL){
        retorno += InOrden_ABB(raiz_acutual->getIzquierdo());
        retorno += (raiz_acutual->getNombreUsuario()) +", ";
        retorno += InOrden_ABB(raiz_acutual->getDerecho());
    }
    return retorno;
}

std::string ABB::PostOrden_ABB(NodoABB * raiz_acutual){
    if(this->getRaiz() == NULL){
        std::cout << "-------------el arbol esta vacio----------------" << std::endl;
        return  NULL;
    }
    std::string retorno = "";
    if(raiz_acutual != NULL){
        retorno += InOrden_ABB(raiz_acutual->getIzquierdo());
        retorno += InOrden_ABB(raiz_acutual->getDerecho());
        retorno += (raiz_acutual->getNombreUsuario()) +", ";
    }
    return retorno;
}

//************metodos para graficar
void ABB::graficar_ABB(){
    FILE * doc = fopen("ABB.dot","w");
    fprintf(doc,"digraph G{ rankdir = TB\n");
    fprintf(doc,"node [fillcolor=azure3 style=filled shape=oval fontname=\"Arial\"];\n");
    fprintf(doc, "subgraph cluster1 {\nlabel=\"ABB - Jugadores\"; \n");


    char  inte[10000];
    sprintf(inte,"%s",graficarRecorridoPreorden(this->getRaiz()).c_str());
    fprintf(doc,inte);

    char flechas[10000];
    sprintf(flechas,"%s",graficarRecorridoInOrden(this->getRaiz()).c_str());
    fprintf(doc,flechas);

    fprintf(doc,"}\n");
    fprintf(doc,"}\n");
    fclose(doc);
    system("cd src/" );
    system( "dot -Tpng ABB.dot -o ABB.png");
    system("cd src/" );
    system("xdg-open ABB.png");
}

std::string ABB::graficarRecorridoPreorden(NodoABB * raiz_actual){ //Pre: raiz-izquierdo-derecho
    std::string retorno="";
    if(raiz_actual!=NULL){
        retorno += "node[label =\" " +(raiz_actual->getNombreUsuario()) + " \"]" ;
        retorno +=  "ABB"+(raiz_actual->getNombreUsuario()) + ";\n" ;
        retorno += graficarRecorridoPreorden(raiz_actual->getIzquierdo());
        retorno += graficarRecorridoPreorden(raiz_actual->getDerecho());
    }
    return retorno;
}

std::string ABB::graficarRecorridoInOrden(NodoABB * raiz_actual){//Inorden: izquierdo-raiz-derecho
    std::string retorno="";
    if(raiz_actual!=NULL){
        if(raiz_actual->getIzquierdo()!=NULL){
            retorno +=  "ABB"+(raiz_actual->getNombreUsuario()) + "->"+"ABB"
                        +(raiz_actual->getIzquierdo()->getNombreUsuario())+";\n" ;
            retorno += graficarRecorridoInOrden(raiz_actual->getIzquierdo());
        }
        if(raiz_actual->getDerecho()!=NULL){
            retorno +=  "ABB"+(raiz_actual->getNombreUsuario()) + "->"+"ABB"
                        +(raiz_actual->getDerecho()->getNombreUsuario())+";\n" ;
            retorno += graficarRecorridoInOrden(raiz_actual->getDerecho());
        }
    }
    return retorno;
}

//Postorden: izquierdo-derecho-raiz


NodoABB * ABB::buscar(std::string dato, NodoABB * raiz_actual){
    if(raiz_actual != NULL){
        if(raiz_actual->getNombreUsuario().compare(dato) == 0){
            return raiz_actual;
        }else if(raiz_actual->getNombreUsuario().compare(dato) > 0){
            return buscar(dato, raiz_actual->getIzquierdo());
        }else{
            return buscar(dato, raiz_actual->getDerecho());
        }
    }
    return NULL;
}

void ABB::graficarPreOrden(){
    FILE * doc = fopen("preorden.dot","w");
    fprintf(doc,"digraph G{ rankdir = LR\n");
    fprintf(doc,"node [shape=box fontsize=12 fontname=\"Arial\"];\n");
    fprintf(doc, "subgraph cluster1 {\nlabel=\"Recorrido ABB - PreOrden\"; \n");


    char  inte[10000];
    sprintf(inte,"%s",graficarRecorridoPreorden2(this->getRaiz()).c_str());
    fprintf(doc,inte);
    /*char  flecha[10000];
    sprintf(flecha,"%s",preOrdenFlechas(this->getRaiz()).c_str());
    fprintf(doc,flecha);*/

    fprintf(doc,"\n}\n");
    fprintf(doc,"}\n");
    fclose(doc);
    system("cd src/" );
    system( "dot -Tpng preorden.dot -o preorden.png");
    system("cd src/" );
    system("xdg-open preorden.png");
}


void ABB::graficarInOrden(){
    FILE * doc = fopen("inorden.dot","w");
    fprintf(doc,"digraph G{ rankdir = LR\n");
    fprintf(doc,"node [shape=box fontsize=12 fontname=\"Arial\"];\n");
    fprintf(doc, "subgraph cluster1 {\nlabel=\"Recorrido ABB - InOrden\"; \n");


    char  inte[10000];
    sprintf(inte,"%s",graficarRecorridoInOrden2(this->getRaiz()).c_str());
    fprintf(doc,inte);
    /*char  flecha[10000];
    sprintf(flecha,"%s",graficarRecorridoInOrden(this->getRaiz()).c_str());
    fprintf(doc,flecha);*/

    fprintf(doc,"}\n");
    fprintf(doc,"}\n");
    fclose(doc);
    system("cd src/" );
    system( "dot -Tpng inorden.dot -o inorden.png");
    system("cd src/" );
    system("xdg-open inorden.png");
}

void ABB::graficarPostOrden(){
    FILE * doc = fopen("post.dot","w");
    fprintf(doc,"digraph G{ rankdir = LR\n");
    fprintf(doc,"node [shape=box fontsize=12 fontname=\"Arial\"];\n");
    fprintf(doc, "subgraph cluster1 {\nlabel=\"Recorrido ABB - PostOrden\"; \n");


    char  inte[10000];
    sprintf(inte,"%s",graficarRecorridoPostOrden2(this->getRaiz()).c_str());
    fprintf(doc,inte);
    /*char  flecha[10000];
    sprintf(flecha,"%s",graficarRecorridoInOrden(this->getRaiz()).c_str());
    fprintf(doc,flecha);*/

    fprintf(doc,"}\n");
    fprintf(doc,"}\n");
    fclose(doc);
    system("cd src/" );
    system( "dot -Tpng post.dot -o post.png");
    system("cd src/" );
    system("xdg-open post.png");
}

std::string ABB::graficarRecorridoPreorden2(NodoABB * raiz_actual){ //Pre: raiz-izquierdo-derecho
    std::string retorno="";
    if(raiz_actual!=NULL){
        retorno += "node[label =\" " +(raiz_actual->getNombreUsuario()) + " \"]" ;
        retorno +=  "ABB"+(raiz_actual->getNombreUsuario()) + ";\n" ;
        retorno += graficarRecorridoPreorden2(raiz_actual->getIzquierdo());
        retorno += graficarRecorridoPreorden2(raiz_actual->getDerecho());
    }
    return retorno;
}

std::string ABB::preOrdenFlechas(NodoABB * raiz_actual){ //Pre: raiz-izquierdo-derecho
    std::string retorno="";
    if(raiz_actual!=NULL){
        retorno += "\n ABB" +(raiz_actual->getNombreUsuario()) +"->";
        //retorno +=  "ABB"+(raiz_actual->getNombreUsuario()) + ";\n" ;
        retorno += preOrdenFlechas(raiz_actual->getIzquierdo())+";";
        retorno += preOrdenFlechas(raiz_actual->getDerecho())+";";
    }
    return retorno;
}

std::string ABB::graficarRecorridoInOrden2(NodoABB * raiz_actual){//Inorden: izquierdo-raiz-derecho
    std::string retorno="";

   /* retorno += InOrden_ABB(raiz_acutual->getIzquierdo());
        retorno += (raiz_acutual->getNombreUsuario()) +", ";
        retorno += InOrden_ABB(raiz_acutual->getDerecho());*/


    if(raiz_actual!=NULL){
        retorno += graficarRecorridoInOrden2(raiz_actual->getIzquierdo());
        retorno += "node[label =\" " +(raiz_actual->getNombreUsuario()) + " \"]" ;
        retorno +=  "ABB"+(raiz_actual->getNombreUsuario()) + ";\n" ;
        retorno += graficarRecorridoInOrden2(raiz_actual->getDerecho());
    }

    return retorno;
}

std::string ABB::graficarRecorridoPostOrden2(NodoABB * raiz_actual){
    std::string retorno="";
    std::string f="";

   /*retorno += InOrden_ABB(raiz_acutual->getIzquierdo());
        retorno += InOrden_ABB(raiz_acutual->getDerecho());
        retorno += (raiz_acutual->getNombreUsuario()) +", ";*/


    if(raiz_actual!=NULL){
        retorno += graficarRecorridoPostOrden2(raiz_actual->getIzquierdo());
        retorno += graficarRecorridoPostOrden2(raiz_actual->getDerecho());
        retorno += "node[label =\" " +(raiz_actual->getNombreUsuario()) + " \"]" ;
        retorno +=  "ABB"+(raiz_actual->getNombreUsuario()) + ";\n" ;
    }

    return retorno;
}
