#ifndef SEGMENT_H
#define SEGMENT_H

#include "Pos.hpp"
#include "Intersection.hpp"

class Segment
{
	Pos origine;
	Pos vecteur;
	public :
	Segment(Pos p1, Pos p2) : origine(p1)
	{
		vecteur = p1.segment(p2);
	}
	Segment prolongeSegment(Intersection i);
	bool croiseVisible(Visible v);
};


bool Segment::croiseVisible(Visible v)
{
	return true;
}
/*Segment Segment::prolongeSegment(Intersection i)
{
	//Todo pour les réflexions
}*/
#endif