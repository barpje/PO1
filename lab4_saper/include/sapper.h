#pragma once
#include "game.h"
#include "matrix.h"
//klasa symulujaca wlasciwa gre
class Sapper: public Game{
    public:
        Sapper() = default;
        virtual ~Sapper() = default;
        //metoda tworzy nowa plansz do gry
        void new_board(const Board&) override;
        //metoda do wypisywania planszy
        void print_board() override;
        //operator symulujacy ruch
        bool operator()(int,int) override;
    private:
        MyStuff::matrix  _board;
        int _moves;//liczba wszystkich mozliwych(dobrych) ruchow na planszy
};