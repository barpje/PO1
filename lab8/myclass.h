#pragma once
#include "terrorist.h"
#include "weapon.h"

//klasa pochodna klasy Terrorist oraz Knife i Rifle symuluje terroryste niosacego noz i bron
class Terrorist1 : public Terrorist, public Knife, public Rifle {
    using Terrorist::Terrorist;
    using Knife::cut;
    using Rifle::shoot;
    public:
    	virtual void what() const override{
    	    Terrorist::print({Knife::name, Rifle::name});
    	}
    
    	virtual void attack() const override{
    	    cut();
    	    shoot();
    	}
    
};
//klasa pochodna klasy Terrorist oraz Axe i Bomb symuluje terroryste niosacego bombe oraz topor
class Terrorist2 : public Terrorist, public Axe, public Bomb {
    using Terrorist::Terrorist;
    using Axe::chop;
    using Bomb::explode;
    public:
        virtual void what() const override{
    	    print({Axe::name, Bomb::name});
    	}
    
    	virtual void attack() const override{
    	    chop();
    	    explode();
    	}
};
//klasa pochodna klasy Terrorist przechowuje wskaznik do terrorysty
class Safety : public Terrorist{
    public:
        Safety(Terrorist * wsk) : _terro(wsk){}
        Safety(std::unique_ptr<Terrorist>& wsk) : _terro(wsk.get()){}
        virtual void what() const override{
    	    _terro->what();
    	}
    
    	virtual void attack() const override{
    	    if(!attackblocked)
    	        _terro->attack();
    	}
    	//metoda uniemozliwia atak terrorysty
    	void apply_safety_measures(){
    	    attackblocked = true;
    	}
    private:
        bool attackblocked = false;//zmienna informujaca czy atak jest zablokowany
        Terrorist * _terro = nullptr;//wskaznik na terroryste
};

