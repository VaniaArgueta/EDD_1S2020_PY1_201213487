#ifndef MENU_H
#define MENU_H
#include "ABB.h"
#include "Cola.h"
#include "ListaCircularDoble.h"
#include "ListaSimpleOrdenada.h"


class Menu
{
    public:
        Menu();
        void menuPrincipal();
        void menuReportes();
        void menuPrueba(Cola* fichas, ListaCircularDoble* diccionario, ABB* arbolin, ListaSimpleOrdenada* lista);

    protected:

    private:
};

#endif // MENU_H
