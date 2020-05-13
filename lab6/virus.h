#pragma once
#include <string>
#include "gene_sequence.h"
#include <vector>
//klasa implementujaca wirusa, jako sekwencje nukleotydow, nazwe oraz wiek
//wiek powieksza sie po kazdym skopiowaniu wirusa
class Virus{
    public:
        Virus() : name(""), age(0),gen(nullptr){}
        Virus(std::string nazwa): name(nazwa), age(0), gen(nullptr){}
        Virus(Virus& ref){
            age = 0;
            ref.age++;//starzeje sie
            name = ref.name;
            gen = new GeneSeq(ref.gen->get_sequence());
        }
        Virus(Virus&& ref){
            gen = ref.gen;
            age = ref.age;
            name = std::move(ref.name);
            ref.age=0;
            ref.gen = nullptr;
        }
        Virus& operator=(const Virus&ref){
            if(this==&ref)
                return *this;
            else{
                delete gen;
                age = ref.age;
                name = ref.name;
                gen = new GeneSeq(ref.gen->get_sequence());
            }
            return *this;
        }
        Virus& operator=(Virus&& ref){
            if(this==&ref)
                return *this;
            else{
                delete gen;
                gen = ref.gen;
                age = ref.age;
                name = std::move(ref.name);
                ref.age=0;
                ref.gen = nullptr;
                return* this;
            }
            
        }
        //zwraca nazwe wirusa
        std::string get_name()const {
            return name;
        }
       // zwraca sekwecje nukleotydow jako wskaznik
        GeneSeq* get_RNA()const{
            return gen;
        }
        
        //ustawia sekwencja nukleotydow
        void set_RNA(const std::vector<Nucleotide>&ref){
            gen = new GeneSeq(ref);
        }
        //zwraca wiek
        int get_age() const{
            return age;
        }
        ~Virus(){
            if(gen!=nullptr)
                delete gen;
        }
    protected:
        std::string name;//nazwa
        int age;//wiek
        GeneSeq* gen;//sekwecja nukleotydow wirusa
};