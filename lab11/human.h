#pragma once
#include <iostream>
#include <utility>
#include <tuple>
#include <string>

typedef std::tuple<int,int,int,int,int> format;
//stale okreslajace popularne jednostki czasu w sekundach
const int year = 365*24*3600;
const int day = 24 * 3600;
const int hour = 3600;
const int minute = 60;

//globalny operator<< Drukowanie czasu w formacie #y:#d:#h:#m:#s (gdzie znak # oznacza jakąś liczbę).
std::ostream& operator<<(std::ostream& o, const format& t){
    int yy, dd, hh, mm, ss;
    std::tie(yy, dd, hh, mm, ss) = t;
    o<<yy<<"y:"<<dd<<"d:"<<hh<<"h:"<<mm<<"m:"<<ss<<"s";
    return o;
}
//globalny operator + Dodawanie dwóch czasów.
format operator+(const format& t1, const format& t2){
    int yy1, dd1, hh1, mm1, ss1;
    int yy2, dd2, hh2, mm2, ss2;
    std::tie(yy1, dd1, hh1, mm1, ss1) = t1;
    std::tie(yy2, dd2, hh2, mm2, ss2) = t2;
    return std::make_tuple(yy1+yy2, dd1+dd2, hh1+hh2, mm1+mm2, ss1+ss2);
}
//Fcja globalna konwertująca czas human-readable na sekundy.
int to_sec(const format&t){
    int yy, dd, hh, mm, ss;
    std::tie(yy, dd, hh, mm, ss) = t;
    return yy*year + dd*day + hh*hour + mm*minute +ss;
}
//Fcja globalna konwertująca czas w sekundach na human-readable.
format from_sec(unsigned long long int sec){
    int yy, dd, hh, mm, ss;
    yy =  sec/year;
    sec %= year;
    dd = sec/day;
    sec %= day;
    hh = sec/hour;
    sec %= hour;
    mm = sec/minute;
    sec %=minute;
    ss =sec;
    return std::make_tuple(yy, dd, hh, mm, ss);
}
//Konwersja literału liczby oznaczającej lata do formatu human-readable.
format operator ""_yrs(unsigned long long int y){
    return std::make_tuple(y, 0, 0, 0, 0);
}
//Konwersja literału liczby oznaczającej sekundy do formatu human readable
format operator ""_sec(unsigned long long int s){
    return from_sec(s);
}
//Klasa przechowująca nazwisko oraz wiek człowieka
class Human{
    public:
        Human(const std::string& nam, const format& f): name(nam), age(f){}
        //getter zwraca wiek
        format get_age()const{ return age;}
        //getter zwraca nazwisko
        std::string get_name()const {return name;}
        //funkcja update_time, której argumentem jest czas human-readable o który należy zwiększyć wiek człowieka
        void update_time(const format& up){
            age = age + up;
        }
        //zwracamy liczbe klonow
        int get_clones()const{return clones;}
        //zwiekszamy liczbe klonow po klonowaniu
        void cloned(){clones+=1;}
    private:
        std::string name;//nazwisko
        format age;//wiek człowieka (w formacie human-readble)
        int clones = 1;//poniewaz liczbe klonow zwiekszamy po utworzeniu Clone, zakladamy 1 klon"do przodu"
};
//Klasa pochodna klasy Human, która służy do produkcji klonów.
class Clone : public Human{
    public:
        Clone(Human& h) : Human(h.get_name() + "_" + std::to_string(h.get_clones()), h.get_age()){
            h.cloned();  //tutaj "postarzamy" czlowieka
        }
};

