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
#include <time.h>
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


int cargarArchivo(std::string ruta, Matriz *tablero, ListaCircularDoble* diccionario){
    int dimension = 0;
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
        dimension = j3.at("dimension");
        //dimension = stoi(cadenaDimension);

        //cout << "Dimension: " <<  j3.at("dimension") << endl;
        cout << "---> Dimension del tablero: " <<  dimension << endl;
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
    return dimension;


}

int generarRandom(){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,26);
    return dist6(rng);
}

void generarFichas(Cola* fichas){
    fichas->vaciarCola();
    //95 fichas
    int cantidadA=12;
    int cantidadE=12;
    int cantidadO=9;
    int cantidadI=6;
    int cantidadS=6;
    int cantidadN=5;
    int cantidadL=4;
    int cantidadR=5;
    int cantidadU=5;
    int cantidadT=4;
    int cantidadD=5;
    int cantidadG=2;
    int cantidadC=4;
    int cantidadB=2;
    int cantidadM=2;
    int cantidadP=2;
    int cantidadH=2;
    int cantidadF=1;
    int cantidadV=1;
    int cantidadY=1;
    int cantidadQ=1;
    int cantidadJ=1;
    int cantidadX=1;
    int cantidadZ=1;
    int cantidadW=1;

    //Para A,E,O,I,S,N,L,R,U,T
    int puntaje1 = 1;
    //PARA D,G
    int puntaje2 = 2;
    //PARA C,B,M,P
    int puntaje = 3;
    //PARA H,F,V,Y
    int puntaje4 = 4;
    //PARA Q
    int puntaje5 = 5;
    //Para J,X
    int puntaje8 = 8;
    //PARA Z,W
    int puntaje10 = 10;


    bool aux = true;

    try{
        int i=1;
        int cantidad = 95;
        int random;
        while(cantidad > 0){
            random = generarRandom();
            //std::cout << i<< "=" << random << std::endl;
            //std::cout << random << std::endl;
            switch (random)
                {
                case 1: ///A
                    if(cantidadA>0){
                        fichas->queue_('A');
                        cantidadA--;
                        cantidad--;
                    }
                    break;
                case 2: ///E
                    if(cantidadE>0){
                        fichas->queue_('E');
                        cantidadE--;
                        cantidad--;
                    }
                    break;
                case 3:///O
                    if(cantidadO>0){
                        fichas->queue_('O');
                        cantidadO--;
                        cantidad--;
                    }
                    break;
                case 4:///I
                    if(cantidadI>0){
                        fichas->queue_('I');
                        cantidadI--;
                        cantidad--;
                    }
                    break;
                case 5:///S
                    if(cantidadS>0){
                        fichas->queue_('S');
                        cantidadS--;
                        cantidad--;
                    }
                    break;
                case 6:///N
                    if(cantidadN>0){
                        fichas->queue_('n');
                        cantidadN--;
                        cantidad--;
                    }
                    break;
                case 7:///L
                    if(cantidadL>0){
                        fichas->queue_('L');
                        cantidadL--;
                        cantidad--;
                    }
                    break;
                case 8:///R
                    if(cantidadR>0){
                        fichas->queue_('R');
                        cantidadR--;
                        cantidad--;
                    }
                    break;
                case 9:///U
                    if(cantidadU>0){
                        fichas->queue_('U');
                        cantidadU--;
                        cantidad--;
                    }
                    break;
                case 10:///T
                    if(cantidadT>0){
                        fichas->queue_('T');
                        cantidadT--;
                        cantidad--;
                    }
                    break;
                case 11:///D
                    if(cantidadD>0){
                        fichas->queue_('D');
                        cantidadD--;
                        cantidad--;
                    }
                    break;
                case 12:///G
                    if(cantidadG>0){
                        fichas->queue_('G');
                        cantidadG--;
                        cantidad--;
                    }
                    break;
                case 13:///C
                    if(cantidadC>0){
                        fichas->queue_('C');
                        cantidadC--;
                        cantidad--;
                    }
                    break;
                case 14:///B
                    if(cantidadB>0){
                        fichas->queue_('B');
                        cantidadB--;
                        cantidad--;
                    }
                    break;
                case 15:///M
                    if(cantidadM>0){
                        fichas->queue_('M');
                        cantidadM--;
                        cantidad--;
                    }
                    break;
                case 16:///P
                    if(cantidadP>0){
                        fichas->queue_('P');
                        cantidadP--;
                        cantidad--;
                    }
                    break;
                case 17:///H
                    if(cantidadH>0){
                        fichas->queue_('H');
                        cantidadH--;
                        cantidad--;
                    }
                    break;
                case 18:///F
                    if(cantidadF>0){
                        fichas->queue_('F');
                        cantidadF--;
                        cantidad--;
                    }
                    break;
                case 19:///V
                    if(cantidadV>0){
                        fichas->queue_('V');
                        cantidadV--;
                        cantidad--;
                    }
                    break;
                case 20:///Y
                    if(cantidadY>0){
                        fichas->queue_('Y');
                        cantidadY--;
                        cantidad--;
                    }
                    break;
                case 21:///Q
                    if(cantidadQ>0){
                        fichas->queue_('Q');
                        cantidadQ--;
                        cantidad--;
                    }
                    break;
                case 22:///J
                    if(cantidadJ>0){
                        fichas->queue_('J');
                        cantidadJ--;
                        cantidad--;
                    }
                    break;
                case 23:///X
                    if(cantidadX>0){
                        fichas->queue_('X');
                        cantidadX--;
                        cantidad--;
                    }
                    break;
                case 24:///Z
                    if(cantidadZ>0){
                        fichas->queue_('Z');
                        cantidadZ--;
                        cantidad--;
                    }
                    break;
                case 25: ///W
                    if(cantidadW>0){
                        fichas->queue_('W');
                        cantidadW--;
                        cantidad--;
                    }
                    break;
                default:
                    break;
                }
                //cantidad--;
        }

    }catch(exception e){
        std::cout << "Error en el random." << std::endl;
    }
}

void elegirJugador1(std::string jugador1, ABB* usuarios, Cola* fichas){
    //std::cout << "ENtró al método " << jugador1<< std::endl;
    try{

        if(usuarios->buscar(jugador1,usuarios->getRaiz())==NULL){

            std::cout << "El nodo es null" << std::endl;
        }else{
            //std::cout << "El nodo no es null " << usuarios->buscar(jugador1,usuarios->getRaiz())->getNombreUsuario() <<std::endl;
            if(usuarios->buscar(jugador1,usuarios->getRaiz())->lista_fichas != NULL){
                //std::cout << "lista_fichas no es null" << std::endl;
                for (int i=0;i<7;i++){
                    usuarios->buscar(jugador1,usuarios->getRaiz())->lista_fichas->insertar(toupper(fichas->deque_()));
                    //std::cout << "Char: " <<fichas->deque_() << std::endl;
                }
                usuarios->buscar(jugador1,usuarios->getRaiz())->lista_fichas->graficaLista();
            }else{
                std::cout << "lista_fichas es null" << std::endl;
            }
            //usuarios->buscar(jugador1,usuarios->getRaiz())->lista_fichas->mostrar();
        }
    }catch(exception e){
        std::cout << "Error en repartir fichas a jugador1." << std::endl;
    }
}

void elegirJugador2(std::string jugador2, ABB* usuarios, Cola* fichas){
    try{

        if(usuarios->buscar(jugador2,usuarios->getRaiz())==NULL){

            std::cout << "El nodo es null" << std::endl;
        }else{
            //std::cout << "El nodo no es null " << usuarios->buscar(jugador2,usuarios->getRaiz())->getNombreUsuario() <<std::endl;
            if(usuarios->buscar(jugador2,usuarios->getRaiz())->lista_fichas != NULL){
                //std::cout << "lista_fichas no es null" << std::endl;
                for (int i=0;i<7;i++){
                    usuarios->buscar(jugador2,usuarios->getRaiz())->lista_fichas->insertar(toupper(fichas->deque_()));
                    //std::cout << "Char: " <<fichas->deque_() << std::endl;
                }
                usuarios->buscar(jugador2,usuarios->getRaiz())->lista_fichas->graficaLista();
            }else{
                std::cout << "lista_fichas es null" << std::endl;
            }
            std::cout << "Llegó al final del método elegir jugador2" << std::endl;
        }
    }catch(exception e){
        std::cout << "Error en repartir fichas a jugador2." << std::endl;
    }

}

void ejecutarPartida(Cola* fichas, Matriz* tablero, ListaDoble* fichasJugador1, ListaDoble* fichasJugador2, std::string jugador1, std::string jugador2, int dimension){
    char letra;
    int terminarJuego = 1;///0 termina - 1 sigue
    int continuarTurno = 1; ///0 termina - 1 sigue
    bool primerJugador = true;
    int coordenadaX, coordenadaY;
    std::string letraString;
    cout <<"\n|-------- INICIA EL JUEGO --------| "<< jugador1 <<"--------|"<< endl;
    try{
        while(terminarJuego != 0){
            if(primerJugador == true){
                cout <<"\n|-------- Turno Jugador1: "<< jugador1 <<"--------|"<< endl;
                cout <<"Fichas disponibles: "<< endl;
                fichasJugador1->mostrar();
                printf("\n  |-------- Ingrese letra --------|\n");
                cin >> letra;
                printf("\n  |-------- Ingrese X --------|\n");
                cin >> coordenadaX;
                printf("\n  |-------- Ingrese Y --------|\n");
                cin >> coordenadaY;
                letraString = letra;
                if ((coordenadaX <= dimension) && (coordenadaY <= dimension)){
                    tablero->insertar_matriz(coordenadaX,coordenadaY,new nodo_internoMatriz(coordenadaX,coordenadaY,letraString));
                    fichasJugador1->eliminarNodo(toupper(letra));
                    tablero->graficar_logico();
                    fichasJugador1->graficaLista();
                }else{
                    printf("\n  ------->Las coordenadas exceden la dimension del tablero\n");
                }

                printf("\n  ------->¿Terminar el juego? [0/1]\n");
                cin >> terminarJuego;
                    if(terminarJuego == 0){
                        cout <<"|FIN DEL JUEGO"<< endl;
                        return;
                    }else{
                        printf("\n  ------->¿Continuar turno?[0/1]\n");
                        cin >> continuarTurno;
                        if(continuarTurno == 0){
                            primerJugador = false;
                            cout <<"Variable: " << continuarTurno<< endl;
                        }else {
                            primerJugador = true;
                            cout <<"Variable: " << continuarTurno<< endl;
                        }
                        tablero->graficar_logico();
                    }
            }else{
                cout <<"\n|-------- Turno Jugador2: "<< jugador2 <<"--------|"<< endl;
                cout <<"Fichas disponibles: "<< endl;
                fichasJugador2->mostrar();
                printf("\n  |-------- Ingrese letra --------|\n");
                cin >> letra;
                printf("\n  |-------- Ingrese X --------|\n");
                cin >> coordenadaX;
                printf("\n  |-------- Ingrese Y --------|\n");
                cin >> coordenadaY;
                letraString = letra;
                if ((coordenadaX <= dimension) && (coordenadaY <= dimension)){
                    tablero->insertar_matriz(coordenadaX,coordenadaY,new nodo_internoMatriz(coordenadaX,coordenadaY,letraString));
                    fichasJugador2->eliminarNodo(toupper(letra));
                    tablero->graficar_logico();
                    fichasJugador2->graficaLista();
                }else{
                    printf("\n  ------->Las coordenadas exceden la dimension del tablero\n");
                }

                printf("\n  ------->¿Terminar el juego? [0/1]\n");
                cin >> terminarJuego;
                    if(terminarJuego == 0){
                        cout <<"|FIN DEL JUEGO"<< endl;
                        return;
                    }else{
                        printf("\n  ------->¿Continuar turno?[0/1]\n");
                        cin >> continuarTurno;
                        if(continuarTurno == 0){
                            primerJugador = true;
                            cout <<"Variable: " << continuarTurno<< endl;
                        }else {
                            primerJugador = false;
                            cout <<"Variable: " << continuarTurno<< endl;
                        }
                        tablero->graficar_logico();
                    }
            }


        }
    }catch(exception e){
        cout <<"\n  -----> Error desconocido durante la partida."<< endl;
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
    std::string jugador1;
    std::string jugador2;
    std::string opcionJugador;
    int opcion, opcionABB;
    int dimension;

    try{
        //Prueba datos quemados

        lista->insertar("Heidy",10);
        lista->insertar("Carlos",5);
        lista->insertar("Rodrigo",80);
        lista->insertar("Eduardo",50);
        lista->insertar("Antonio",300);

        usuarios->insertarABB(usuarios->getRaiz() ,new NodoABB("Heidy"));
        usuarios->insertarABB(usuarios->getRaiz() ,new NodoABB("Carlos"));
        usuarios->insertarABB(usuarios->getRaiz() ,new NodoABB("Rodrigo"));
        usuarios->insertarABB(usuarios->getRaiz() ,new NodoABB("Eduardo"));
        usuarios->insertarABB(usuarios->getRaiz() ,new NodoABB("Antonio"));

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

                    dimension = cargarArchivo(ruta, tablero, diccionario);

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
                    fichas->vaciarCola();

                    generarFichas(fichas);
                    cout <<"\n |------- JUGADORES DISPONIBLES ------|\n";
                    cout <<usuarios->InOrden_ABB(usuarios->getRaiz()) << endl;


                    printf("\n  |-------- Elija jugador 1 --------|\n");
                    cin >> jugador1;
                    elegirJugador1(jugador1, usuarios, fichas);
                    printf("\n  |-------- Elija jugador 2 --------|\n");
                    cin >> jugador2;
                    elegirJugador1(jugador2, usuarios, fichas);

                    //Inicio de partida
                    //Las listas de fichas de los jugadores comienzan vacias
                    //usuarios->buscar(jugador1,usuarios->getRaiz())->lista_fichas->vaciarLista();
                    //usuarios->buscar(jugador2,usuarios->getRaiz())->lista_fichas->vaciarLista();

                    tablero->graficar_logico();
                    ejecutarPartida(fichas, tablero, usuarios->buscar(jugador1,usuarios->getRaiz())->lista_fichas, usuarios->buscar(jugador2,usuarios->getRaiz())->lista_fichas, jugador1, jugador2, dimension);

                    break;

                case 4:
                    try{
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

                                printf("\n  |-------- Jugador --------|\n");
                                cin >> opcionJugador;
                                usuarios->buscar(opcionJugador,usuarios->getRaiz())->lista_fichas->graficaLista();
                                break;
                            case 8:
                                //General jugador
                                break;
                            default:
                                cout <<"\n  ----->> Ingrese una opción válida del 1 al 8.";
                            break;
                        }
                    }catch(exception e){
                        cout <<"\n  ----->> Error. Ingrese una opción válida del 1 al 8."<<endl;
                    }
                    break;
                    case 5:
                        cout <<"\n  ----->> Saliendo..."<<endl;
                        cout <<"\n  ----->> Saliendo..."<<endl;
                        cout <<"\n  ----->> Saliendo..."<<endl;
                        break;
                    default:
                    cout <<"\n  ----->> Error en el menú. Ingrese una opción válida del 1 al 5."<<endl;
                    break;
            }

        }while(opcion != 5);
    }catch(exception e){
        cout <<"\n  ----->> Error en el menú. Ingrese una opción válida del 1 al 5."<<endl;
    }
    return 0;
}


