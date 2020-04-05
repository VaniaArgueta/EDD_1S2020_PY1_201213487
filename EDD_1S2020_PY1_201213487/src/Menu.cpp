#include "Menu.h"

Menu::Menu()
{
    //ctor
}
void Menu::menuReportes(){

}

void Menu::menuPrueba(Cola* fichas, ListaCircularDoble* diccionario, ABB* arbolin, ListaSimpleOrdenada* lista){
    int p;
    cout << "1. Lista Doble Circular - Diccionario" << endl;
    cout << "2. Cola - Fichas" << endl;
    cout << "3. ABB - Usuarios" << endl;
    cout << "4. Lista simple ordenada - Historial por jugador" << endl;
    cout << "5. Lista simple ordenada - Scoreboard" << endl;
    cout << "6. Matriz dispersa - Tablero de juego" << endl;
    cout << "7. Lista Doble - Fichas por jugador" << endl;
    cout << "8. Volver a menú principal" << endl;
    cout << "9. Salir" << endl;
    cin>> p;

    if (p == 1){
        cout <<"LISTA DOBLE CIRCULAR - DICCIONARIO"<< endl;
        //ListaCircularDoble* diccionario = new ListaCircularDoble();
        diccionario->insertar("Palabra1");
        diccionario->insertar("Palabra2");
        diccionario->insertar("Palabra3");
        diccionario->insertar("Palabra4");
        diccionario->insertar("Palabra5");
        diccionario->insertar("Palabra6");
        diccionario->mostrar();
        diccionario->graficar();
        menuPrueba(fichas, diccionario, arbolin, lista);

    }else if(p == 2){
        cout <<"COLA - DICCIONARIO"<< endl;

        fichas->queue_('w');
        fichas->queue_('f');
        fichas->queue_('D');
        fichas->queue_('w');
        fichas->queue_('a');
        fichas->queue_('j');
        fichas->mostrar();
        fichas->graficar();;
        menuPrueba(fichas, diccionario, arbolin, lista);

    }else if(p == 3){
        cout <<"ABB - JUGADORES"<< endl;

            /*arbolin->insertar(20);
            arbolin->insertar(25);
            arbolin->insertar(15);
            arbolin->insertar(10);
            arbolin->insertar(30);
            arbolin->insertar(5);
            arbolin->insertar(35);
            arbolin->insertar(67);
            arbolin->insertar(43);
            arbolin->insertar(21);
            arbolin->insertar(10);
            arbolin->insertar(10000);
            arbolin->insertar(38);
            arbolin->insertar(69);*/
            /*cout << "InOrden" << endl;
            arbolin->inOrder(arbolin->getRaiz());
            cout << endl << "PreOrden" << endl;
            arbolin->preOrden(arbolin->getRaiz());
            cout << endl << "PostOrden" << endl;
            arbolin->postOrden(arbolin->getRaiz());
            arbolin->graficar(arbolin->getRaiz());*/
            menuPrueba(fichas, diccionario, arbolin, lista);

    }else if(p == 4){

            //menuPrueba();

    }else if(p == 5){

        lista->insertar("VAnia",10);
        lista->insertar("Ari",5);
        lista->insertar("Josue",80);
        lista->insertar("Ale",50);
        lista->insertar("Ricardo",50);
        lista->mostrar();
        lista->graficarScoreboard();
        lista->graficarScore();

        menuPrueba(fichas, diccionario, arbolin, lista);

    }else if(p == 6){
        menuPrincipal();

    }else if(p == 7){
        exit(0);

    }else if(p == 8){
        //menuPrueba();

    }else if(p == 9){
        //menuPrincipal();

    }else{
        cout << "Opción incorrecta. Ingresar número de 1 al 9."<< endl;
    }


}
void Menu::menuPrincipal(){
    int opcionMenu;
    cout << endl << "**SCRABBLE**"<< endl;
    cout << "Elija opción" << endl;
    cout << "1. Ingresar jugadores" << endl;
    cout << "2. Cargar archivo" << endl;
    cout << "3. Iniciar partida" << endl;
    cout << "4. Ver reportes" << endl;
    cout << "5. Otros reportes" << endl;
    cout << "6. Salir" << endl;
    cin >> opcionMenu;
    switch(opcionMenu)
    {
        case 1:
            //menuCargarArchivos();
        break;
        case 2:
            //menuGenerarImagenes();
        break;
        case 3:
            //menuABC();
        break;
        case 4:
            //menuPrueba();
        break;
        case 5:
            //menuOtrosReportes();
        break;
        case 6:
            exit(0);
        break;
        default:
            cout << "Opción incorrecta. Ingresar número de 1 al 5.";
    }

    cout << "" << endl<< endl;

}
