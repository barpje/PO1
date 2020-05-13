#pragma once
#include <string>
#include "dna.h"

class Organism{
    public:
        Organism(std::string name,const DNA& ref){
            orgname = name;
            dna = new DNA(ref[0],ref[1]);
        }
        std::string get_name() const{
            return orgname;
        }
        DNA get_dna()const{
            return *dna;
        }
        virtual  Organism* reproduce()=0;
        virtual Organism* reproduce(Organism* )=0;
       
        Organism& operator<<(const Virus& ref){
            int k = std::rand() % 2;
            int gdzie = std::rand() % dna->get_size(k) ;
            int counter = 0;
            for(int i=gdzie;i < dna->get_size(k) && counter < ref.get_RNA()->get_sequence().size();i++){
                (*dna)[k][i] = (ref.get_RNA()->get_sequence())[counter];
                counter++;
            }
            int ile = ref.get_RNA()->get_sequence().size() - counter;
            for(int i=0;i<ile;i++){
                (*dna)[k][i] = (ref.get_RNA()->get_sequence())[counter];
                counter++;
            }         
            return *this;
            
        }
        virtual ~Organism(){
            delete dna;
        }
    protected:
        std::string orgname;
        DNA * dna;
};




