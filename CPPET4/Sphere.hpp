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
	virtual void calculNormale ( Intersection* inter);
};



//retourne -1 si n'est pas traversé, sinon renvoie delta 
Intersection* Sphere::estTraverse(Segment s)
{

	
	int a = pow(s.getVecteur().getX(),2) + pow(s.getVecteur().getY(),2) +pow(s.getVecteur().getZ(),2);
	int b = (s.getVecteur().getX()*(s.getOrigine().getX()-position.getX()))*2 + ((s.getVecteur().getY()*(s.getOrigine().getY()-position.getY()))*2) + ((s.getVecteur().getZ()*(s.getOrigine().getZ()-position.getZ()))*2);
	int c = pow((s.getOrigine().getX()-position.getX()),2) + pow((s.getOrigine().getY()-position.getY()),2) + pow((s.getOrigine().getZ()-position.getZ()),2) - pow(rayon,2);
	
	int discri = pow(b,2) - 4*a*c;	
	
	if(discri > 0)
	{
		int t1 = (- b + sqrt(discri))/ (2*a);
		int t2 = (- b - sqrt(discri))/ (2*a);
		Pos p1(s.getVecteur().getX()*t1 + s.getOrigine().getX(), s.getVecteur().getY()*t1 + s.getOrigine().getY(),s.getVecteur().getZ()*t1 + s.getOrigine().getZ());
		Pos p2(s.getVecteur().getX()*t2 + s.getOrigine().getX(), s.getVecteur().getY()*t2 + s.getOrigine().getY(),s.getVecteur().getZ()*t2 + s.getOrigine().getZ());
		if(s.getOrigine().distanceAvecPoint(p1) < s.getOrigine().distanceAvecPoint(p2))
		{
			Intersection* i = new Intersection(p1,this->position,color);
			return i;
		}
		else
		{
			Intersection* i = new Intersection(p2,this->position,color);
			
			return i;
		}								 
	}
	else if(discri == 0)
	{
		int t = - b / (2*a);
		Pos p(s.getVecteur().getX()*t + s.getOrigine().getX(), s.getVecteur().getY()*t + s.getOrigine().getY(),s.getVecteur().getZ()*t + s.getOrigine().getZ());
		Intersection* i = new Intersection(p,this->position,color);

		return i;// rajouter ce cas
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

void Sphere::calculNormale(Intersection* inter){
	inter->setNormale(this->position.segment(inter->getOrigine()));
}



#endif