#pragma once
//klasa implementujaca kod DNA czyli dwa poloczone ze soba sekwencje nukleotydow
//o tej samej dlugosci
class DNA : public GeneSeq{
    friend std::ostream& operator<<(std::ostream& out, const DNA& ref);
    public:
        DNA(const GeneSeq& ref1, const GeneSeq& ref2): GeneSeq(ref1){
            chain2 = ref2.get_sequence();
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