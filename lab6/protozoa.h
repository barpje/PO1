#pragma once
#include "organism.h"
#include "gene_utils.h"

class Protozoa : public Organism{
    public:
        Protozoa(std::string name,const DNA& dna): Organism(name, dna){}
        Organism* reproduce() override{
            return new Protozoa(this->get_name(), mutation(this->get_dna()));
        }
        Organism* reproduce(Organism* tmp) override{
            if(this->get_name() == tmp->get_name()){
                DNA tmp1 =  DNA(this->get_dna()[0], tmp->get_dna()[1]);
                return new Protozoa(tmp->get_name(), mutation(tmp1));
            }
            return nullptr;
        }
        virtual ~Protozoa() = default;
};


