#ifndef OBJETS_H  
#define OBJETS_H 



#include <iostream>
#include <cstdlib>
#include <string>
#include "Pos.hpp"

class Objets 
{
	public :
	Objets(){};
	Objets(Pos p) : position(p) {};
	Pos getPosition(){ return position;};
	void setPosition(Pos p){position = p;};
	virtual void afficher(std::ostream &flux) const =0;

	protected :
	Pos position;	
	
};


#endif