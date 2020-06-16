#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <type_traits>

//typ wyliczeniowy banknotow
enum Bill{
    Ten_PLN = 10,
    Hundred_PLN = 100, 
    Fifty_PLN = 50, 
    Twenty_PLN =20
};
//stala mapa umozliwiajaca mapowanie enum Bill --> std::string
const std::map<Bill, std::string> m {{Ten_PLN, "Ten"}, {Twenty_PLN, "Twenty"}, {Fifty_PLN, "Fifty"}, {Hundred_PLN, "Hundred"}};

//operator wypisania potrzebny do wypisania wektora obiektow typu Bill
std::ostream& operator<<(std::ostream& o, const std::vector<Bill>& bills){
    if(bills.size() == 0){
        o<<"No bills.";
        return o;
    }
    else{
        for(auto b : bills)
            o<<m.at(b)<<" ";
        return o;
    }
}


//Klasa pojemnika na wodę o zadanej maksymalnej pojemności.
class WaterContainer{
    public:
        WaterContainer(double size) : max_size(size), actual(0){}
        //metoda wypelniajaca kontener na zasadzie wszystko albo nic
        void put(double V){
            if(V <= max_size)
                actual = V;
            else throw std::string("Error: Container too small.");
            
        }
        //operator += dopelniajacy konterner1 i czyszczacy kontener2, jesli jest miejsce w kontenerze1
        WaterContainer& operator+=(WaterContainer& ref){
            if(ref.actual + actual <= max_size){
                actual += ref.actual;
                ref.clean();
                return *this;
            }
            else throw std::string("Error: Container too small.");
        }
        //getter zwraca zawartosc kontenera
        double get()const {return actual;}
        //metoda czysci kontener
        void clean(){ actual = 0;}
        //metoda zwraca maxymalny rozmiar kontenera
        double get_max()const{return max_size;}
    private:
        const double max_size;
        double actual;
};

//Klasa implementująca portfel o zadanej pojemności (maksymalnej liczbie banknotów)
class Wallet{
    public:
        Wallet(unsigned siz) : max_size(siz){}
        //metoda wypelniajaca kontener na zasadzie wszystko albo nic
        void put(const std::vector<Bill>& vals){
            if(vals.size() <= max_size)
                for(auto b : vals)
                    bills.push_back(b);
            else throw std::string("Error: Wallet too small.");
        }
        //operator += dopelniajacy konterner1 i czyszczacy kontener2, jesli jest miejsce w kontenerze1
        Wallet& operator+=(Wallet& ref){
            if(ref.bills.size() + bills.size() <= max_size){
                for(auto b : ref.bills)
                    bills.push_back(b);
                ref.clean();
                return *this;
            }
            else throw std::string("Error: Wallet too small.");
        }
        //getter zwraca zawartosc kontenera
        std::vector<Bill> get() const {return bills;}
        //metoda czysci kontener
        void clean(){ bills.clear(); }
        //metoda usuwa ostatni banknot z kontenera
        void pop_back(){bills.pop_back();}
        //metoda zwraca maxymalny rozmiar kontenera
        unsigned get_max()const{return max_size;}
    private:
        const unsigned max_size;
        std::vector<Bill> bills;
};

//szablon funkcji ktora zwraca wektor identycznych kopii podanego konetnera.
template <unsigned x, typename T>
std::vector<T> replicate_container(const T& ref){
    std::vector<T> tmps;
    T tmp(ref.get_max());
    tmp.put(ref.get());
    for(unsigned i = 0; i < x;i++)
        tmps.push_back(tmp);
    return tmps;
}
//szablon funkcji przekladajacej zawartosc kontenera2 do konterenera 1, na zasadzie wszystko albo nic
template <typename T>
void move_to_container(T& con1, T& con2){
    try {
		con1+=con2; }
	catch (const std::string& info) {
		std::cout << info << std::endl; }
}
//szablon funkcji porównujacej typ kontenerów przesłanych w argumencie obiektów
template <typename T1, typename T2>
void compare_container_type(const T1& ref, const T2& ref2){
    if (std::is_same<T1,T2>::value)
        std::cout<<"The containers are of same type."<<std::endl;
    else std::cout<<"The containers are of different type."<<std::endl;
}
