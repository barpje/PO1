#include "sapper.h"

void Sapper::new_board(const Board& board){       
    _board = MyStuff::matrix(board.get_geometry(1), board.get_geometry(2));
    _moves = _board.get_columns()*_board.get_rows()-board.get_params();
    //losujemy zadana ilosc bomb
    for(int i = 0; i < board.get_params(); i++){
    int x = std::rand() % _board.get_columns();
    int y = std::rand() % _board.get_rows();
    if (_board[y][x] != -200)
        _board[y][x] = -200;
    else --i;
    }
    //uzupelniamy pozostale pola
    for(int i = 0; i < _board.get_rows(); i++){
        for(int j = 0; j < _board.get_columns(); j++){
             if(_board[i][j] != -200)
                _board[i][j] = -100;
        }
    }
    //sprawdzamy sasiadow kazdego pola, jesli sasiadem jest bomba zwiekszamy pole o 1
    for(int i = 0; i < _board.get_columns(); i++)
        for(int j = 0; j < _board.get_rows(); j++)
            for(int ii = i - 1; ii <= i + 1; ii++)
                if((ii >= 0) && (ii < _board.get_columns()))
                    for(int jj = j - 1; jj <= j + 1; jj++)
                        if((jj >= 0) && (jj < _board.get_rows()) && _board[jj][ii]==-200)
                            if(_board[j][i]!=-200)
                                _board[j][i]++;
}

void Sapper::print_board(){
    for(int i = 0; i < _board.get_rows(); i++){
        for(int j = 0; j < _board.get_columns(); j++){
            if(_board[i][j] < 0)
                std::cout<<"* ";
            else
                std::cout<<_board[i][j]<<" ";
            }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}
bool Sapper::operator()(int x,int y){ 
    if(y >= _board.get_rows() || x >= _board.get_columns()){
        std::cout<<std::endl;
        std::cout<<"out of range..."<<std::endl;
        return true;
    }
    else if(_board[y][x] == -200){
        std::cout<<std::endl;
        std::cout<<"!!!   BOOOOM    !!!"<<std::endl;
        std::cout<<"    Game Over"<<std::endl;
        return false;  
    }
    //jesli to ostatni mozliwy ruch, to wygrywamy
    else if(_moves - 1 ==  0){
        std::cout<<std::endl;
        std::cout<<"Good job! You survived!"<<std::endl;
        return false;
    }
    //straznik aby nie odkryc dwa razy tego samego pola,
    //po odkryciu zmiejszamy ilosc mozliwych ruchow    
    else if(_board[y][x] < -25){
        _board[y][x]+=100;
        _moves-=1;
    }
                    
    return true;
}       