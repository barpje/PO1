#include <vector.h>

using namespace MyStuff;

namespace MyStuff{
    std::ostream& operator<<(std::ostream& o, const vector& ref){
        for(int i = 0; i < ref.sizev; i++)
            o<<ref.tab[i]<<" ";
        return o;
    }
    vector operator+(const vector& ref1, const vector& ref2){
        if(ref1.sizev > ref2.sizev){
            vector tmp(ref1);
            for(int i = 0;i<ref2.sizev;i++)
                tmp.tab[i] += ref2.tab[i];
            return tmp;
        }
        else{
            vector tmp(ref2);
            for(int i = 0; i < ref1.sizev;i++)
                tmp.tab[i] +=ref1.tab[i];
            return tmp;
        }
    }
}
vector::vector(int s): sizev(s){
    tab = new int[sizev];
    for(int i = 0; i < sizev; i++)
        tab[i] = 0;
}
vector::vector(const vector& tmp){
    sizev = tmp.sizev;
    tab = new int[sizev];    
    for(int i = 0; i < sizev; i++)
        tab[i] = tmp.tab[i];
}
 vector::vector(vector&& tmp){
    sizev = tmp.sizev;
    tab = tmp.tab;
    tmp.tab = nullptr;
    tmp.sizev = 0;
}
vector& vector::operator=(const vector& tmp){
    if(this==&tmp)
        return *this;
    else{            
            sizev = tmp.sizev;
            delete [] tab;
            tab  = new int[sizev];
            for(int i = 0; i < sizev; i++)
                tab[i] = tmp.tab[i];
            return *this;
        }
}
vector& vector::operator=(vector&& tmp){
    if(this==&tmp)
        return *this;
    else{         
            sizev = tmp.sizev;
            delete [] tab;
            tab  = tmp.tab;
            tmp.tab = nullptr;
            tmp.sizev = 0;
            return *this;
        }
}
void vector::push_back(int m){
    int *tmp = new int[sizev+1];
    if(sizev > 0){
        for(int i = 0; i < sizev; i++)
            tmp[i] = tab[i];
        delete [] tab;
        }   
    sizev = sizev +1;
    tmp[sizev-1] = m; 
    tab = tmp;
}
void vector::pop_back(int n){
    int *tmp = new int[sizev-n];
    for(int i = 0; i < sizev-n; i++)
        tmp[i] = tab[i];
    sizev = sizev - n;
    delete [] tab;
    tab= tmp;
}
