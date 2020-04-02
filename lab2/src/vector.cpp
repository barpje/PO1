#include <vector.h>
using namespace MyStuff;

std::ostream& operator<<(std::ostream& o, const vector& ref){
    for(int i = 0; i < ref.sizev; i++)
        o<<ref.tab[i]<<" ";
    return o;
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
void vector::push_back(int m){
    int *tmp = new int[sizev+1];
    for(int i = 0; i < sizev; i++)
        tmp[i] = tab[i];
    sizev = sizev +1;
    tmp[sizev-1] = m;
    delete [] tab;
    tab = tmp;
}
void vector::pop_back(){
    int *tmp = new int[sizev-1];
    for(int i = 0; i < sizev-1; i++)
        tmp[i] = tab[i];
    sizev = sizev - 1;
    delete [] tab;
    tab= tmp;
}
