#ifndef SPHERE_H   
#define SPHERE_H 


#include <iostream>
#include <cstdlib>
#include <string>

class Sphere : public Visible
{
	float rayon;
	public :
	Sphere() : Visible() {}
	Sphere(Pos p, RGB c, float r, float ray) : Visible(p,c,r), rayon(ray) {}
	void afficher(std::ostream &flux) const;
};

void Sphere::afficher(std::ostream &flux) const
{
	flux << "Objet Sphere de position : " << position << " de couleur : " << color << " de reflexion : " << reflexion << " et de rayon : " << rayon ;
}

std::ostream &operator<<(std::ostream &flux, Sphere const& s)
{
    s.afficher(flux) ;
    return flux;
}
#endif