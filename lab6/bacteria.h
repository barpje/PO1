#pragma once
#include "organism.h"
#include "gene_utils.h"

class Bacteria : public Organism{
    public:
        Bacteria(std::string name,const DNA& dna): Organism(name, dna){}
        Organism* reproduce() override{
            return new Bacteria(this->get_name(), mutation(this->get_dna()));
        }
        Organism* reproduce(Organism* tmp) override{
            return new Bacteria(tmp->get_name(), mutation(tmp->get_dna()));
        }
        virtual ~Bacteria() = default;
        
};


