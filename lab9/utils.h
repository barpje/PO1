#pragma once
#include <vector>
#include <functional>

double operator "" _km(long double x){
    return (x*360)/(2*3.14*3396.2);
}
typedef std::vector<std::function< std::vector<double>()>> Program;

//klasa implementująca współrzędne geograficzne na Marsie
class Coordinates{
    //operator - odejmuje wspolrzedne dwoch obiektow od siebie
    friend std::vector<double> operator-(const Coordinates& ref1, const  Coordinates& ref2);
    //operator wypisuje wspolrzedne w odpowiednim formacie
    friend std::ostream& operator<<(std::ostream& o, const Coordinates& ref);
    public:
        Coordinates(): _x(0), _y(0){}
        Coordinates(double x, double y): _x(x), _y(y){}
        Coordinates(const std::vector <double>& vec): _x(vec[0]), _y(vec[1]){}
        //operator += dodaje wartosc do wspolrzednych
        Coordinates& operator +=(double val){
            _x+=val;
            _y+=val;
            return *this;
        }
        //operator -= odejmuje wartosc od wspolrzednych
        Coordinates& operator -=(double val){
            _x-=val;
            _y-=val;
            return *this;
        }
        //metoda ustawia x
        void set_x(double val){
            _x += val;
        }
        //metoda ustawia y
        void set_y(double val){
            _y += val;
        }
        
    private:
        double _x;
        double _y;
};

std::ostream& operator<<(std::ostream& o, const Coordinates& ref){
    o<<"("<<ref._x<<","<<ref._y<<")";
    return o;
}
std::vector<double> operator-(const Coordinates& ref1,  const Coordinates& ref2){
            double x = ref1._x - ref2._x;
            double y = ref1._y - ref2._y;
            return std::vector<double> {x,y};
}
//przestrzen nazw wymagana w zadaniu
namespace MarsRoutes{
    //pierwsza droga na marsie, przesuwa lazik o zadane wektory
    Program route1(){
        return {
			[](){ return std::vector<double>{1,-1}; }, 
			[](){ return std::vector<double>{1,0}; },
			[](){ return std::vector<double>{1,-1}; },
            };
    }
    //program symulujacy powrot do bazy
    Program go_to(const Coordinates& ref1,const Coordinates& ref2){
        return {[ref1, &ref2](){ return (ref2-ref1); }};
    }
}
