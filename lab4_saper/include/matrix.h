#pragma once
#include <vector.h>
namespace MyStuff{
    class matrix{
        friend std::ostream& operator<<(std::ostream&, const matrix&);
        friend matrix operator+(const matrix&, const matrix&);
        friend matrix operator*(const matrix&, const matrix&);
        public:
            matrix();
            ~matrix();
            //konstruktor tworzy macierz NxM, N-kolumny, M-wiersze
            matrix(int, int);
            matrix(const matrix&);
            matrix(matrix&&);
            int get_rows()const{
                return _rows;
            }
            int get_columns()const{
                return _columns;
            }
            //operator [] zwraca n-ty wiersz jako vector
            vector& operator[](int);
            matrix& operator=(const matrix&);
            matrix& operator=(matrix&&);
            //metoda wypelnia n rzedow macierzy, wartosciami z zadanych wektorow
            void fill(vector*,int);
        private:
            int _rows;
            int _columns;
            vector** _matrix;//macierz zlozona z obiektow klasy vector
    };
}
