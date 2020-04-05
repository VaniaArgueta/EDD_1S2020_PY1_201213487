#ifndef NODOSIMPLE_H
#define NODOSIMPLE_H


class NodoSimple
{
    public:
        NodoSimple();
        NodoSimple(char* jugador_, int score_);
        NodoSimple* siguiente;
        NodoSimple* getSiguiente();
        void setSiguiente(NodoSimple* siguiente_);
        char* jugador;
        int score;
        char* getJugador();
        int getScore();
        void setJugador(char* jugador_);
        void setScore(int score_);



    protected:

    private:
};

#endif // NODOSIMPLE_H
