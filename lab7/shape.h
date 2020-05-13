#pragma once
#include<string>
#include <vector>
//abstrakcyjna klasa implementująca dowolny (zamknięty) kształt
class Shape{
    //operator<< wypisujacy nazwe ksztaltu
    friend std::ostream& operator<<(std::ostream& o, const Shape& ref){
        o<<ref._name;
        return o;
    }
    public:
        Shape(std::string name, std::vector <float> dane) : _name(name), _dane(dane){}
        //metoda oblicza pole powierchni
        virtual float area()const=0;
        //metoda oblicza obwod
        virtual float circumference()const=0;
        virtual ~Shape() = default;
    protected:
        std::string _name;//nazwa figury
        std::vector <float> _dane;//parametry figury
};
//klasa pochodna klasy Shape implementujaca koło
class Circle : public Shape{
    using Shape::Shape;
    public:
        float area() const override{
            return 3.14*_dane[0]*_dane[0];
        }
        float circumference() const override{
            return 2*3.14*_dane[0];
        }
};
//klasa pochodna klasy Shape implementujaca prostokąt
class Rectangle  : public Shape{
    using Shape::Shape;
    public:
        float area() const override{
            return _dane[0] * _dane[1];
        }
        float circumference() const override{
            return 2*_dane[0] + 2* _dane[1];
        }
};