#ifndef SOURCE_H   
#define SOURCE_H 

#include "Visible.hpp"

class Source : Visible
{
	public :
	Source() : Visible() {};
	Source(Pos p, RGB c) : Visible(p,c,0) {};
	virtual void afficher(std::ostream &flux) const;	
};

void Source::afficher(std::ostream &flux) const
{
	flux << "Source de lumière de couleur : " << color << " et de position : " << position;
}
std::ostream &operator<<(std::ostream &flux, Source const& src)
{
    src.afficher(flux) ;
    return flux;
}

#endif