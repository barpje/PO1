#pragma once
#include <string>
#include "utils.h"

//klasa implementująca łazik o zadanej nazwie, znajdujący się pod pewnymi współrzędnymi   
class Rover {
	friend class RoverIface;
    public:
        Rover():name(""){}
        Rover(std::string _name): name(_name){}
        //metoda do uzyskania wspolrzednych
        Coordinates get_coordinates() const {
		    return coordinates;
		}

	    /// metoda zwraca nazwe lazika 
	    std::string get_name() const {
		    return name;
		}

    	/// wykonuje pojedyńczą akcję daną bezargumentowym obiektem 
	    /// wykonywalnym o typie zwracanym void
	    void execute(const std::function< void() > action_) {
	    if(online)
		    action_();
		else std::cout<<"ERROR: Rover not linked to an interface."<<std::endl;
	    }

	    /// metoda drive wykonuje ciąg instrukcji zmieniających współrzędne.
	
	    void drive(const Program& _progr) {
	        if(online){
    	        for(unsigned i = 0; i < _progr.size();i++){
    	           coordinates.set_x( _progr[i]()[0]);
    	           coordinates.set_y( _progr[i]()[1]);
    	           std::cout<<"Arriving at "<<coordinates<<std::endl;
    	        }
	        }
	        else std::cout<<"ERROR: Rover not linked to an interface."<<std::endl;
	     }

    private:
        //flaga informująca czy łazik podłączony jest do interfejsu sterowania
        bool online = false;
        //nazwa lazika
        std::string name;
        //wspolrzedne lazika
        Coordinates coordinates;
};