#ifndef PIXEL_H
#define PIXEL_H

#include "RGB.hpp"
#include "Visible.hpp"
#include "Pos.hpp"

class Pixel 
{
	Pos position;
	RGB couleur;

	public :
	Pixel() {};
	Pixel(Pos p, RGB c) : position(p), couleur(c) {};
	RGB getColor(){return couleur;}
	void setColor(RGB c){couleur=c;}
	Pos getPosition(){return position;}
	void setPosition(Pos p){position=p;}
};

#endif