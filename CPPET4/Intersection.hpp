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
		normale = p1.segment(p2);
	}
	Pos getOrigine(){return origine;}
};

#endif