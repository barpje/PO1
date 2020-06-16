#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <exception>
#include <memory>

//klasa przechowujaca nazwe uzytkownika
class User{
    public:
        User(const std::string& nam) : name(nam){
            std::cout<<"Creating User "<<name<<std::endl;
        }
        //getter zwraca nazwe uzytkownika
        std::string get_name()const{return name;}
        //metoda autoryzujaca, jesli autoryzacja niepoprawna to rzucamy wyjatek std::string
        void authorize(bool var){
            if(var)
                playing = var;
            else throw "Authorisation for User "+name+" was not granted.";
        }
        ~User(){
            std::cout<<"Deleting User "<<name<<std::endl;
        }
        
    private:
        std::string name;//nazwa uzytkownika
        bool playing = false;//flaga autoryzacji
};
//klasa przechowuje uzytkownikow w tablicy
class UserArray{
    public:
        UserArray(unsigned size) : tab{size, nullptr} {}
        //setter ustawia uzytkownika na zadanym indexie, jesli index zly to usuwa uzykownika i zwraca wyjatek
        void set(unsigned  i, User* ptr){
            if(i < tab.size() && i >=0){
                delete tab[i];
                tab[i] = ptr;
            }
            else {
                delete ptr;
                throw std::unique_ptr<UserArray>{this};
            }
        }
        //getter zwraca uzytkownika o zadanym indexie, jesli index zly zwraca wyjatek 
        User* get(unsigned l){
            if(l < tab.size() && l >= 0)
                return tab[l];
            else throw std::unique_ptr<UserArray>{this};
        }
        ~UserArray(){
            for(auto l: tab)
                delete l;
        }
    private:
        std::vector<User*> tab;//tablica uzytkownikow
};


