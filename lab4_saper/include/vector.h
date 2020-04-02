#pragma once
#include <iostream>

namespace MyStuff{
    class vector{
    friend std::ostream& operator<<(std::ostream&, const vector&);
    friend vector operator+(const vector&, const vector&);
    public: 
        vector(): tab(nullptr), sizev(0){}
        //konstruktor przyjmuje jako parametr rozmiar wektora i wypelnia go zerami
        vector(int);
        vector(const vector&);
        vector(vector&&);
        vector& operator=(const vector&);
        vector& operator=(vector&&);
        ~vector(){
            if(tab != nullptr)
                delete [] tab;
        }
        //operator [] zwraca referencje do itego elementu tablicy
        int& operator[](int i){
            return tab[i];
        }
        //metoda zwraca rozmiar wektora
        int size()const{
            return sizev;
        }
        //metoda dodaje podana liczbe do konca wektora i zwieksza jego rozmiar o 1
        void push_back(int);
        //metoda usuwa ostatni element wektora i zmniejsza jego rozmiar o n elementow,
        //domyslnie o 1 element
        void pop_back(int n = 1);
                       
    private:
        int *tab;//tablica elementow
        int sizev;//rozmiar wektora
    };
}
  
