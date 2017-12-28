#ifndef SPHERE_H   
#define SPHERE_H 


#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>
#include "Intersection.hpp"

class Sphere : public Visible
{
	float rayon;
	public :
	Sphere() : Visible() {}
	Sphere(Pos p, RGB c, float r, float ray) : Visible(p,c,r), rayon(ray) {}
	virtual void afficher(std::ostream &flux) const;
	virtual Intersection* estTraverse(Segment s);
};



//retourne -1 si n'est pas traversé, sinon renvoie delta 
Intersection* Sphere::estTraverse(Segment s)
{

	int a = s.getVecteur().getX()*s.getVecteur().getX() + s.getVecteur().getY()*s.getVecteur().getY() +s.getVecteur().getZ()*s.getVecteur().getZ();
	int b = pow((s.getVecteur().getX()*s.getOrigine().getX()),2) + pow((s.getVecteur().getY()*s.getOrigine().getY()),2) + pow((s.getVecteur().getZ()*s.getOrigine().getZ()),2);
	int c = pow((s.getOrigine().getX()),2) + pow((s.getOrigine().getY()),2) + pow((s.getOrigine().getZ()),2) - pow(rayon,2);

	int discri = pow(b,2) - 4*a*c;
	if(discri > 0)
	{
		int t1 = (- b + sqrt(discri))/ (2*a);
		int t2 = (- b - sqrt(discri))/ (2*a);
		Pos p1(s.getVecteur().getX()*t1 + s.getOrigine().getX(), s.getVecteur().getY()*t1 + s.getOrigine().getY(),s.getVecteur().getZ()*t1 + s.getOrigine().getZ());
		Pos p2(s.getVecteur().getX()*t2 + s.getOrigine().getX(), s.getVecteur().getY()*t2 + s.getOrigine().getY(),s.getVecteur().getZ()*t2 + s.getOrigine().getZ());
		if(s.getOrigine().distanceAvecPoint(p1) < s.getOrigine().distanceAvecPoint(p2))
		{
			Intersection* i = new Intersection(p1,p2,color); //TODO chnager constructeur intersection(p2 a rien à faire ici)
			return i;
		}
		else
		{
			Intersection* i = new Intersection(p2,p1,color); //TODO chnager constructeur intersection(p2 a rien à faire ici)
			return i;
		}								 
	}
	else if(discri == 0)
	{
		return NULL;// rajouter ce cas
	}
	else
	{
		return NULL;
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