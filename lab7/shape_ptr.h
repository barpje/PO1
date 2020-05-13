#pragma once
#include "shape.h"
//klasa implementująca sprytny wskaźnik do obiektów Shape
class Shape_ptr{
    public:
        Shape_ptr() : _ptr(nullptr) {}
        Shape_ptr(Shape * ptr) : _ptr(ptr){}
        //zapobiegamy kopiowaniu
        Shape_ptr(const Shape_ptr& ref) = delete;
        Shape_ptr& operator=(const Shape_ptr& ref) = delete;
        Shape_ptr(Shape_ptr&& ref){
             std::swap(_ptr, ref._ptr);
        }
        Shape_ptr& operator=(Shape_ptr&& ref){
            if(this==&ref)
                return *this;
            else{
                delete _ptr;
                std::swap(_ptr,ref._ptr);
                return * this;
            }
        }
        Shape_ptr& operator=(Shape* &ptr){
            delete _ptr;//usuwamy aktualny wskaznik przed przypisaniem
            std::swap(_ptr, ptr);
            return *this;
        }
        Shape_ptr& operator=(Shape_ptr& ref){
            if(this == &ref)
                return *this;
            else{
                delete _ptr;//usuwamy aktualny wskaznik przed przypisaniem
                std::swap(_ptr,ref._ptr);
                return *this;
            }
        }
        //operator ->, zwraca wskaznik na Shape
        Shape* operator->(){
            return _ptr;
        }
        //operator *(dereferencji), zwraca referencje do Shape
        Shape& operator*(){
            return *_ptr;
        }
        //operator konwersji do bool, zwraca true gdy sprytny wskaznik nie jest pusty
        operator bool(){
            if (_ptr != nullptr)
                return true;
            else return false;
        }
        ~Shape_ptr(){
            if(_ptr!=nullptr)
                delete _ptr;
        }
    private:
        Shape * _ptr;
};


