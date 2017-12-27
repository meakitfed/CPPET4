#ifndef POS_H
#define POS_H

#include <iostream>

class Pos 
{
	private :
	float x;
	float y;
	float z;

	public :
	Pos(){};
	Pos(float x1, float y1, float z1) : x(x1), y(y1), z(z1){};
	void afficher(std::ostream &flux) const;
};

void Pos::afficher(std::ostream &flux) const
{
    flux << "[x : " << x << " - y : " << y << " - z : " << z << "]";
}

std::ostream &operator<<(std::ostream &flux, Pos const& pos)
{
    pos.afficher(flux);
    return flux;
}


#endif