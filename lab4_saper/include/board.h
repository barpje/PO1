#pragma once
//abstrakcyjna klasa dostarczajaca interfejs do klasy sapper_board
class Board{
    public:
        virtual int get_geometry(int) const =0;
        virtual int get_params(int k = 0) const =0;
        virtual ~Board() = default;
};