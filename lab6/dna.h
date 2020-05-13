#pragma once
#include "gene_sequence.h"
//klasa implementujaca kod DNA czyli dwa poloczone ze soba sekwencje nukleotydow
//o tej samej dlugosci
class DNA : public GeneSeq{
    friend std::ostream& operator<<(std::ostream& out, const DNA& ref);
    public:
        DNA(const GeneSeq& ref1, const GeneSeq& ref2): GeneSeq(ref1){
            chain2 = ref2.get_sequence();
        }
        DNA(const std::vector< Nucleotide >& ref1, const std::vector< Nucleotide >& ref2) : GeneSeq(ref1){
            chain2 = ref2;
        }
        //operatro [] zwraca dolny lancuch gdy 0 gorny gdy 1
        std::vector< Nucleotide > operator[](int k)const{
            if(k==0)
                return chain;
            else 
                return chain2;
        }
        std::vector< Nucleotide >& operator[](int k){
            if(k==0)
                return chain;
            else 
                return chain2;
        }
         std::vector< Nucleotide >get_chain(int k)const{
            if(k==0)
                return chain;
            else 
                return chain2;
        }
        int get_size(int k){
            if(k==0)
                return chain.size();
            else 
                return chain2.size();
        }
    private:
        std::vector< Nucleotide > chain2;//wektor przechowujacy druga sekwencje nukleotydow
};

std::ostream& operator<<(std::ostream& out, const DNA& ref){
    out<<GeneSeq(ref);
    for(unsigned i = 0; i< ref.chain.size(); i++)
        out<<"| ";
    out<<std::endl;
    out<<GeneSeq(ref.chain2);
    return out;
}