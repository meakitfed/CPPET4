#ifndef SPHERE_H   
#define SPHERE_H 


#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>

class Sphere : public Visible
{
	float rayon;
	public :
	Sphere() : Visible() {}
	Sphere(Pos p, RGB c, float r, float ray) : Visible(p,c,r), rayon(ray) {}
	void afficher(std::ostream &flux) const;
	virtual bool estTraverse(Segment s);
};


//retourne -1 si n'est pas traversé, sinon renvoie delta 
int Sphere::estTraverse(Segment s)
{
	int a = s.getVecteur().getX()*s.getVecteur().getX() + s.getVecteur().getY()*s.getVecteur().getY() +s.getVecteur().getZ()*s.getVecteur().getZ();
	int b = pow(s.getVecteur().getX()*s.getOrigine().getX()) + pow(s.getVecteur().getY()*s.getOrigine().getY()) + pow(s.getVecteur().getZ()*s.getOrigine.getZ())
	int c = pow(s.getOrigine().getX()) + pow(s.getOrigine().getY()) + pow(s.getOrigine.getZ()) - pow(rayon);

	int discri = pow(b) - 4*a*c;
	if(discri >= 0)
	{
		return discri;
	}
	else
	{
		return -1;
	}
	
}

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