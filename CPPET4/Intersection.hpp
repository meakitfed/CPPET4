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
	Intersection(Pos p1, Pos p2) : origine(p1)
	{
		normale = p1.segment(p2);
	}
};

#endif