#pragma once
#include "board.h"
//klasa dostarczajaca informacje o planszy do gry
class SapperBoard: public Board{
    public:
        SapperBoard(int rows, int columns, int mines){
            if(columns > 4 && columns < 21)
                _columns = columns;
            else{
                _columns = 5;
                std::cout<<"Min columns size: 5, max columns size: 20!!!\n";
                std::cout<<"columns size set: 5"<<std::endl;
            }
            if(rows > 4 && rows < 21)
                _rows = rows;
            else{
                _rows = 5;
                std::cout<<"Min rows size: 5, max rows size: 20!!!\n";
                std::cout<<"rows size set: 5"<<std::endl;
            }
            if(mines > 1 || mines < rows*columns/3)
                _mines = mines;
            else{
                _mines = 2;
                std::cout<<"Min mines size: 2, max mines size: rows*columns/3!!!\n";
                std::cout<<"mines size set: 2"<<std::endl;
            }
        }
        //metoda zwraca liczbe wierszy lub kolumn planszy
        int get_geometry(int k) const override{
            switch(k){
                case 1: return _columns;
                case 2: return _rows;
            }
            return _mines;
        }
        //metoda zwraca domyslnie liczbe min na planszy, moze zwracac limit czasu do gry
        int get_params(int k = 0) const override{
            if(k==0)
                return _mines;
            else return _timeLimit;
        }
    private:
        int _rows;
        int _columns;
        int _mines;
        int _timeLimit = 1000;
};