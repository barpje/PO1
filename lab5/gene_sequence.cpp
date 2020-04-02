#include "gene_sequence.h"
//operator wypisania, konwertujacy sekwencje na litery
std::ostream& operator<<(std::ostream& out, const GeneSeq& seq_){
    if(seq_.chain.empty())
        out<<"0";
    else{
        for(unsigned i = 0; i< seq_.chain.size(); i++)
            out<<static_cast<char>(seq_.chain[i])<<" ";
    }
    out<<std::endl;
    return out;
}