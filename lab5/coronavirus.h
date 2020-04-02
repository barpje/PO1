#pragma once
#include "virus.h"
#include <string>
//klasa implementuja koronawirusa, jako klase pochodna wirusa, posiada dodatkowo nazwe zweirzecia ktore go przenosi
class CoronaVirus : public Virus{
    public:
        CoronaVirus() : Virus() , animal(""){}
        CoronaVirus(std::string nam, std::string anim, const std::vector<Nucleotide>&ref) : Virus(nam){
            gen = new GeneSeq(ref);
            animal = anim;
        }
        CoronaVirus(CoronaVirus& ref) : Virus(ref) {
            animal = ref.animal;
        }
        CoronaVirus(CoronaVirus&&ref) : Virus(std::move(ref)) {
            animal = ref.animal;
            ref.animal = "";
        }
        CoronaVirus& operator=(const CoronaVirus& ref){
            if(this==&ref)
                return *this;
            else{
                this->Virus::operator=(ref);
                animal = ref.animal;
                return *this;
            }
        }
        CoronaVirus& operator=(CoronaVirus&& ref){
            if(this==&ref)
                return *this;
            else{
                this->Virus::operator=(std::move(ref));
                animal = ref.animal;
                ref.animal = "";
                return *this;
            }
        }
        //zwraca nazwe zwierzecia "nosiciela"
        std::string get_animal_host() const{
            return animal;
        }
    private:
        std::string animal;//nazwa zwierzecia "nosiciela"
};