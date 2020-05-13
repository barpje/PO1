#pragma once
#include "human.h"
#include <functional>
#include <map>

//Klasa przechowuje załogę (o typie polimorficznym Human)
class Spacecraft{
    public:
        Spacecraft(const std::vector<Human*>& vec){
            for(auto k: vec){
                craft.insert({k->get_name(), k});
            }
        }
        //funkcja oblicza nowy czas, przymuje obiekt funkcyjny lub funkcje oraz czas w formacie human-readable
        void update_time(const std::function<format(const format&)> fun, const format& f){
            for(auto k: craft){
                k.second->update_time(fun(f));
            }
        }
        //operator [] zwraca staly obiekt Human o zadanym nazwisku
        Human operator[](const std::string& key)const{
            return *craft.at(key);
        }
    private:
        std::map<std::string, Human*> craft;
};