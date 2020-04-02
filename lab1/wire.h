#pragma once

class QuantumWire{
friend QuantumWire operator*(const QuantumWire& ref, double x);
friend QuantumWire operator*(double x,const QuantumWire& ref);
friend std::ostream& operator<<(std::ostream& o, const QuantumWire& ref);
public:
    QuantumWire(){
        length = 0;
        ile = 0;
        tab = nullptr;
    }
    ~QuantumWire(){
        if(tab !=nullptr)
            delete [] tab;
    }
    QuantumWire(double l, int q){
        length = l;
        tab = new bool[q];
        ile = q;
        for(int i = 0; i<q;i++){
            tab[i] = std::rand()%2;
        }
    }
    QuantumWire(const QuantumWire& tmp){
        length = tmp.length;
        ile = tmp.ile;
        tab = new bool[ile];
        for(int i = 0; i<ile;i++)
            tab[i] = tmp.tab[i];
    }
    QuantumWire(QuantumWire&& tmp){
        ile = tmp.ile;
        length = tmp.length;
        tab = tmp.tab;
        tmp.tab = nullptr;
    }
    QuantumWire& operator=(const QuantumWire& tmp){
        if(this==&tmp)
            return *this;
        delete [] tab;
        length = tmp.length;
        ile = tmp.ile;
        tab = new bool[ile];
        for(int i = 0; i<ile;i++)
            tab[i] = tmp.tab[i];
        return *this;
    }
    QuantumWire& operator=(QuantumWire&& tmp){
        if(this==&tmp)
            return *this;
        delete [] tab;
        length = tmp.length;
        ile = tmp.ile;
        tab = tmp.tab;
        tmp.tab = nullptr;
        return *this;
    }
    QuantumWire& operator*=(double x){
        length*=x;
        return *this;
    }
    
    QuantumWire operator!(){
        QuantumWire tmp(*this);
        for(int i = 0;i<tmp.ile;i++){
            if(tmp.tab[i]==0)
                tmp.tab[i]=1;
            else tmp.tab[i] = 0;
        }
        return tmp;
    }
    bool operator[](int i){
        return this->tab[i];
    }
    operator int()const{
        return ile;
    }
    bool operator()(const QuantumWire& ref1, const QuantumWire& ref2){
        if(ref1.length>ref2.length)
            return true;
        else return false;
    }
private:
    double length;
    bool *tab; 
    int ile;
};
QuantumWire operator*(const QuantumWire& ref, double x){
        QuantumWire tmp(ref);
        tmp*=x;
        return tmp;
    }
    QuantumWire operator*(double x,const QuantumWire& ref){
        QuantumWire tmp(ref);
        tmp*=x;
        return tmp;
    }
 std::ostream& operator<<(std::ostream& o, const QuantumWire& ref){
     o<<"length: "<<ref.length<<", quanta: ";
     for(int i = 0; i<ref.ile;i++)
         o<<ref.tab[i]<<" ";
     return o;
 }