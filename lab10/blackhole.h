#pragma once
#include <iostream>
#include <string>

const double G = 6.67*1e-11;//stała grawitacji Newtona
const double M = 2*1e30;//masa czarnej dziury w kg
const double c = 3*1e8;//prędkość światła
const double pc = 3.1*1e13;// parsec na km

//wlasny literal potrzebny w zadaniu dodatkowym
double operator "" _pc(long double x){
    return x*pc;
}

//klasa implementuje czarna dziure(przechowuje informacje o niej)
class BlackHole{
    friend std::ostream& operator<<(std::ostream& o, const BlackHole& hole);
    public:
        BlackHole(const std::string& n, double m, double r) : name(n), mass(m), distance(r){
            schwarzschild = (m/1e3*2*G*M)/(c*c);
        }
        //metoda zwraca nazwe czarnej dziury
        std::string get_name() const{return name;}
        //operator < porzadkujacy czarne dziury wg masy
        bool operator<(const BlackHole& ref)const {
            return mass < ref.mass;
        }
        //zwraca mase
        double get_mass()const { return mass;}
        //zwraca promien Schwarzwilda
        double get_Rh()const {return schwarzschild;}
    private:
        std::string name;//nazwa czarnej dziury
        double mass;//masa w masach slonca
        double schwarzschild;//promien Schwarzwilda
        double distance;//odległość czarnej dziury od Ziemi
};

std::ostream& operator<<(std::ostream& o, const BlackHole& hole){
    o<<hole.name<<" : M="<<hole.mass<<" solar mass, Rh="<<hole.schwarzschild<<" km, dist="<<hole.distance<<" pc"<<std::endl;
    return o;
}