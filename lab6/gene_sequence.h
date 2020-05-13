#pragma once

// *** Nie wolno modyfikować tego pliku ***

#include <vector>
#include <ostream>


//-------------------------------------------------------------
// Implementacja nukleotydów
enum Nucleotide { 
	A='A', // adeine 
	G='G', // guanine
	C='C', // citozine
	T='T', // thymine
	U='U'  // uracil
};


//-------------------------------------------------------------
// Implementacja sekwencji nukleotydów
// danych typem Nucleotide.
class GeneSeq {

	// operator drukujący sekwencję genów na wyjście ostream.
	friend std::ostream& operator<<( std::ostream& out, const GeneSeq& seq_);

 public:	

	// zwraca sekwencję genów (nukleotydów) w postaci wektora
	std::vector< Nucleotide > get_sequence() const { return chain; }
	
	//operator konwersji
    operator std::vector<Nucleotide>(){
        return chain;
    }
	GeneSeq( const std::vector< Nucleotide > seq_ ): chain(seq_) { }

 protected:

	// ciąg nukleotydów zaimplementowany jako wektor	
	std::vector< Nucleotide > chain;

};

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