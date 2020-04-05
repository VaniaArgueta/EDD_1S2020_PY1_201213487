#include <iostream>
#include "ListaCircularDoble.h"
#include "Cola.h"
#include "ABB.h"
#include "Menu.h"
#include "ListaSimpleOrdenada.h"
#include "Matriz.h"
#include "ListaDiccionario.h"
#include "ListaDoble.h"
#include <stdlib.h>
#include <string>
#include <string.h>
#include <stdio.h>
#include<bits/stdc++.h>
#include "json.hpp"
#include <fstream>      // std::ifstream
#include <typeinfo>
#include <random>

using namespace std;
using json = nlohmann::json;

std::string stringToUpper(std::string &s)
{
    try{
        for(unsigned int l = 0; l < s.length(); l++)
          {
            s[l] = toupper(s[l]);
          }
    }catch(exception e){
      std::cout << "Error en stringToUpper "<< std::endl;
    }
  return s;
}

void cargarArchivo(std::string ruta, Matriz *tablero, ListaCircularDoble* diccionario){
    try{
        //tablero->insertar_matriz(35,7,new nodo_internoMatriz(35,7,2));
        //diccionario->insertar("holis");
        const char* palabra;
        char* otra;
        std::string palabra_auxiliar;
        std::string dx;
        std::string dy;
        std::string tx;
        std::string ty;
        int intDx, intDy, intTx, intTy;
        std::ifstream i(ruta);
        json j3;
        i >> j3;
        cout << "Dimension: " << j3.at("dimension") << endl;
        for(int casillas = 0; casillas < j3.at("casillas").at("dobles").size(); casillas++){
            intDx = j3.at("casillas").at("dobles")[casillas].at("x");
            intDy = j3.at("casillas").at("dobles")[casillas].at("y");
            tablero->insertar_matriz(intDx,intDy,new nodo_internoMatriz(intDx,intDy,2));
            intDy = j3.at("casillas").at("triples")[casillas].at("y");
            tablero->insertar_matriz(intDx,intDy,new nodo_internoMatriz(intDx,intDy,3));
        }
        for(int x = 0; x < j3.at("diccionario").size(); x++){

            palabra_auxiliar = j3.at("diccionario")[x].at("palabra");
            palabra_auxiliar = stringToUpper(palabra_auxiliar);
            char* otra = new char[palabra_auxiliar.size()+1];
            std::copy(palabra_auxiliar.begin(), palabra_auxiliar.end(), otra);
            otra[palabra_auxiliar.size()+1]= '\0';
            diccionario->insertar((char*)otra);
            //delete[] palabra;
        }
        diccionario->mostrar();
    }catch(exception e){
        std::cout << "Error en la carga masiva." << std::endl;
    }

}

void generarFichas(Cola* colaFichas){
    try{
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(1,26); // distribution in range [1, 6]
        std::cout << dist6(rng) << std::endl;

    }catch(exception e){
        std::cout << "Error en el random." << std::endl;
    }


}
int main()
{
    //Estructuras de datos
    ListaCircularDoble* diccionario = new ListaCircularDoble();
    Cola* fichas = new Cola();
    ABB * usuarios = new ABB();
    ListaSimpleOrdenada* lista = new ListaSimpleOrdenada();
    ListaSimpleOrdenada* scoreJugador = new ListaSimpleOrdenada();
    ListaSimpleOrdenada* scoreboard = new ListaSimpleOrdenada();
    ListaDoble *listaDobleFichas = new ListaDoble();

    Matriz * tablero = new Matriz();

   // tablero->insertar_matriz(5,2,new nodo_internoMatriz(5,2,2));
    ///tablero->insertar_matriz(1,2,new nodo_internoMatriz(1,2,2));
    //tablero->insertar_matriz(1,2,new nodo_internoMatriz(1,2,"B"));
    ///tablero->insertar_matriz(30,2,new nodo_internoMatriz(30,2,"A"));
    //tablero->insertar_matriz(5,2,new nodo_internoMatriz(5,2,"A"));

    //Variables para el menú
    std::string nombreJugador;
    std::string usuario;
    std::string ruta;

    int opcion, opcionABB;

    //Prueba datos quemados
        /*diccionario->insertar("Palabra1");
        diccionario->insertar("Palabra2");
        diccionario->insertar("Palabra3");
        diccionario->insertar("Palabra4");
        diccionario->insertar("Palabra5");
        diccionario->insertar("Palabra6");
        diccionario->insertar("Palabra7");
        diccionario->insertar("Palabra8");*/

        fichas->queue_('w');
        fichas->queue_('f');
        fichas->queue_('D');
        fichas->queue_('w');
        fichas->queue_('a');
        fichas->queue_('j');

        usuarios->insertarABB(usuarios->getRaiz() ,new NodoABB("Heidy"));
        usuarios->insertarABB(usuarios->getRaiz() ,new NodoABB("Carlos"));
        usuarios->insertarABB(usuarios->getRaiz() ,new NodoABB("Rodrigo"));
        usuarios->insertarABB(usuarios->getRaiz() ,new NodoABB("Eduardo"));
        usuarios->insertarABB(usuarios->getRaiz() ,new NodoABB("Antonio"));
        usuarios->insertarABB(usuarios->getRaiz() ,new NodoABB("Josue"));

        /*usuarios->insertar(35);
        usuarios->insertar(67);
        usuarios->insertar(43);
        usuarios->insertar(21);
        usuarios->insertar(10);
        usuarios->insertar(10000);
        usuarios->insertar(38);
        usuarios->insertar(69);*/

        lista->insertar("VAnia",10);
        lista->insertar("Ari",5);
        lista->insertar("Josue",80);
        lista->insertar("Ale",50);
        lista->insertar("Ricardo",50);
        lista->insertar("dd",5880);
        lista->insertar("sdjfskjdf",56);
        lista->insertar("sdfsadfs",10000);

        listaDobleFichas->insertar('A');
        listaDobleFichas->insertar('B');
        listaDobleFichas->insertar('C');
        listaDobleFichas->insertar('D');
        listaDobleFichas->insertar('E');
        listaDobleFichas->insertar('U');
        listaDobleFichas->insertar('P');


    cout <<"\n  |------------PROYECTO 1 EDD 2020--------------|";
    cout <<"\n  |-----------------201213487-------------------|"<<endl;


    do{
        cout <<"\n  |--------------------------------------------|";
        cout <<"\n  |---------------- SCCRABBLE -----------------|";
        cout <<"\n  |--------------------------------------------|";
        cout <<"\n  |--- 1. Cargar archivo                    ---|";
        cout <<"\n  |--- 2. Ingresar jugadores                ---|";
        cout <<"\n  |--- 3. Iniciar partida                   ---|";
        cout <<"\n  |--- 4. Reportes                          ---|";
        cout <<"\n  |--- 5. Salir                             ---|";
        cout <<"\n  |--------------------------------------------| \n";
        cin >> opcion;

        switch(opcion){
            case 1:
                //carga de archivos
                printf("\n  |-------- Ingresar ruta de archivo --------|\n");
                cin >> ruta;

                cargarArchivo(ruta, tablero, diccionario);

                break;

            case 2:
                cout <<"\n |------- JUGADORES ------|\n";
                cout <<"\n |--- Agregar Usuario  ---|";
                cout <<"\n Igresar nombre:\n";
                cin >> usuario;
                usuarios->insertarABB(usuarios->getRaiz() ,new NodoABB(usuario));


                break;
            case 3:
                //Iniciar partida
                generarFichas(fichas);
                break;

            case 4:
                int opcionReporte;
                cout <<"\n  |--------------------- REPORTES ------------------------|\n";
                cout <<"\n  |--- 1. Lista doble circular | Diccionario           ---|";
                cout <<"\n  |--- 2. Cola | Fichas                                ---|";
                cout <<"\n  |--- 3. ABB | Jugadores                              ---|";
                cout <<"\n  |--- 4. Lista simple ordenada | Historial jugador    ---|";
                cout <<"\n  |--- 5. Lista simple ordenada | Scoreboard           ---|";
                cout <<"\n  |--- 6. Matriz dispersa | Tablero de juego           ---|";
                cout <<"\n  |--- 7. Lista doble | Fichas por jugador             ---|";
                cout <<"\n  |--- 8. General jugador                              ---|\n ";
                cin >> opcionReporte;

                switch(opcionReporte){
                    case 1:
                        diccionario->graficar();
                        break;
                    case 2:
                        fichas->graficar();
                        break;
                    case 3:

                        cout <<"\n  |---------- GRAFICAR ABB ----------|\n";
                        cout <<"\n  |----------------------------------|";
                        cout <<"\n  |--- 1. Árbol                   ---|";
                        cout <<"\n  |--- 2. PreOrden                ---|";
                        cout <<"\n  |--- 3. InOrden                 ---|";
                        cout <<"\n  |--- 4. PostOrden               ---|";
                        cout <<"\n  |----------------------------------| \n";
                        cin >> opcionABB;

                        switch(opcionABB){
                            case 1:
                                usuarios->graficar_ABB();
                                break;

                            case 2:
                              usuarios->graficarPreOrden();
                                break;
                            case 3:
                                usuarios->graficarInOrden();
                                break;
                            case 4:
                                usuarios->graficarPostOrden();
                                break;
                            default:
                                cout <<"\n  ----->Ingrese una opción válida del 1 al 4 \n";
                                break;
                            }
                        break;
                    case 4:
                        cout<< " Ingrese nombre del jugador: \n" << endl;
                        cin>> nombreJugador;
                        /*if(arbol_capas->buscar_capa(aux_capa,arbol_capas->getRaiz())!=NULL){
                            arbol_capas->buscar_capa(aux_capa,arbol_capas->getRaiz())->matriz_capa->graficar_logico();
                        }else{
                            cout<< " \n la capa que ingreso no esta en el sistema \n"<<endl;
                        }*/
                        lista->graficarScore();
                        break;
                    case 5:
                        lista->graficarScoreboard();
                        break;
                    case 6:
                        //Matriz dispersa
                        tablero->graficar_logico();
                        break;
                    case 7:
                        //Lista doble
                        listaDobleFichas->graficaLista();
                        break;
                    case 8:
                        //General jugador
                        break;
                    default:
                        cout <<"\n  ----->> Ingrese una opción válida del 1 al 8.";
                    break;
                }

        }

    }while(opcion != 5);
    return 0;
}


