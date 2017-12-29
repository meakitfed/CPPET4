#ifndef VISIBLE_H   
#define VISIBLE_H 


#include "Objets.hpp"
#include "Segment.hpp"


class Visible : public Objets
{
	protected :
	RGB color;
	float reflexion;
	public :
	Visible() : Objets(){};
	Visible(Pos p, RGB c, float r): Objets(p), color(c), reflexion(r){};

	virtual void calculNormale(Intersection* inter) = 0;
	virtual Intersection* estTraverse(Segment s) = 0;
	virtual void afficher(std::ostream &flux) const;
};

void Visible::afficher(std::ostream &flux) const
{
	flux << "Objet Visible de position : " << position << " et de couleur : " << color;
}

std::ostream &operator<<(std::ostream &flux, Visible const& v)
{
    v.afficher(flux) ;
    return flux;
}

#endif