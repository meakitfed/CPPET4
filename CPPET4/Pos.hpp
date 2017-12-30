#ifndef POS_H
#define POS_H

#include <iostream>
#include <math.h>

class Pos 
{
	private :
	float x;
	float y;
	float z;

	public :


	Pos(){};
	Pos(float x1, float y1, float z1) : x(x1), y(y1), z(z1){};
	Pos segment(Pos p2);
	float getX(){return x;}
	float getY(){return y;}
	float getZ(){return z;}
	void setX(float x){this->x = x;}
	void setY(float y){this->y = y;}
	void setZ(float z){this->z = z;}
	float distanceAvecPoint(Pos p);
	void afficher(std::ostream &flux) const;
	float calculeCos(Pos vecteur2) const;
};

void Pos::afficher(std::ostream &flux) const
{
    flux << "[x : " << x << " - y : " << y << " - z : " << z << "]";
}

Pos Pos::segment(Pos p2)
{	
	Pos p(p2.getX()-x, p2.getY()-y, p2.getZ()-z);
	return p;
} 

float Pos::distanceAvecPoint(Pos p)
{
	return sqrt(pow((x-p.getX()),2) + pow((y-p.getY()),2) + pow((z-p.getZ()),2));
}


std::ostream &operator<<(std::ostream &flux, Pos const& pos)
{
    pos.afficher(flux);
    return flux;
}

float Pos::calculeCos(Pos vect2) const{
	float cosAlpha = this->x*vect2.x+this->y*vect2.y+this->z*vect2.z;
	float normthis = sqrt(pow(this->x,2)+pow(this->y,2)+pow(this->z,2));
	float normvect2 = sqrt(pow(vect2.x,2)+pow(vect2.y,2)+pow(vect2.z,2));
	cosAlpha = cosAlpha/(normthis*normvect2);
	return cosAlpha;
}

#endif