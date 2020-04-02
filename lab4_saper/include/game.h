#pragma once
#include <string>
#include "board.h"
//abstrakcyjna klasa dostarczajaca interfejs do klasy Sapper
class Game{
    public:
        void new_player(std::string name){
            _userName = name;
        }
        virtual void new_board(const Board&) =0;
        virtual void print_board() =0;
        virtual bool operator()(int,int) =0;
        virtual ~Game() = default;
    private:
        std::string _userName;
};