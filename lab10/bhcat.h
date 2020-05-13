#pragma once
#include "blackhole.h"
#include <algorithm>
#include <map>
#include <initializer_list>
#include <functional>
//klasa implementuje katalog czarnych dziur
class BHCatalogue{
    public:
        //funkcja pomocnicza zwracaja kolejne klucze jako string
        std::string roman(){
            switch(holes.size()){
                case 0:
                    return "I.";
                case 1:
                    return "II.";
                case 2:
                    return "III.";
                case 3:
                    return "IV.";
                case 4:
                    return "V.";
            }
            return "";
        }
        //metoda dodajaca jedna dziure do mapy jesli jej rozmiar jest nie wiekszy niz 5
        void add(const BlackHole& hole){
            if(holes.size() < 5)
                holes.insert({roman(), hole});
            else std::cout<<">> Catalogue full. \""<<hole.get_name()<<"\" not added."<<std::endl; 
        }
        //metoda dodajaca czarne dziury do mapy jesli jej rozmiar jest nie wiekszy niz 5
        void add(std::initializer_list<BlackHole> hole){
            for(auto h : hole){
                if(holes.size() < 5)
                    holes.insert({roman(), h});
                else std::cout<<">> Catalogue full. \""<<h.get_name()<<"\" not added."<<std::endl;
            }
        }
        //zwraca BlackHole o kluczu n
        BlackHole get(const std::string& n)const{
            return holes.at(n);
        }
        //metoda zwraca mape <string, BlackHole>
        std::map<std::string, BlackHole> get_map() const {return holes;}
        //metoda zwraca std::vector<BlackHole> posortowany wg masy
        std::vector<BlackHole> get_ordered_by_mass()    {
            std::vector<BlackHole> vec;
            std::map <std::string, BlackHole> :: iterator it;
            for(it = holes.begin(); it != holes.end(); it++)
                vec.push_back(it->second);
            std::sort(vec.begin(), vec.end());
            return vec;
        }
        //metoda zwraca std::vector<BlackHole> spelniajacych okreslony warunek przeslany jako funkcja
        std::vector<BlackHole> get_custom(const std::function <bool(const BlackHole&)> fun){
            std::vector<BlackHole> vec;
            std::map <std::string, BlackHole> :: iterator it;
            for(it = holes.begin(); it != holes.end(); it++)
                if(fun(it->second))
                    vec.push_back(it->second);
            return vec;
        }
    private:
        std::map <std::string, BlackHole> holes;//mapa przechowujaca pary <string, BlackHole>
};