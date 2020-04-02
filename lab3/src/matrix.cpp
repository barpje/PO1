#include <matrix.h>
using namespace MyStuff;

matrix::matrix():_rows(0), _columns(0), _matrix(nullptr){}
matrix::matrix(int columns, int rows):_rows(rows), _columns(columns){
    _matrix = new vector*[_rows];
    for(int i = 0; i<_rows;i++)
        _matrix[i] = new vector(_columns);
}
matrix::~matrix(){
    if(_matrix != nullptr){
        for(int i = 0; i < _rows; i++){
            if(_matrix[i]!=nullptr)
                delete _matrix[i];
        }
        delete [] _matrix;
    }
}
matrix::matrix(const matrix& tmp){
    _rows = tmp._rows;
    _columns = tmp._columns;
    _matrix = new vector*[_rows];
    for(int i = 0; i<_rows;i++)
        _matrix[i] = new vector(*tmp._matrix[i]);
}
matrix::matrix(matrix&& tmp){
    _rows = tmp._rows;
    _columns = tmp._columns;
    _matrix = tmp._matrix;
    tmp._rows = 0;
    tmp._columns = 0;
    tmp._matrix = nullptr;
}
matrix& matrix::operator=(const matrix& tmp){
    if(this==&tmp)
        return *this;
    else{
        for(int i = 0; i<_rows;i++)
            delete _matrix[i];
        delete [] _matrix;
        _rows = tmp._rows;
        _columns = tmp._columns;
        _matrix = new vector*[_rows];
        for(int i = 0; i<_rows;i++)
            _matrix[i] = new vector(*tmp._matrix[i]);
        return *this;
    }
}
matrix& matrix::operator=(matrix&& tmp){
    if(this==&tmp)
        return *this;
    else{
        for(int i = 0; i<_rows;i++)
            delete _matrix[i];
        delete [] _matrix;
        _rows = tmp._rows;
        _columns = tmp._columns;
        _matrix = tmp._matrix;
        tmp._rows = 0;
        tmp._columns = 0;
        tmp._matrix = nullptr;
        return *this;
    }
}
vector& matrix::operator[](int row){
    return *_matrix[row];
}

void matrix::fill(vector* tmp,int rows){
    if(_rows >=rows){
        for(int i = 0; i<rows;i++){
            for(int j = 0; j < _columns; j++)
                _matrix[i]->operator[](j) = tmp[i][j];
            }
    }
}
namespace MyStuff{
    std::ostream& operator<<(std::ostream& o, const matrix& ref){
        for(int i = 0;i<ref._rows;i++){
            o<<*(ref._matrix[i]);
             o<<std::endl;
        }
        o<<std::endl;
        return o;
    }
    matrix operator+(const matrix& tmp1, const matrix& tmp2){
        int rows = tmp1._rows > tmp2._rows ? tmp1._rows: tmp2._rows;
        int columns = tmp1._columns > tmp2._columns ? tmp1._columns: tmp2._columns;
        matrix tmp(columns, rows);
        //wybieramy wieksze wartosci wierszy oraz kolumnn i tworzymy nowy obiekt
        //nastepnie wypelniamy nowa macierz zadanymi elementami
        for(int i = 0; i < tmp1._rows;i++)
            *tmp._matrix[i] = *tmp._matrix[i] + *tmp1._matrix[i];
        for(int i = 0; i < tmp2._rows;i++)
            *tmp._matrix[i] = *tmp._matrix[i] + *tmp2._matrix[i];

        return tmp;
    }
    matrix operator*(const matrix& tmp1, const matrix& tmp2){
       matrix tmp( tmp2._columns, tmp1._rows);
       //mnozymy macierz zgodnie z regulami matematycznymi
       //jesli macierzy nie da sie pomnozyc lub da w odrwotnej kolenosci
       //wyswietlamy stosowna informacje
       if(tmp1._columns == tmp2._rows){
            for(int i = 0; i < tmp1._rows; i++){
                for(int j = 0; j < tmp2._columns; j++){
                    for(int k = 0; k < tmp1._columns; k++)
                        (tmp._matrix[i])->operator[](j)  += 
                        (tmp1._matrix[i])->operator[](k) * (tmp2._matrix[k])->operator[](j);    
                }
            } 
            return tmp;
        }
        else if(tmp1._rows== tmp2._columns)
            std::cout<<"Cannot multiply m1*m2 but m2*m1 is okay."<<std::endl;
        else std::cout<<"Wrong dimensions"<<std::endl;
        return tmp;
    }
}
