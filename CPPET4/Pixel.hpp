#ifndef PIXEL_H
#define PIXEL_H

#include "RGB.hpp"

class Pixel
{
	RGB couleur;
	public :
	Pixel(){};
	RGB getColor(){return couleur;}
	void setColor(RGB c){couleur=c;}
};

#endif