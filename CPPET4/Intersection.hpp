#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "Pos.hpp"
#include "RGB.hpp"


class Intersection
{

	Pos origine;
	Pos normale;
	RGB color;

	public :


	Intersection(){};
	Intersection(Pos p1, Pos p2, RGB c) : origine(p1), color(c)
	{
		normale = p2.segment(p1);
	}

	Pos getOrigine(){return origine;}
	Pos getNormale(){return normale;}
	RGB getColor(){return color;}
	void setOrigine(Pos origine){this->origine = origine;}
	void setNormale(Pos normale){this->normale = normale;}
	void setColor(RGB color){this->color = color;}
};

#endif