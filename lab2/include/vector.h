#pragma once
#include <iostream>

//deklaracja przestrzeni nazw wraz z deklaracja klasy wektor
namespace MyStuff{
    class vector;
}
//deklaracja operatora wypisania
std::ostream& operator<<(std::ostream&, const MyStuff::vector&);

namespace MyStuff{
//klasa wektor 
    class vector{
//deklaracja przyjazni z operatorem <<
    friend std::ostream& ::operator<<(std::ostream&, const vector&);
    public:
//konstruktor domyslny
        vector(): tab(nullptr), sizev(0){}
//konstruktor przyjmuje jako parametr rozmiar wektora i wypelnia go zerami
        vector(int);
//konstruktor kopiujacy
        vector(const vector&);
//operator przypisania kopiujacy
        vector& operator=(const vector&);
//destruktor zwalnia pamiec
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
//metoda usuwa ostatni element wektora i zmniejsza jego rozmiar o 1
        void pop_back();
                       
    private:
        int *tab;//tablica elementow
        int sizev;//rozmiar wektora
    };
}
  
